/*
 * Copyright (C) 2026 Open Source Robotics Foundation
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
#include <OgreSceneManager.h>

#include "gz/rendering/ogre2/Ogre2Fog.hh"
#include "gz/rendering/ogre2/Ogre2Conversions.hh"

using namespace gz;
using namespace rendering;

//////////////////////////////////////////////////
Ogre2Fog::Ogre2Fog()
{
}

//////////////////////////////////////////////////
Ogre2Fog::~Ogre2Fog()
{
  this->Destroy();
}

//////////////////////////////////////////////////
void Ogre2Fog::SetMode(FogMode _mode)
{
  BaseFog::SetMode(_mode);
  this->SyncOgreFog();
}

//////////////////////////////////////////////////
void Ogre2Fog::SetColor(const math::Color &_color)
{
  BaseFog::SetColor(_color);
  this->SyncOgreFog();
}

//////////////////////////////////////////////////
void Ogre2Fog::SetDensity(double _density)
{
  BaseFog::SetDensity(_density);
  this->SyncOgreFog();
}

//////////////////////////////////////////////////
void Ogre2Fog::SetStart(double _start)
{
  BaseFog::SetStart(_start);
  this->SyncOgreFog();
}

//////////////////////////////////////////////////
void Ogre2Fog::SetEnd(double _end)
{
  BaseFog::SetEnd(_end);
  this->SyncOgreFog();
}

//////////////////////////////////////////////////
void Ogre2Fog::SyncOgreFog()
{
  if (!this->scene)
    return;

  Ogre::FogMode ogreMode = Ogre::FOG_NONE;
  if (this->mode == FogMode::FOG_LINEAR)
    ogreMode = Ogre::FOG_LINEAR;
  else if (this->mode == FogMode::FOG_EXP)
    ogreMode = Ogre::FOG_EXP;
  else if (this->mode == FogMode::FOG_EXP2)
    ogreMode = Ogre::FOG_EXP2;

  this->scene->OgreSceneManager()->setFog(
      ogreMode,
      Ogre2Conversions::Convert(this->color),
      this->density,
      this->start,
      this->end);
}

//////////////////////////////////////////////////
void Ogre2Fog::Destroy()
{
  if (!this->scene)
    return;

  this->scene->OgreSceneManager()->setFog(Ogre::FOG_NONE);
  this->scene = nullptr;
}
