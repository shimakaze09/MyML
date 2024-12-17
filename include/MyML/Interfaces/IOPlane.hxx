//
// Created by Admin on 16/12/2024.
//

#pragma once

#include "ILinear.hxx"

#include <tuple>

namespace My {
// plane in linear subspace
// 'O' : original point
template <typename Base, typename Impl, typename ArgList>
struct IOPlane : std::tuple<Arg_Vector<ArgList>>, Base {
  using Vector = Arg_Vector<ArgList>;
  using F = Arg_F<ArgList>;

  static_assert(ExistInstance_v<typename Vector::AllVBs, ILinear>);

  void init_IOPlane(const Vector& n) noexcept { normal() = n; }

  Vector& normal() noexcept { return std::get<Vector>(*this); }

  const Vector& normal() const noexcept { return std::get<Vector>(*this); }
};
}  // namespace My
