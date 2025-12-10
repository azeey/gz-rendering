/*
 * Copyright (C) 2022 Open Source Robotics Foundation
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

#include "gz/rendering/Scene.hh"
#include "gz/rendering/GlobalIllumination.hh"

using namespace gz;
using namespace rendering;

/// \brief Keep track of scene extensions
// added as static var here for ABI compatibility
static std::unordered_map<const Scene *, SceneExt *> g_sceneExtMap;

//////////////////////////////////////////////////
Scene::~Scene() = default;

//////////////////////////////////////////////////
GlobalIlluminationPtr Scene::CreateGlobalIllumination()
{
  return this->CreateGlobalIllumination(this->Id(), "");
}

//////////////////////////////////////////////////
GlobalIlluminationPtr Scene::CreateGlobalIllumination(unsigned int _id)
{
  return this->CreateGlobalIllumination(_id, "");
}

//////////////////////////////////////////////////
GlobalIlluminationPtr Scene::CreateGlobalIllumination(const std::string &_name)
{
  return this->CreateGlobalIllumination(this->Id(), _name);
}

//////////////////////////////////////////////////
GlobalIlluminationVctPtr Scene::CreateGlobalIlluminationVct()
{
  return std::dynamic_pointer_cast<GlobalIlluminationVct>(
      this->CreateGlobalIllumination(
        this->Id(), "", GIT_VCT));
}

//////////////////////////////////////////////////
GlobalIlluminationVctPtr Scene::CreateGlobalIlluminationVct(unsigned int _id)
{
  return std::dynamic_pointer_cast<GlobalIlluminationVct>(
      this->CreateGlobalIllumination(_id, "", GIT_VCT));
}

//////////////////////////////////////////////////
GlobalIlluminationVctPtr Scene::CreateGlobalIlluminationVct(
    const std::string &_name)
{
  return std::dynamic_pointer_cast<GlobalIlluminationVct>(
      this->CreateGlobalIllumination(this->Id(), _name, GIT_VCT));
}

//////////////////////////////////////////////////
GlobalIlluminationVctPtr Scene::CreateGlobalIlluminationVct(
    unsigned int _id, const std::string &_name)
{
  return std::dynamic_pointer_cast<GlobalIlluminationVct>(
      this->CreateGlobalIllumination(_id, _name, GIT_VCT));
}

//////////////////////////////////////////////////
GlobalIlluminationCiVctPtr Scene::CreateGlobalIlluminationCiVct()
{
  return std::dynamic_pointer_cast<GlobalIlluminationCiVct>(
      this->CreateGlobalIllumination(
        this->Id(), "", GIT_CI_VCT));
}

//////////////////////////////////////////////////
GlobalIlluminationCiVctPtr Scene::CreateGlobalIlluminationCiVct(
    unsigned int _id)
{
  return std::dynamic_pointer_cast<GlobalIlluminationCiVct>(
      this->CreateGlobalIllumination(_id, "", GIT_CI_VCT));
}

//////////////////////////////////////////////////
GlobalIlluminationCiVctPtr Scene::CreateGlobalIlluminationCiVct(
    const std::string &_name)
{
  return std::dynamic_pointer_cast<GlobalIlluminationCiVct>(
      this->CreateGlobalIllumination(this->Id(), _name, GIT_CI_VCT));
}

//////////////////////////////////////////////////
GlobalIlluminationCiVctPtr Scene::CreateGlobalIlluminationCiVct(
    unsigned int _id, const std::string &_name)
{
  return std::dynamic_pointer_cast<GlobalIlluminationCiVct>(
      this->CreateGlobalIllumination(_id, _name, GIT_CI_VCT));
}

//////////////////////////////////////////////////
SceneExt *Scene::Extension() const
{
  auto it = g_sceneExtMap.find(this);
  if (it != g_sceneExtMap.end())
    return it->second;
  return nullptr;
}

//////////////////////////////////////////////////
void Scene::SetExtension(SceneExt *_ext)
{
  g_sceneExtMap[this] = _ext;
}
