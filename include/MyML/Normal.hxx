//
// Created by Admin on 10/12/2024.
//

#pragma once

#include "Point.hxx"

#include "Interfaces/IArray/ICross.hxx"

namespace My {
// it's necessary to distinguish vector and normal(bivector) when transformings
// ref
// - PBRT p. 86-87
// - wikipedia-bivector: https://en.wikipedia.org/wiki/Bivector
// - https://stackoverflow.com/questions/30465573/transforming-surface-normal-vectors-and-tangent-vectors
template <typename T>
struct normal : SIIT_CRTP<TemplateList<IArray1D_Util, ICross>, normal<T>,
                          TypeList<TypeList<T, Size<3>>, T>> {
  using SIIT_CRTP<TemplateList<IArray1D_Util, ICross>, normal<T>,
                  TypeList<TypeList<T, Size<3>>, T>>::SIIT_CRTP;

  const point<T, 2> to_sphere_texcoord() const noexcept;

  const vec<T, 3> to_sphere_tangent() const noexcept;
};

using normalf = normal<float>;

// maybe error in editor, but no compile error
static_assert(sizeof(normalf) == 3 * sizeof(float));
}  // namespace My

#include "detail/Normal.inl"
