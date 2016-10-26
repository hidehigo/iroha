/*
Copyright Soramitsu Co., Ltd. 2016 All Rights Reserved.
http://soramitsu.co.jp

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

         http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include "sumeragi.hpp"
#include <queue>
#include <map>
#include <tuple>
#include <thread>
#include <algorithm>
#include <cmath>

#include "../util/logger.hpp"
#include "../repository/consensus/merkle_transaction_repository.hpp"
#include "../repository/consensus/event_repository.hpp"
#include "../model/transactions/abstract_transaction.hpp"
#include "../crypto/hash.hpp"
#include "../crypto/signature.hpp"

#include "../validation/transaction_validator.hpp"
#include "../service/peer_service.hpp"
#include "./connection/connection.hpp"

template<class T>
std::unique_ptr<T> make_unique(){
  return std::unique_ptr<T>(new T());
}

/**
* |ーーー|　|ーーー|　|ーーー|　|ーーー|
* |　ス　|ー|　メ　|ー|　ラ　|ー|　ギ　|
* |ーーー|　|ーーー|　|ーーー|　|ーーー|
*
* A chain-based byzantine fault tolerant consensus algorithm, based in large part on BChain: 
*
* Duan, S., Meling, H., Peisert, S., & Zhang, H. (2014). Bchain: Byzantine replication with 
* high throughput and embedded reconfiguration. In International Conference on Principles of 
* Distributed Systems (pp. 91-106). Springer.
*/
namespace sumeragi {

    using ConsensusEvent = consensus_event::ConsensusEvent;

struct Context {
    bool isSumeragi; // am I the leader or not?
    unsigned long maxFaulty;  // f
    unsigned long proxyTailNdx;
    int panicCount;
    unsigned long numValidatingPeers;
    std::string myPublicKey;

    std::vector<
        std::unique_ptr<peer::Node>
    > validatingPeers;

    Context(std::vector<
        std::unique_ptr<peer::Node>
    > peers):
        validatingPeers(std::move(peers))
    {}

    std::vector<std::unique_ptr<ConsensusEvent>> processedCache;
};

std::unique_ptr<Context> context = nullptr;

void initializeSumeragi(const std::string& myPublicKey,
                        std::vector<std::unique_ptr<peer::Node>> peers) {

    logger::info("sumeragi", "initialize");

    context = std::make_unique<Context>(std::move(peers));
    peers.clear();

    context->numValidatingPeers = context->validatingPeers.size();
    context->maxFaulty = context->numValidatingPeers / 3;  // Default to approx. 1/3 of the network. TODO: make this configurable

    context->proxyTailNdx = context->maxFaulty*2 + 1;
    if (context->proxyTailNdx >= context->validatingPeers.size()) {
        context->proxyTailNdx = context->validatingPeers.size()-1;
    }

    context->panicCount = 0;
    context->myPublicKey = myPublicKey;

    //TODO: move the peer service and ordering code to another place
    determineConsensusOrder(); // side effect is to modify validatingPeers
    logger::info("sumeragi", "initialize.....  complete!");
}

unsigned long long getNextOrder() {
    return merkle_transaction_repository::getLeafCount() + 1;
}

void processTransaction(std::unique_ptr<ConsensusEvent> event) {
    if (!transaction_validator::isValid<abstract_transaction::AbstractTransaction>(*event->tx)) {
        return; //TODO-futurework: give bad trust rating to nodes that sent an invalid event
    }

    if (event->signatures.empty() && context->isSumeragi) {
        // Determine the order for processing this event
        event->order = getNextOrder();
    }

    event->addSignature(signature::sign(event->getHash(), peer::getMyPublicKey(), peer::getPrivateKey()));
    if (context->validatingPeers.at(context->proxyTailNdx)->getPublicKey() == peer::getMyPublicKey()) {
        connection::send(context->validatingPeers.at(context->proxyTailNdx)->getIP(), event->getHash()); // Think In Process
    } else {
        connection::sendAll(event->getHash()); // Think In Process
    }

    setAwkTimer(3000, [&](){
        if (!merkle_transaction_repository::leafExists(event->getHash())) {
            panic(event);
        }
    });

    context->processedCache.push_back(std::move(event));
}



/**
* 
* For example, given:
* if f := 1, then
*  _________________    _________________
* /        A        \  /        B        \
* |---|  |---|  |---|  |---|  |---|  |---|
* | 0 |--| 1 |--| 2 |--| 3 |--| 4 |--| 5 |
* |---|  |---|  |---|  |---|  |---|  |---|,
*
* if 2f+1 signature are not received within the timer's limit, then
* the set of considered validators, A, is expanded by f (e.g., by 1 in the example below):
*  ________________________    __________
* /           A            \  /    B     \ 
* |---|  |---|  |---|  |---|  |---|  |---|
* | 0 |--| 1 |--| 2 |--| 3 |--| 4 |--| 5 |
* |---|  |---|  |---|  |---|  |---|  |---|.
*/
void panic(const std::unique_ptr<ConsensusEvent>& event) {
    context->panicCount++; // TODO: reset this later
    unsigned long broadcastStart = 2 * context->maxFaulty + 1 + context->maxFaulty * context->panicCount;
    unsigned long broadcastEnd = broadcastStart + context->maxFaulty;

    // Do some bounds checking
    if (broadcastStart > context->numValidatingPeers - 1) {
        broadcastStart = context->numValidatingPeers - 1;
    }

    if (broadcastEnd > context->numValidatingPeers - 1) {
        broadcastEnd = context->numValidatingPeers - 1;
    }

    connection::sendAll(event->getHash()); //TODO: change this to only broadcast to peer range between broadcastStart and broadcastEnd  
}

void setAwkTimer(int const sleepMillisecs, std::function<void(void)> const action) {
    std::thread([action, sleepMillisecs]() {
        std::this_thread::sleep_for(std::chrono::milliseconds(sleepMillisecs));
        action();
    }).join();
}

/**
 * The consensus order is based primarily on the trust scores. If two trust scores
 * are the same, then the order (ascending) of the public keys for the servers are used.
 */
void determineConsensusOrder() {
    std::sort(context->validatingPeers.begin(), context->validatingPeers.end(), 
        [](const std::unique_ptr<peer::Node> &lhs,
           const std::unique_ptr<peer::Node> &rhs) {
            return lhs->getTrustScore() > rhs->getTrustScore()
                || (lhs->getTrustScore() == rhs->getTrustScore()
                    && lhs->getPublicKey() < rhs->getPublicKey());
        }
    );

    context->isSumeragi = context->validatingPeers.at(0)->getPublicKey() == context->myPublicKey;
}

void loop() {
    logger::info("sumeragi", "start main loop");

    while (true) {  // TODO: replace with callback linking the event repository?
        if(!repository::event::empty()) {

            // Determine node order
            determineConsensusOrder();

            logger::info("sumeragi", "event queue not empty");
            std::vector<std::unique_ptr<ConsensusEvent>> events = repository::event::findAll();
            // Sort the events to determine priority to process
            std::sort(events.begin(), events.end(), 
                [](const std::unique_ptr<ConsensusEvent> &lhs,
                   const std::unique_ptr<ConsensusEvent> &rhs) {
                    return lhs->signatures.size() > rhs->signatures.size()
                           || (context->isSumeragi && lhs->order == 0)
                           || lhs->order < rhs->order;
                }
            );

            for (auto&& event : events) {
                if (!transaction_validator::isValid(*event->tx)) {
                    continue;
                }

                // Process transaction
                processTransaction(std::move(event));
            }
        }

        // warning: processedCache should be ordered by order (ascending)
        for (auto&& event : context->processedCache) {

            // Check if we have at least 2f+1 signatures
            if (event->signatures.size() >= context->maxFaulty*2 + 1) {
                // Check Merkle roots to see if match for new state
                //TODO: std::vector<std::string>>const merkleSignatures = event.merkleRootSignatures;
                //TODO: try applying transaction locally and compute the merkle root
                //TODO: see if the merkle root matches or not

                // Commit locally
                merkle_transaction_repository::commit(event->getHash(), std::move(event->tx)); //TODO: add error handling in case not saved
            }
        }
    }
}

};  // namespace sumeragi
