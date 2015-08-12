/*
 * Copyright (C) 2015 Open Source Robotics Foundation
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
#ifndef _IGNITION_RENDERING_OGRESCENE_HH_
#define _IGNITION_RENDERING_OGRESCENE_HH_

#include "ignition/rendering/base/BaseScene.hh"
#include "ignition/rendering/ogre/OgreRenderTypes.hh"

namespace Ogre
{
  class Root;
  class SceneManager;
}

namespace ignition
{
  namespace rendering
  {
    class IGNITION_VISIBLE OgreScene :
      public BaseScene
    {
      protected: OgreScene(unsigned int _id, const std::string &_name);

      public: virtual ~OgreScene();

      public: virtual void Fini();

      public: virtual RenderEngine *GetEngine() const;

      public: virtual VisualPtr GetRootVisual() const;

      public: virtual gazebo::common::Color GetAmbientLight() const;

      public: virtual void SetAmbientLight(const gazebo::common::Color &_color);

      public: virtual gazebo::common::Color GetBackgroundColor() const;

      public: virtual void SetBackgroundColor(const gazebo::common::Color &_color);

      public: virtual void PreRender();

      public: virtual void Clear();

      public: virtual void Destroy();

      public: virtual Ogre::SceneManager *GetOgreSceneManager() const;

      protected: virtual bool LoadImpl();

      protected: virtual bool InitImpl();

      protected: virtual DirectionalLightPtr CreateDirectionalLightImpl(
                     unsigned int _id, const std::string &_name);

      protected: virtual PointLightPtr CreatePointLightImpl(unsigned int _id,
                     const std::string &_name);

      protected: virtual SpotLightPtr CreateSpotLightImpl(unsigned int _id,
                     const std::string &_name);

      protected: virtual CameraPtr CreateCameraImpl(unsigned int _id,
                     const std::string &_name);

      protected: virtual VisualPtr CreateVisualImpl(unsigned int _id,
                     const std::string &_name);

      protected: virtual ArrowVisualPtr CreateArrowVisualImpl(unsigned int _id,
                     const std::string &_name);

      protected: virtual AxisVisualPtr CreateAxisVisualImpl(unsigned int _id,
                     const std::string &_name);

      protected: virtual GeometryPtr CreateBoxImpl(unsigned int _id,
                     const std::string &_name);

      protected: virtual GeometryPtr CreateConeImpl(unsigned int _id,
                     const std::string &_name);

      protected: virtual GeometryPtr CreateCylinderImpl(unsigned int _id,
                     const std::string &_name);

      protected: virtual GeometryPtr CreatePlaneImpl(unsigned int _id,
                     const std::string &_name);

      protected: virtual GeometryPtr CreateSphereImpl(unsigned int _id,
                     const std::string &_name);

      protected: virtual MeshPtr CreateMeshImpl(unsigned int _id,
                     const std::string &_name, const std::string &_meshName);

      protected: virtual MeshPtr CreateMeshImpl(unsigned int _id,
                     const std::string &_name, const MeshDescriptor &_desc);

      protected: virtual MaterialPtr CreateMaterialImpl(unsigned int _id,
                     const std::string &_name);

      protected: virtual RenderTexturePtr CreateRenderTextureImpl(
                     unsigned int _id, const std::string &_name);

      protected: virtual bool InitObject(OgreObjectPtr _object,
                     unsigned int _id, const std::string &_name);

      protected: virtual LightStorePtr GetLights() const;

      protected: virtual SensorStorePtr GetSensors() const;

      protected: virtual VisualStorePtr GetVisuals() const;

      protected: virtual MaterialMapPtr GetMaterials() const;

      private: void CreateContext();

      private: void CreateRootVisual();

      private: void CreateMeshFactory();

      private: void CreateStores();

      private: OgreScenePtr GetSharedThis();

      protected: OgreVisualPtr rootVisual;

      protected: OgreMeshFactoryPtr meshFactory;

      protected: gazebo::common::Color backgroundColor;

      protected: OgreLightStorePtr lights;

      protected: OgreSensorStorePtr sensors;

      protected: OgreVisualStorePtr visuals;

      protected: OgreMaterialMapPtr materials;

      protected: Ogre::Root *ogreRoot;

      protected: Ogre::SceneManager *ogreSceneManager;

      private: friend class OgreRenderEngine;
    };
  }
}
#endif
