//
// Created by Admin on 16/12/2024.
//

#pragma once

#include "IAffine.hxx"

namespace My {
template <typename Base, typename Impl, typename ArgList>
struct IAffineRealSubspace
    : std::tuple<Arg_Point<ArgList>>,
      SIVT_CRTP<TemplateList<IAffineSubspace>, Base, Impl, ArgList> {
  using Point = Arg_Point<ArgList>;
  using Vector = Arg_Vector<ArgList>;

  static_assert(ExistInstance_v<typename Point::AllVBs, IAffine>);
  static_assert(ExistInstance_v<typename Vector::AllVBs, ILinear>);
  static_assert(Point::N == Vector::N);

  using SIVT_CRTP<TemplateList<IAffineSubspace>, Base, Impl,
                  ArgList>::SIVT_CRTP;

  Point& point() noexcept { return std::get<Point>(*this); }

  const Point& point() const noexcept {
    return const_cast<IAffineRealSubspace*>(this)->point();
  }

  static const Impl move(const Impl& impl, const Point& p) noexcept {
    return Impl::impl_move(impl, p);
  }

  const Impl move(const Point& p) const noexcept {
    auto& impl = static_cast<const Impl&>(*this);
    return move(impl, p);
  }

  Impl& move_self(const Point& p) noexcept {
    point() = p;
    return static_cast<Impl&>(*this);
  }

  void init_IAffineRealSubspace(const Point& p) { point() = p; }

 private:
  template <typename Base, typename Impl, typename ArgList>
  friend struct IAffineSubspace;

  const Impl impl_affine_subspace_add(const Vector& v) const noexcept {
    auto moved_p = point() + v;
    return move(moved_p);
  }

  Impl& impl_affine_subspace_add_to_self(const Vector& v) noexcept {
    point() += v;
    return static_cast<Impl&>(*this);
  }

  const Impl impl_affine_subspace_minus(const Vector& v) const noexcept {
    auto moved_p = point() - v;
    return move(moved_p);
  }

  Impl& impl_affine_subspace_minus_to_self(const Vector& v) noexcept {
    point() -= v;
    return static_cast<Impl&>(*this);
  }
};
}  // namespace My
