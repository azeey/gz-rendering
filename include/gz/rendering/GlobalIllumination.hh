/*
 * Copyright (C) 2023 Open Source Robotics Foundation
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
 *
*/

#ifndef GZ_RENDERING_GLOBALILLUMINATION_HH_
#define GZ_RENDERING_GLOBALILLUMINATION_HH_

#include "gz/rendering/config.hh"
#include "gz/rendering/Object.hh"
#include "gz/rendering/Scene.hh"

namespace gz
{
  namespace rendering
  {
    inline namespace GZ_RENDERING_VERSION_NAMESPACE {

    enum GlobalIlluminationType
    {
      /// \brief Voxel Cone Tracing
      GIT_VCT,

      /// \brief Cone Tracing followed by a voxel-based light injection
      /// and anisotropic voxel diffusion.
      GIT_CI_VCT,

      /// \brief Screen Space Ambient Occlusion
      GIT_SSAO,
    };

    class GZ_RENDERING_VISIBLE GlobalIllumination :
      public Object
    {
      public: GlobalIllumination();

      public: virtual ~GlobalIllumination();

      public: virtual void PreRender();

      public: virtual void PostRender();

      protected: ScenePtr scene;
    };
    }
  }
}

#endif
