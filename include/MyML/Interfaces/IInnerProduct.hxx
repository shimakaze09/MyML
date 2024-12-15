//
// Created by Admin on 10/12/2024.
//

#ifndef IINNERPRODUCT_HXX
#define IINNERPRODUCT_HXX

#include "INormal.hxx"

namespace My {
template <typename Base, typename Impl, typename ArgList>
struct IInnerProduct : SIVT_CRTP<TemplateList<INorm>, Base, Impl, ArgList> {
  using F = Arg_F<ArgList>;

  using SIVT_CRTP<TemplateList<INorm>, Base, Impl, ArgList>::SIVT_CRTP;

  inline static F dot(const Impl& x, const Impl& y) noexcept {
    return Impl::impl_dot(x, y);
  }

  inline F dot(const Impl& y) const noexcept {
    auto& x = static_cast<const Impl&>(*this);
    return dot(x, y);
  }

  inline F norm2() const noexcept {
    auto& x = static_cast<const Impl&>(*this);
    return dot(x, x);
  }

  inline static F distance2(const Impl& x, const Impl& y) noexcept {
    return (x - y).norm2();
  }

  inline F distance2(const Impl& y) const noexcept {
    auto& x = static_cast<const Impl&>(*this);
    return distance2(x, y);
  }

  inline static F cos_theta(const Impl& x, const Impl& y) noexcept {
    F xN = x.norm();
    F yN = y.norm();
    F xyN = xN * yN;
    assert(xyN != static_cast<F>(0));
    return Impl::dot(x, y) / xyN;
  }

  inline F cos_theta(const Impl& y) const noexcept {
    auto& x = static_cast<const Impl&>(*this);
    return cos_theta(x, y);
  }

  const Impl project(const Impl& n) const noexcept {
    assert(n.is_normalized());
    return dot(n) * n;
  }

  const Impl orthogonalize(const Impl& n) const noexcept {
    auto& x = static_cast<const Impl&>(*this);
    return x - x.project(n);
  }

 private:
  template <typename Base, typename Impl, typename ArgList>
  friend struct INorm;

  inline F impl_norm() const noexcept { return std::sqrt(norm2()); }
};
}  // namespace My

#endif  //IINNERPRODUCT_HXX
