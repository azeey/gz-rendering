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
#include "ignition/rendering/optix/OptixGeometry.hh"

#include "gazebo/common/Console.hh"
#include "ignition/rendering/optix/OptixScene.hh"
#include "ignition/rendering/optix/OptixVisual.hh"

using namespace ignition;
using namespace rendering;

//////////////////////////////////////////////////
OptixGeometry::OptixGeometry()
{
}

//////////////////////////////////////////////////
OptixGeometry::~OptixGeometry()
{
}

//////////////////////////////////////////////////
bool OptixGeometry::HasParent() const
{
  return this->parent != NULL;
}

//////////////////////////////////////////////////
VisualPtr OptixGeometry::GetParent() const
{
  return this->parent;
}
