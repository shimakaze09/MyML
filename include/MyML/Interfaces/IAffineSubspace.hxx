//
// Created by Admin on 16/12/2024.
//

#ifndef IAFFINESUBSPACE_HXX
#define IAFFINESUBSPACE_HXX

#include "ILinear.hxx"

namespace My {
template <typename Base, typename Impl, typename ArgList>
struct IAffineSubspace : Base {
  using ImplV = Arg_ImplV<ArgList>;

  static_assert(ExistInstance_v<typename ImplV::AllVBs, ILinear>);

  using Base::Base;

  inline const Impl operator+(const ImplV& v) const noexcept {
    return static_cast<const Impl*>(this)->impl_affine_add(v);
  }

  inline Impl& operator+=(const ImplV& v) noexcept {
    return static_cast<Impl*>(this)->impl_affine_add_to_self(v);
  }

  inline const Impl operator-(const ImplV& v) const noexcept {
    return static_cast<const Impl*>(this)->impl_affine_minus_v(v);
  }

  inline Impl& operator-=(const ImplV& v) noexcept {
    return static_cast<Impl*>(this)->impl_affine_minus_v_to_self(v);
  }
};
}  // namespace My

#endif  //IAFFINESUBSPACE_HXX
