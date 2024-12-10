//
// Created by Admin on 10/12/2024.
//

#ifndef IRING_HXX
#define IRING_HXX

#include "IAdd.hxx"
#include "IMul.hxx"

#include <MyTemplate/SI.hxx>

namespace My {
template <typename Base, typename Impl, typename ArgList>
struct IRing : SIVT_CRTP<TemplateList<IMul, IAdd>, Base, Impl, ArgList> {
  using SIVT_CRTP<TemplateList<IMul, IAdd>, Base, Impl, ArgList>::SIVT_CRTP;
};
}  // namespace My

#endif  //IRING_HXX
