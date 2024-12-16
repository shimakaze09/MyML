//
// Created by Admin on 10/12/2024.
//

#ifndef IAFFINE_HXX
#define IAFFINE_HXX

#include "IAffineSubspace.hxx"

namespace My {
template <typename Base, typename Point, typename ArgList>
struct IAffine
    : SIVT_CRTP<TemplateList<IAffineSubspace>, Base, Point, ArgList> {
  using Vector = Arg_Vector<ArgList>;

  static_assert(ExistInstance_v<typename Vector::AllVBs, ILinear>);

  using DBase = SIVT_CRTP<TemplateList<IAffineSubspace>, Base, Point, ArgList>;
  using DBase::DBase;
  using DBase::operator-;

  inline const Vector operator-(const Point& y) const noexcept {
    return static_cast<const Point*>(this)->impl_affine_minus(y);
  }
};
}  // namespace My

#endif  //IAFFINE_HXX
