// Copyright 2018 Baidu, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// 	http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef USKIT_POLICY_FLOW_POLICY_H
#define USKIT_POLICY_FLOW_POLICY_H

#include "config.pb.h"
#include "common.h"
#include "backend_engine.h"

namespace uskit {
namespace policy {
// Base class for flow policy.
class FlowPolicy {
public:
    FlowPolicy() {}
    virtual ~FlowPolicy() {}

    virtual int init(const google::protobuf::RepeatedPtrField<FlowNodeConfig> &config) { return 0; }
    virtual int run(USRequest& request, USResponse& response,
                    const BackendEngine* backend_engine,
                    const RankEngine* rank_engine) const = 0;
};
} // namespace policy
} // namespace uskit

#endif // USKIT_POLICY_FLOW_POLICY_H
