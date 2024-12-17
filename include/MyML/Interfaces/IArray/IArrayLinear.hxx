//
// Created by Admin on 17/12/2024.
//

#pragma once

#include "IArrayAdd.hxx"
#include "IArrayScalarMul.hxx"
#include "../ILinear.hxx"

namespace My{
template<typename Base, typename Impl, typename ArgList>
    struct IArrayLinear : SIVT_CRTP<TemplateList<IArrayAdd, IArrayScalarMul, ILinear>, Base, Impl, ArgList> {
  using SIVT_CRTP<TemplateList<IArrayAdd, IArrayScalarMul, ILinear>, Base, Impl, ArgList>::SIVT_CRTP;
};
}
