/*
Copyright 2020 The OneFlow Authors. All rights reserved.

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
#ifndef ONEFLOW_CORE_VM_TRANSPORTER_H_
#define ONEFLOW_CORE_VM_TRANSPORTER_H_

#include "oneflow/core/vm/transport_request.msg.h"

namespace oneflow {
namespace vm {

class Transporter {
 public:
  Transporter(const Transporter&) = delete;
  Transporter(Transporter&&) = delete;
  virtual ~Transporter() = default;

  virtual void MakeSendTransportRequest(
      const TransportDataToken& data_token, const char* data_ptr, size_t data_size,
      std::atomic<int64_t>* incomplete_cnt,
      TransportKey2SendRequest* transport_key2send_request) const = 0;

  virtual void MakeReceiveTransportRequest(
      const TransportDataToken& data_token, char* data_ptr, size_t data_size,
      std::atomic<int64_t>* incomplete_cnt,
      TransportKey2ReceiveRequest* transport_key2send_request) const = 0;

  virtual void Transport(TransportKey2SendRequest* transport_key2send_request) const = 0;
  virtual void Transport(TransportKey2ReceiveRequest* transport_key2receive_request) const = 0;

 protected:
  Transporter() = default;
};

}  // namespace vm

}  // namespace oneflow

#endif  // ONEFLOW_CORE_VM_TRANSPORTER_H_
