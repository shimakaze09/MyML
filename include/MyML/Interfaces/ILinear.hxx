//
// Created by Admin on 10/12/2024.
//

#ifndef ILINEAR_HXX
#define ILINEAR_HXX

#include "IAdd.hxx"
#include "IScalarMul.hxx"

namespace My {
template <typename Base, typename Impl, typename ArgList>
struct ILinear
    : SIVT_CRTP<TemplateList<IAdd, IScalarMul>, Base, Impl, ArgList> {
  using SIVT_CRTP<TemplateList<IAdd, IScalarMul>, Base, Impl,
                  ArgList>::SIVT_CRTP;
};
}  // namespace My

#endif  //ILINEAR_HXX
