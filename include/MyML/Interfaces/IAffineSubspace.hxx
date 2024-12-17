//
// Created by Admin on 16/12/2024.
//

#pragma once

#include "ILinear.hxx"

namespace My {
template <typename Base, typename Impl, typename ArgList>
struct IAffineSubspace : Base {
  using Point = Arg_Point<ArgList>;
  using Vector = Arg_Vector<ArgList>;

  static_assert(ExistInstance_v<typename Vector::AllVBs, ILinear>);

  using Base::Base;

  inline const Impl operator+(const Vector& v) const noexcept {
    return static_cast<const Impl*>(this)->impl_affine_subspace_add(v);
  }

  inline Impl& operator+=(const Vector& v) noexcept {
    return static_cast<Impl*>(this)->impl_affine_subspace_add_to_self(v);
  }

  inline const Impl operator-(const Vector& v) const noexcept {
    return static_cast<const Impl*>(this)->impl_affine_subspace_minus(v);
  }

  inline Impl& operator-=(const Vector& v) noexcept {
    return static_cast<Impl*>(this)->impl_affine_subspace_minus_to_self(v);
  }
};
}  // namespace My
