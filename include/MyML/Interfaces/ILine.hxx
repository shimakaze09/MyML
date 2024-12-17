//
// Created by Admin on 15/12/2024.
//

#pragma once

#include "IAffineRealSubspace.hxx"
#include "IOLine.hxx"

namespace My {
// line in real affine subspace
template <typename Base, typename Impl, typename ArgList>
struct ILine : SIVT_CRTP<TemplateList<IAffineRealSubspace, IOLine>, Base, Impl,
                         ArgList> {
  using Point = Arg_Point<ArgList>;
  using Vector = Arg_Vector<ArgList>;
  using F = Arg_F<ArgList>;

  void init_ILine(const Point& p, const Vector& dir) noexcept {
    this->init_IAffineRealSubspace(p);
    this->init_IOLine(dir);
  }

  const Point at(F t) const noexcept { return this->point() + t * this->dir(); }
};
}  // namespace My
