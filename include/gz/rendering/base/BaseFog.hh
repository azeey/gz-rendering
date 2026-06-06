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
#ifndef GZ_RENDERING_BASE_BASEFOG_HH_
#define GZ_RENDERING_BASE_BASEFOG_HH_

#include <string>
#include "gz/rendering/Fog.hh"

namespace gz
{
  namespace rendering
  {
    inline namespace GZ_RENDERING_VERSION_NAMESPACE {
    //
    template <class T>
    class BaseFog :
      public virtual Fog,
      public virtual T
    {
      protected: BaseFog();

      public: virtual ~BaseFog();

      // Documentation inherited
      public: virtual FogMode Mode() const override;

      // Documentation inherited
      public: virtual void SetMode(FogMode _mode) override;

      // Documentation inherited
      public: virtual math::Color Color() const override;

      // Documentation inherited
      public: virtual void SetColor(const math::Color &_color) override;

      // Documentation inherited
      public: virtual double Density() const override;

      // Documentation inherited
      public: virtual void SetDensity(double _density) override;

      // Documentation inherited
      public: virtual double Start() const override;

      // Documentation inherited
      public: virtual void SetStart(double _start) override;

      // Documentation inherited
      public: virtual double End() const override;

      // Documentation inherited
      public: virtual void SetEnd(double _end) override;

      protected: FogMode mode = FogMode::FOG_NONE;
      protected: math::Color color = math::Color::White;
      protected: double density = 1.0;
      protected: double start = 0.0;
      protected: double end = 0.0;
    };

    //////////////////////////////////////////////////
    template <class T>
    BaseFog<T>::BaseFog()
    {
    }

    //////////////////////////////////////////////////
    template <class T>
    BaseFog<T>::~BaseFog()
    {
    }

    //////////////////////////////////////////////////
    template <class T>
    FogMode BaseFog<T>::Mode() const
    {
      return this->mode;
    }

    //////////////////////////////////////////////////
    template <class T>
    void BaseFog<T>::SetMode(FogMode _mode)
    {
      this->mode = _mode;
    }

    //////////////////////////////////////////////////
    template <class T>
    math::Color BaseFog<T>::Color() const
    {
      return this->color;
    }

    //////////////////////////////////////////////////
    template <class T>
    void BaseFog<T>::SetColor(const math::Color &_color)
    {
      this->color = _color;
    }

    //////////////////////////////////////////////////
    template <class T>
    double BaseFog<T>::Density() const
    {
      return this->density;
    }

    //////////////////////////////////////////////////
    template <class T>
    void BaseFog<T>::SetDensity(double _density)
    {
      this->density = _density;
    }

    //////////////////////////////////////////////////
    template <class T>
    double BaseFog<T>::Start() const
    {
      return this->start;
    }

    //////////////////////////////////////////////////
    template <class T>
    void BaseFog<T>::SetStart(double _start)
    {
      this->start = _start;
    }

    //////////////////////////////////////////////////
    template <class T>
    double BaseFog<T>::End() const
    {
      return this->end;
    }

    //////////////////////////////////////////////////
    template <class T>
    void BaseFog<T>::SetEnd(double _end)
    {
      this->end = _end;
    }
    }
  }
}
#endif
