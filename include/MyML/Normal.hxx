//
// Created by Admin on 10/12/2024.
//

#ifndef NORMAL_HXX
#define NORMAL_HXX

#include "Mat.hxx"

#include "Interfaces/IArray/IArray1D_Util.hxx"
#include "Interfaces/IArray/IEuclideanV.hxx"

namespace My {
template <typename T, size_t N>
struct vec;

template <typename T>
struct normal : SIIT_CRTP<TemplateList<IArray1D_Util, IEuclideanV>, normal<T>,
                          TypeList<TypeList<T, Size<3>>, T>> {
  using SIIT_CRTP<TemplateList<IArray1D_Util, IEuclideanV>, normal<T>,
                  TypeList<TypeList<T, Size<3>>, T>>::SIIT_CRTP;

  inline explicit normal(const vec<T, 3>& v) {
    for (size_t i = 0; i < 3; i++)
      (*this)[i] = v[i];
  }

  inline static const normal cross(const normal& x, const normal& y) noexcept {
    return normal{x[1] * y[2] - x[2] * y[1], x[2] * y[0] - x[0] * y[2],
                  x[0] * y[1] - x[1] * y[0]};
  }

  inline const normal cross(const normal& y) const noexcept {
    const normal& x = *this;
    return cross(x, y);
  }

  inline static T sin_theta(const normal& x, const normal& y) noexcept {
    T xN = x.norm();
    T yN = y.norm();
    T xyN = xN * yN;
    assert(xyN > 0);
    return cross(x, y) / xyN;
  }

  inline T sin_theta(const normal& y) const noexcept {
    const normal& x = *this;
    return sin_theta(x, y);
  }

  const mat<T, 3> coord_space() const {
    const auto z = this->normalize();
    auto h = z;
    if (std::abs(h[0]) <= std::abs(h[1]) && std::abs(h[0]) <= std::abs(h[2]))
      h[0] = 1.0;
    else if (std::abs(h[1]) <= std::abs(h[0]) &&
             std::abs(h[1]) <= std::abs(h[2]))
      h[1] = 1.0;
    else
      h[2] = 1.0;

    const auto y = h.cross(z).normalize();
    const auto x = z.cross(y).normalize();

    return {x.cast_to<vec<T, 3>>(), y.cast_to<vec<T, 3>>(),
            z.cast_to<vec<T, 3>>()};
  }

  // I is the incident vector
  // Both I and N should be unit vectors
  // eta is the ratio of the indices of refraction
  // If total internal reflection occurs, return normal(0)
  static const normal refract(const normal& I, const normal& N, T eta) {
    const auto dotValue = N.dot(I);
    const auto k = static_cast<T>(1) -
                   eta * eta * (static_cast<T>(1) - dotValue * dotValue);
    if (k <= T{})
      return normal(T{});
    else
      return eta * I - (eta * dotValue + std::sqrt(k)) * N;
  }

  // I is the incident vector, not necessarily a unit vector
  // N should be a unit vector
  // The length of the return value is the same as I
  static const normal reflect(const normal& I, const normal& N) {
    return I - N * N.dot(I) * static_cast<T>(2);
  }
};

using normalf = normal<float>;
}  // namespace My

#endif  //NORMAL_HXX
