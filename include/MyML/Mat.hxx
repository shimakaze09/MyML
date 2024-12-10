//
// Created by Admin on 10/12/2024.
//

#ifndef MAT_HXX
#define MAT_HXX

#include "Interfaces/IMatrix/IMatrixInOut.hxx"
#include "Interfaces/IMatrix/IMatrixMul.hxx"
#include "Interfaces/IRing.hxx"
#include "Vec.hxx"

namespace My {
template <typename T, size_t N>
struct mat
    : SIIT_CRTP<TemplateList<IMatrixMul, IMatrixInOut, IRing, IEuclideanV>,
                mat<T, N>, TypeList<TypeList<vec<T, N>, Size<N>>, T>> {
  using SIIT_CRTP<TemplateList<IMatrixMul, IMatrixInOut, IRing, IEuclideanV>,
                  mat<T, N>,
                  TypeList<TypeList<vec<T, N>, Size<N>>, T>>::SIIT_CRTP;
};

template <size_t N>
using matf = mat<float, N>;

using matf3 = matf<3>;
using matf4 = matf<4>;
}  // namespace My

#endif  //MAT_HXX
