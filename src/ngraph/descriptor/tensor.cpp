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

#include "ngraph/descriptor/tensor.hpp"
#include "ngraph/descriptor/layout/tensor_view_layout.hpp"
#include "ngraph/node.hpp"

using namespace ngraph;
using namespace std;

descriptor::Tensor::Tensor(const element::Type& element_type,
                           const Shape& shape,
                           const std::string& name)
    : m_element_type(element_type)
    , m_shape(shape)
    , m_name(name)
{
}

void descriptor::Tensor::set_tensor_view_type(const element::Type& element_type, const Shape& shape)
{
    m_shape = shape;
    m_element_type = element_type;
    if (nullptr != m_tensor_view_layout)
    {
        m_tensor_view_layout->set_tensor_view_type(element_type, shape);
    }
}

void descriptor::Tensor::set_pool_offset(size_t offset)
{
    m_pool_offset = offset;
}

size_t descriptor::Tensor::get_pool_offset() const
{
    return m_pool_offset;
}

size_t descriptor::Tensor::size() const
{
    if (auto tvl = get_tensor_view_layout())
    {
        return tvl->get_allocated_size();
    }
    else
    {
        return shape_size(get_shape()) * m_element_type.size();
    }
}

ostream& operator<<(ostream& out, const descriptor::Tensor& tensor)
{
    out << "Tensor(" << tensor.get_name() << ")";
    return out;
}
