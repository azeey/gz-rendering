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

#include "OgreAmbientOcclusionPass.hh"

#include <OgreRoot.h>
#include <OgreSceneManager.h>
#include <OgreTechnique.h>

#include "gz/common/Console.hh"

using namespace gz;
using namespace rendering;

//////////////////////////////////////////////////
OgreAmbientOcclusionPass::OgreAmbientOcclusionPass()
{
}

//////////////////////////////////////////////////
OgreAmbientOcclusionPass::~OgreAmbientOcclusionPass()
{
}

//////////////////////////////////////////////////
void OgreAmbientOcclusionPass::PreRender()
{
  if (!this->enabled)
  {
    this->CreateSsao();
    this->CreateCrease();
    this->CreateModulate();
    this->enabled = true;
  }
}

//////////////////////////////////////////////////
void OgreAmbientOcclusionPass::SetCamera(Ogre::Camera *_camera)
{
  this->camera = _camera;
  this->viewport = this->camera->getViewport();
}

//////////////////////////////////////////////////
void OgreAmbientOcclusionPass::CreateSsao()
{
  Ogre::CompositorManager::getSingleton().addCompositor(
      this->viewport, "SSAOPost");
  Ogre::CompositorManager::getSingleton().setCompositorEnabled(
      this->viewport, "SSAOPost", true);
}

//////////////////////////////////////////////////
void OgreAmbientOcclusionPass::CreateCrease()
{
  Ogre::CompositorManager::getSingleton().addCompositor(
      this->viewport, "CreaseShading");
  Ogre::CompositorManager::getSingleton().setCompositorEnabled(
      this->viewport, "CreaseShading", true);
}

//////////////////////////////////////////////////
void OgreAmbientOcclusionPass::CreateModulate()
{
  Ogre::CompositorManager::getSingleton().addCompositor(
      this->viewport, "Modulate");
  Ogre::CompositorManager::getSingleton().setCompositorEnabled(
      this->viewport, "Modulate", true);
}
