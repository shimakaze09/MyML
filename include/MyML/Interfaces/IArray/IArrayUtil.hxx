//
// Created by Admin on 10/12/2024.
//

#pragma once

#include "IArrayCast.hxx"
#include "IArrayInOut.hxx"

namespace My {
template <typename Base, typename Impl, typename ArgList>
struct IArrayUtil
    : SIVT_CRTP<TemplateList<IArrayCast, IArrayInOut>, Base, Impl, ArgList> {
  using SIVT_CRTP<TemplateList<IArrayCast, IArrayInOut>, Base, Impl,
                  ArgList>::SIVT_CRTP;
};
}  // namespace My
