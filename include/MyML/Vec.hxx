//
// Created by Admin on 10/12/2024.
//

#ifndef VEC_HXX
#define VEC_HXX

#include "Interfaces/IArray/IArray1D_Util.hxx"
#include "Interfaces/IArray/IEuclideanV.hxx"

namespace My {
template <typename T, size_t N>
struct point;
template <typename T, size_t N>
struct val;

template <typename T, size_t N>
struct vec : SIIT_CRTP<TemplateList<IArray1D_Util, IEuclideanV>, vec<T, N>,
                       TypeList<TypeList<T, Size<N>>, T>> {
  using SIIT_CRTP<TemplateList<IArray1D_Util, IEuclideanV>, vec<T, N>,
                  TypeList<TypeList<T, Size<N>>, T>>::SIIT_CRTP;
};

template <typename T>
struct vec<T, 3> : SIIT_CRTP<TemplateList<IArray1D_Util, IEuclideanV>,
                             vec<T, 3>, TypeList<TypeList<T, Size<3>>, T>> {
  using SIIT_CRTP<TemplateList<IArray1D_Util, IEuclideanV>, vec<T, 3>,
                  TypeList<TypeList<T, Size<3>>, T>>::SIIT_CRTP;

  static const vec cross(const vec& x, const vec& y) noexcept {
    return vec{x[1] * y[2] - x[2] * y[1], x[2] * y[0] - x[0] * y[2],
               x[0] * y[1] - x[1] * y[0]};
  }

  const vec cross(const vec& y) const noexcept {
    const vec& x = *this;
    return cross(x, y);
  }

  static T sin_theta(const vec& x, const vec& y) noexcept {
    T xN = x.norm();
    T yN = y.norm();
    T xyN = xN * yN;
    assert(xyN > 0);
    return cross(x, y).norm() / xyN;
  }

  T sin_theta(const vec& y) const noexcept {
    const vec& x = *this;
    return sin_theta(x, y);
  }
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
