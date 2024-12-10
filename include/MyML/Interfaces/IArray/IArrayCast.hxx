//
// Created by Admin on 10/12/2024.
//

#ifndef IARRAYCAST_HXX
#define IARRAYCAST_HXX

#include "IArray.hxx"

namespace My {
template <typename Base, typename Impl, typename ArgList>
struct IArrayCast : SIVT_CRTP<TemplateList<IArray>, Base, Impl, ArgList> {
  using SIVT_CRTP<TemplateList<IArray>, Base, Impl, ArgList>::SIVT_CRTP;

  static constexpr size_t N = Arg_N<ArgList>;

  template <typename To>
  const To cast_to() const noexcept {
    To rst{};
    constexpr size_t M = To::N;
    using F = typename To::F;
    for (size_t i = 0; i < std::min(N, M); i++)
      rst[i] = static_cast<F>((*this)[i]);
    for (size_t i = std::min(N, M); i < M; i++)
      rst[i] = F{};
    return rst;
  }
};
}  // namespace My

#endif  //IARRAYCAST_HXX
