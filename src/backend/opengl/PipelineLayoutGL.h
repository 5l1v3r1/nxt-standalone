// Copyright 2017 The NXT Authors
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

#ifndef BACKEND_OPENGL_PIPELINELAYOUTGL_H_
#define BACKEND_OPENGL_PIPELINELAYOUTGL_H_

#include "common/PipelineLayout.h"

#include "glad/glad.h"

namespace backend {
namespace opengl {

    class Device;

    class PipelineLayout : public PipelineLayoutBase {
        public:
            PipelineLayout(PipelineLayoutBuilder* builder);

            using BindingIndexInfo = std::array<std::array<GLuint, kMaxBindingsPerGroup>, kMaxBindGroups>;
            const BindingIndexInfo& GetBindingIndexInfo() const;

            GLuint GetTextureUnitsUsed() const;
            size_t GetNumSamplers() const;
            size_t GetNumSampledTextures() const;

        private:
            BindingIndexInfo indexInfo;
            size_t numSamplers;
            size_t numSampledTextures;
    };

}
}

#endif // BACKEND_OPENGL_PIPELINELAYOUTGL_H_
