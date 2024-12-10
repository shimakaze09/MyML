//
// Created by Admin on 10/12/2024.
//

#ifndef RGB_HXX
#define RGB_HXX

#include "Interfaces/ILinear.hxx"
#include "Interfaces/IArray/IArrayAdd.hxx"
#include "Interfaces/IArray/IArrayScalarMul.hxx"
#include "Interfaces/IArray/IArrayUtil.hxx"
#include "Interfaces/IArray/IArrayHadamardProduct.hxx"
#include "Interfaces/IArray/IArray1D_Util.hxx"

namespace My{
template<typename T>
    struct rgb : SIIT_CRTP<TemplateList<IArray1D_Util, IArrayUtil, IArrayHadamardProduct, ILinear, IArrayScalarMul, IArrayAdd>, rgb<T>,
        TypeList<TypeList<T, Size<3>>, T>>
{
  using SIIT_CRTP<TemplateList<IArray1D_Util, IArrayUtil, IArrayHadamardProduct, ILinear, IArrayScalarMul, IArrayAdd>, rgb<T>,
      TypeList<TypeList<T, Size<3>>, T>>::SIIT_CRTP;
  T illumination() const { return static_cast<T>(0.2126)* (*this)[0] + static_cast<T>(0.7152)* (*this)[1] + static_cast<T>(0.0722)* (*this)[2]; }
  T gray() const { return (*this)[0] * static_cast<T>(0.299) + (*this)[1] * static_cast<T>(0.587) + (*this)[2] * static_cast<T>(0.114); }
};

using rgbf = rgb<float>;
}

#endif //RGB_HXX