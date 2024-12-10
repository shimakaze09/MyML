//
// Created by Admin on 10/12/2024.
//

#ifndef IARRAYADD_HXX
#define IARRAYADD_HXX

#include "../IAdd.hxx"
#include "IArray.hxx"

namespace My {
template <typename Base, typename Impl, typename ArgList>
struct IArrayAdd : SIVT_CRTP<TemplateList<IAdd, IArray>, Base, Impl, ArgList> {
  static constexpr size_t N = Arg_N<ArgList>;

  using SIVT_CRTP<TemplateList<IAdd, IArray>, Base, Impl, ArgList>::SIVT_CRTP;

 private:
  template <typename Base, typename Impl, typename ArgList>
  friend struct IAdd;

  inline const Impl impl_add(const Impl& y) const noexcept {
    auto& x = static_cast<const Impl&>(*this);
    Impl rst{};
    for (size_t i = 0; i < N; i++)
      rst[i] = x[i] + y[i];
    return rst;
  }

  inline Impl& impl_add_to_self(const Impl& y) noexcept {
    auto& x = static_cast<Impl&>(*this);
    for (size_t i = 0; i < N; i++)
      x[i] += y[i];
    return x;
  }

  inline const Impl impl_add_inverse() const noexcept {
    auto& x = static_cast<const Impl&>(*this);
    Impl rst{};
    for (size_t i = 0; i < N; i++)
      rst[i] = -x[i];
    return rst;
  }

  // const Impl Minus(const Impl& y) const noexcept {
  //   auto& x = static_cast<const Impl&>(*this);
  //   Impl rst{};
  //   for (size_t i = 0; i < N; i++)
  //     rst[i] = x[i] - y[i];
  //   return rst;
  // }
  //
  // Impl& MinusToSelf(const Impl& y) noexcept {
  //   auto& x = static_cast<Impl&>(*this);
  //   for (size_t i = 0; i < N; i++)
  //     x[i] -= y[i];
  //   return x;
  // }
};
}  // namespace My

#endif  //IARRAYADD_HXX