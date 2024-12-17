//
// Created by Admin on 10/12/2024.
//

#pragma once

#include "../IInnerProduct.hxx"
#include "../INormal.hxx"
#include "IArrayLinear.hxx"

namespace My {
// euclidean vector space
template <typename Base, typename Impl, typename ArgList>
struct IEuclideanV : SIVT_CRTP<TemplateList<IInnerProduct, IArrayLinear>, Base,
                               Impl, ArgList> {
  static constexpr size_t N = Arg_N<ArgList>;
  using F = Arg_F<ArgList>;

  using SIVT_CRTP<TemplateList<IInnerProduct, IArrayLinear>, Base, Impl,
                  ArgList>::SIVT_CRTP;

 private:
  template <typename Base, typename Impl, typename ArgList>
  friend struct IInnerProduct;

  inline static F impl_dot(const Impl& x, const Impl& y) noexcept {
    F rst = x[0] * y[0];
    for (size_t i = 1; i < N; i++)
      rst += x[i] * y[i];
    return rst;
  }
};
}  // namespace My
