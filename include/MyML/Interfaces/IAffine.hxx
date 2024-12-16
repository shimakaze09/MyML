//
// Created by Admin on 10/12/2024.
//

#ifndef IAFFINE_HXX
#define IAFFINE_HXX

#include "IAffineSubspace.hxx"

namespace My {
template <typename Base, typename ImplP, typename ArgList>
struct IAffine
    : SIVT_CRTP<TemplateList<IAffineSubspace>, Base, ImplP, ArgList> {
  using ImplV = Arg_ImplV<ArgList>;

  static_assert(ExistInstance_v<typename ImplV::AllVBs, ILinear>);

  using DBase = SIVT_CRTP<TemplateList<IAffineSubspace>, Base, ImplP, ArgList>;
  using DBase::DBase;
  using DBase::operator-;

  inline const ImplV operator-(const ImplP& y) const noexcept {
    return static_cast<const ImplP*>(this)->impl_affine_minus(y);
  }
};
}  // namespace My

#endif  //IAFFINE_HXX
