//
// Created by Admin on 10/12/2024.
//

#ifndef POINT_HXX
#define POINT_HXX

#include "Vec.hxx"

#include "Interfaces/IArray/IEuclideanA.hxx"
#include "Interfaces/IArray/IArrayUtil.hxx"
#include "Interfaces/IArray/IArray1D_Util.hxx"

namespace My{
template<typename T, size_t N>
    struct vec;
template<typename T, size_t N>
struct val;

template<typename T, size_t N>
struct point : SIIT_CRTP<TemplateList<IArray1D_Util, IArrayUtil, IEuclideanA>, point<T, N>, TypeList<TypeList<T, Size<N>>, T, vec<T, N>>> {
  using SIIT_CRTP<TemplateList<IArray1D_Util, IArrayUtil, IEuclideanA>, point<T, N>, TypeList<TypeList<T, Size<N>>, T, vec<T, N>>>::SIIT_CRTP;
};

template<size_t N>
using pointf = point<float, N>;

using pointf1 = pointf<1>;
using pointf2 = pointf<2>;
using pointf3 = pointf<3>;
using pointf4 = pointf<4>;

template<size_t N>
using pointi = point<int, N>;

using pointi1 = pointi<1>;
using pointi2 = pointi<2>;
using pointi3 = pointi<3>;
using pointi4 = pointi<4>;

template<size_t N>
using pointu = point<unsigned, N>;

using pointu1 = pointu<1>;
using pointu2 = pointu<2>;
using pointu3 = pointu<3>;
using pointu4 = pointu<4>;
}

#endif //POINT_HXX
