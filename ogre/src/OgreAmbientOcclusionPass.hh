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

#ifndef GZ_RENDERING_OGRE_OGREAMBIENTOCCLUSIONPASS_HH_
#define GZ_RENDERING_OGRE_OGREAMBIENTOCCLUSIONPASS_HH_

#include "gz/rendering/ogre/OgreGlobalIllumination.hh"

namespace gz
{
  namespace rendering
  {
    inline namespace GZ_RENDERING_VERSION_NAMESPACE {

    class OgreAmbientOcclusionPass :
      public OgreGlobalIllumination
    {
      public: OgreAmbientOcclusionPass();

      public: virtual ~OgreAmbientOcclusionPass();

      public: virtual void PreRender() override;

      protected: void SetCamera(Ogre::Camera *_camera);

      protected: virtual void CreateSsao();

      protected: virtual void CreateCrease();

      protected: virtual void CreateModulate();

      protected: bool enabled = false;

      protected: Ogre::Camera *camera;

      protected: Ogre::Viewport *viewport;
    };
    }
  }
}

#endif
