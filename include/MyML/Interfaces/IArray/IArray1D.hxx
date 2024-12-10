//
// Created by Admin on 10/12/2024.
//

#ifndef IARRAY1D_HXX
#define IARRAY1D_HXX

#include "IArray.hxx"

namespace My {
template <typename Base, typename Impl, typename ArgList>
struct IArray1D : SIVT_CRTP<TemplateList<IArray>, Base, Impl, ArgList> {
  using SIVT_CRTP<TemplateList<IArray>, Base, Impl, ArgList>::SIVT_CRTP;
  static_assert(std::is_same_v<Arg_T<ArgList>, Arg_F<ArgList>>);
};
}  // namespace My

#endif  //IARRAY1D_HXX
