//*****************************************************************************
// Copyright 2017-2018 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//*****************************************************************************

#pragma once

#include <chrono>
#include <cstdint>

namespace mkldnn
{
    class primitive;
}

namespace ngraph
{
    namespace runtime
    {
        class AlignedBuffer;
    }
}

namespace ngraph
{
    namespace runtime
    {
        namespace ccpu
        {
            extern "C" {
            struct CCPURuntimeContext
            {
                bool* p_en;
                mkldnn::primitive* const* mkldnn_primitives;
                std::vector<AlignedBuffer*> memory_buffers;
                char* const* mkldnn_workspaces;
            };
            }
        }
    }
}
