/*
 * Copyright (C) 2021 Open Source Robotics Foundation
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

#ifndef GZ_RENDERING_OGRE_OGRECOMVISUAL_HH_
#define GZ_RENDERING_OGRE_OGRECOMVISUAL_HH_

#include <memory>

#include "gz/rendering/base/BaseCOMVisual.hh"
#include "gz/rendering/ogre/OgreIncludes.hh"
#include "gz/rendering/ogre/OgreMaterial.hh"
#include "gz/rendering/ogre/OgreVisual.hh"

namespace Ogre
{
  class MovableObject;
}

namespace ignition
{
  namespace rendering
  {
    inline namespace IGNITION_RENDERING_VERSION_NAMESPACE {

    // Forward declaration
    class OgreCOMVisualPrivate;

    class IGNITION_RENDERING_OGRE_VISIBLE OgreCOMVisual :
      public BaseCOMVisual<OgreVisual>
    {
      /// \brief Constructor
      protected: OgreCOMVisual();

      /// \brief Destructor
      public: virtual ~OgreCOMVisual();

      // Documentation inherited.
      public: virtual void Init() override;

      // Documentation inherited.
      public: virtual void PreRender() override;

      // Documentation inherited.
      public: Ogre::MovableObject *OgreObject() const;

      /// \brief Create the Light Visual in Ogre
      public: void CreateVisual();

      // Documentation inherited
      public: virtual VisualPtr SphereVisual() const override;

      // Documentation inherited.
      public: virtual MaterialPtr Material() const override;

      // Documentation inherited.
      public: virtual void SetMaterial(
        MaterialPtr _material, bool _unique) override;

      /// \brief Set material to grid geometry.
      /// \param[in] _material Ogre material.
      protected: virtual void SetMaterialImpl(OgreMaterialPtr _material);

      private: friend class OgreScene;

      /// \brief Private data class
      private: std::unique_ptr<OgreCOMVisualPrivate> dataPtr;
    };
    }
  }
}
#endif
