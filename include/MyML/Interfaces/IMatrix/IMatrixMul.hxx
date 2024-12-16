//
// Created by Admin on 10/12/2024.
//

#ifndef IMATRIXMUL_HXX
#define IMATRIXMUL_HXX

#include "../IMul.hxx"
#include "IMatrix.hxx"
#include "IMatrixMul_detail.hxx"

namespace My {
template <typename Base, typename Impl, typename ArgList>
struct IMatrixMul
    : SIVT_CRTP<TemplateList<IMul, IMatrix>, Base, Impl, ArgList> {
  static constexpr size_t N = Arg_N<ArgList>;
  using F = Arg_F<ArgList>;

  using SIVT_CRTP<TemplateList<IMul, IMatrix>, Base, Impl, ArgList>::SIVT_CRTP;
  using SIVT_CRTP<TemplateList<IMul, IMatrix>, Base, Impl, ArgList>::operator*;

  using Vector = Arg_T<ArgList>;

  inline const Vector operator*(const Vector& v) const noexcept {
    auto& m = static_cast<const Impl&>(*this);
    return detail::IMatrixMul::mul<N>::run(m, v);
  }

 private:
  template <typename Base, typename Impl, typename ArgList>
  friend struct IMul;

  inline const Impl impl_mul(const Impl& y) const noexcept {
    auto& x = static_cast<const Impl&>(*this);
    return detail::IMatrixMul::mul<N>::run(x, y);
  }

  inline const Impl impl_inverse() const noexcept {
    auto& m = static_cast<const Impl&>(*this);
    return detail::IMatrixMul::inverse<N>::run(m);
  }
};
}  // namespace My

#endif  //IMATRIXMUL_HXX
