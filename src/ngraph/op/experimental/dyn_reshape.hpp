//*****************************************************************************
// Copyright 2017-2019 Intel Corporation
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

#include "ngraph/axis_vector.hpp"
#include "ngraph/node_vector.hpp"
#include "ngraph/op/op.hpp"
#include "ngraph/shape_util.hpp"

namespace ngraph
{
    namespace op
    {
        /// \brief Dynamic tensor reshape operation.
        class DynReshape : public Op
        {
        public:
            /// \brief Constructs a dynamic reshape operation.
            ///
            /// \param arg The tensor to be reshaped.
            /// \param output_shape A tensor representing the desired output shape; must be a vector of element type u64.
            DynReshape(const std::shared_ptr<Node>& arg, const std::shared_ptr<Node>& output_shape);

            void validate_and_infer_types() override;

            virtual std::shared_ptr<Node>
                copy_with_new_args(const NodeVector& new_args) const override;

        protected:
            virtual void generate_adjoints(autodiff::Adjoints& adjoints,
                                           const NodeVector& deltas) override;
        };
    }
}