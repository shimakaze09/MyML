//
// Created by Admin on 16/12/2024.
//

#ifndef IOLINE_HXX
#define IOLINE_HXX

#include "ILinear.hxx"

#include <tuple>

namespace My{
// line in linear subspace
// 'O' : original point
template<typename Base, typename Impl, typename ArgList>
struct IOLine : std::tuple<Arg_Vector<ArgList>>, Base {
  using Vector = Arg_Vector<ArgList>;
  using F = Arg_F<ArgList>;

  static_assert(ExistInstance_v<typename Vector::AllVBs, ILinear>);

  void init_IOLine(const Vector& v) noexcept { dir() = v; }

  Vector& dir() noexcept { return std::get<Vector>(*this); }
  const Vector& dir() const noexcept { return std::get<Vector>(*this); }

};
}

#endif //IOLINE_HXX
