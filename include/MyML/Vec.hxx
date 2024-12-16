//
// Created by Admin on 10/12/2024.
//

#ifndef VEC_HXX
#define VEC_HXX

#include "Interfaces/IArray/IArray1D_Util.hxx"
#include "Interfaces/IArray/ICross.hxx"

namespace My {
template <typename T, size_t N>
struct vec : SIIT_CRTP<TemplateList<IArray1D_Util, IEuclideanV>, vec<T, N>,
                       TypeList<TypeList<T, Size<N>>, T>> {
  using SIIT_CRTP<TemplateList<IArray1D_Util, IEuclideanV>, vec<T, N>,
                  TypeList<TypeList<T, Size<N>>, T>>::SIIT_CRTP;
};

template <typename T>
struct vec<T, 3> : SIIT_CRTP<TemplateList<IArray1D_Util, ICross>, vec<T, 3>,
                             TypeList<TypeList<T, Size<3>>, T>> {
  using SIIT_CRTP<TemplateList<IArray1D_Util, ICross>, vec<T, 3>,
                  TypeList<TypeList<T, Size<3>>, T>>::SIIT_CRTP;
};

template <size_t N>
using vecf = vec<float, N>;

using vecf1 = vecf<1>;
using vecf2 = vecf<2>;
using vecf3 = vecf<3>;
using vecf4 = vecf<4>;

template <size_t N>
using veci = vec<int, N>;

using veci1 = veci<1>;
using veci2 = veci<2>;
using veci3 = veci<3>;
using veci4 = veci<4>;

template <size_t N>
using vecu = vec<unsigned, N>;

using vecu1 = vecu<1>;
using vecu2 = vecu<2>;
using vecu3 = vecu<3>;
using vecu4 = vecu<4>;
}  // namespace My

#endif  //VEC_HXX
