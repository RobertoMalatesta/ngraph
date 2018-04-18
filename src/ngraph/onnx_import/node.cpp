/*******************************************************************************
 * Copyright 2017-2018 Intel Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *******************************************************************************/

#include "node.hpp"
#include "graph.hpp"
#include "onnx.pb.h"

using namespace ngraph::onnx_import;

Node::Node(const onnx::NodeProto& node_proto, Graph* graph_ptr)
    : m_node_proto(node_proto)
    , m_graph_prt(graph_ptr)
{
}

std::ostream& ngraph::onnx_import::operator<<(std::ostream& os, const Node& wrapper)
{
    std::string name = wrapper.m_node_proto.name();
    std::string op_type = wrapper.m_node_proto.op_type();
    os << "<Node(" << op_type << "): " << name << ">";
    return os;
}