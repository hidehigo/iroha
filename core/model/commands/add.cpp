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
#include "add.hpp"

#include "../objects/account.hpp"
#include "../objects/asset.hpp"
#include "../objects/peer.hpp"

#include "../../util/logger.hpp"

#include "../../service/peer_service.hpp"
#include "../../infra/config/peer_service_with_json.hpp"


namespace command {

    template <>
    void Add<object::Account>::execution() {
        logger::debug("Add<Account>") << "save publicKey:" << object::Account::publicKey << " name:" << object::Account::name;
        //repository::account::add(object::Account::publicKey, object::Account::name);  // replace ametsuchi
    }

    template <>
    void Add<object::Asset>::execution() {

    }

    template<>
    void Add<object::Peer>::execution() {
        logger::debug("Add<Peer>") << "save ip:" << object::Peer::getIP() << " publicKey:" << object::Peer::getPublicKey();

        // 自身がリーダーノードの場合、Peerにデータを送る。
        if ( config::PeerServiceConfig::getInstance().isLeaderMyPeer() ) {

        }


        // save all Data and Consensus another peer
        // TODO

        // Valuation new peer trustScore
        // TODO

        // add peerList
        //double trustScore = 0.4; // calclation trust score
        config::PeerServiceConfig::getInstance().addPeer( object::Peer::getInstance() );

        // add local
        //repository::peer::add(object::Peer::ip, object::Peer::publicKey); // replace ametsuchi
    }
}