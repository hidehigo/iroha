/*
Copyright Soramitsu Co., Ltd. 2016 All Rights Reserved.

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

#ifndef __CORE_IZANAMI_SERVICE_HPP__
#define __CORE_IZANAMI_SERVICE_HPP__

#include <vector>
#include <string>
#include <memory>
#include <infra/protobuf/api.pb.h>

namespace izanami {
    using Api::TransactionResponse;


    class InitializeEvent {
    private:
        uint64_t now_progress;
        std::unordered_map <std::string, std::unique_ptr<TransactionResponse> > txResponses;
        std::unordered_map <uint64_t, std::vector<std::string>> hashes;
    public:

        void add_transactionResponse( std::unique_ptr<TransactionResponse> );
        const std::vector<std::string>& getHashes( uint64_t );
        const std::unique_ptr<TransactionResponse> getTransactionResponse( const std::string& );
        void next_progress();
        uint64_t now() const;

        void storeTxResponse( const std::string& );
        void executeTxResponse( const std::string& );

    };

    namespace detail {
        bool isFinishedReceiveAll(InitializeEvent &event);

        bool isFinishedReceive(const uint64_t &, InitializeEvent &);

        std::string getCorrectHash(const uint64_t &, InitializeEvent &);

        void storeTransactionResponse(const uint64_t &);
    }

    //invoke when receive TransactionResponse.
    void receiveTransactionResponse( std::unique_ptr<TransactionResponse> );

}


#endif