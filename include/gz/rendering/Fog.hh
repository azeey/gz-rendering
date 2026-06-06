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
#ifndef GZ_RENDERING_FOG_HH_
#define GZ_RENDERING_FOG_HH_

#include <gz/math/Color.hh>
#include "gz/rendering/config.hh"
#include "gz/rendering/Object.hh"
#include "gz/rendering/RenderTypes.hh"

namespace gz
{
  namespace rendering
  {
    inline namespace GZ_RENDERING_VERSION_NAMESPACE {
    //
    /// \enum FogMode
    /// \brief Fog mode types
    enum class FogMode
    {
      /// \brief No fog
      FOG_NONE = 0,
      /// \brief Exponential fog
      FOG_EXP = 1,
      /// \brief Exponential squared fog
      FOG_EXP2 = 2,
      /// \brief Linear fog
      FOG_LINEAR = 3
    };

    /// \class Fog Fog.hh gz/rendering/Fog.hh
    /// \brief Represents scene-wide fog parameters. Created via
    /// SceneExt::CreateExt("fog").
    class GZ_RENDERING_VISIBLE Fog : public virtual Object
    {
      /// \brief Destructor
      public: virtual ~Fog() = default;

      /// \brief Set the scene fog mode
      /// \param[in] _mode Fog mode
      public: virtual void SetMode(FogMode _mode) = 0;

      /// \brief Get the scene fog mode
      /// \return Fog mode
      public: virtual FogMode Mode() const = 0;

      /// \brief Set the scene fog color
      /// \param[in] _color Fog color
      public: virtual void SetColor(const math::Color &_color) = 0;

      /// \brief Get the scene fog color
      /// \return Fog color
      public: virtual math::Color Color() const = 0;

      /// \brief Set the scene fog density (used for exponential modes)
      /// \param[in] _density Fog density
      public: virtual void SetDensity(double _density) = 0;

      /// \brief Get the scene fog density
      /// \return Fog density
      public: virtual double Density() const = 0;

      /// \brief Set the scene fog start distance (used for linear mode)
      /// \param[in] _start Fog start distance
      public: virtual void SetStart(double _start) = 0;

      /// \brief Get the scene fog start distance
      /// \return Fog start distance
      public: virtual double Start() const = 0;

      /// \brief Set the scene fog end distance (used for linear mode)
      /// \param[in] _end Fog end distance
      public: virtual void SetEnd(double _end) = 0;

      /// \brief Get the scene fog end distance
      /// \return Fog end distance
      public: virtual double End() const = 0;
    };
    }
  }
}
#endif
