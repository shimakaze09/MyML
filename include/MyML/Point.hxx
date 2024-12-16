//
// Created by Admin on 10/12/2024.
//

#ifndef POINT_HXX
#define POINT_HXX

#include "Vec.hxx"

#include "Interfaces/IArray/IArray1D_Util.hxx"

#include "Interfaces/IArray/IEuclideanA.hxx"

namespace My {
template <typename T, size_t N>
struct vec;

template <typename T, size_t N>
struct point
    : SIIT_CRTP<TemplateList<IArray1D_Util, IEuclideanA>, point<T, N>,
                TypeList<TypeList<T, Size<N>>, T, vec<T, N>, point<T, N>>> {
  using SIIT_CRTP<
      TemplateList<IArray1D_Util, IEuclideanA>, point<T, N>,
      TypeList<TypeList<T, Size<N>>, T, vec<T, N>, point<T, N>>>::SIIT_CRTP;

  template <typename Container>
  static const point combine(const Container& points, T weight) {
    point rst{static_cast<T>(0)};
    for (const auto& p : points) {
      for (size_t i = 0; i < N; i++)
        rst[i] += weight * p[i];
    }
    return rst;
  }

  template <typename PContainer, typename WContainer>
  static const point combine(PContainer points, WContainer weights) {
    assert(points.size() == weights.size());
    point rst{static_cast<T>(0)};
    auto witer = weights.begin();
    for (const auto& p : points) {
      T weight = *witer;
      for (size_t i = 0; i < N; i++)
        rst[i] += weight * p[i];
      ++witer;
    }
    return rst;
  }
};

template <size_t N>
using pointf = point<float, N>;

using pointf1 = pointf<1>;
using pointf2 = pointf<2>;
using pointf3 = pointf<3>;
using pointf4 = pointf<4>;

template <size_t N>
using pointi = point<int, N>;

using pointi1 = pointi<1>;
using pointi2 = pointi<2>;
using pointi3 = pointi<3>;
using pointi4 = pointi<4>;

template <size_t N>
using pointu = point<unsigned, N>;

using pointu1 = pointu<1>;
using pointu2 = pointu<2>;
using pointu3 = pointu<3>;
using pointu4 = pointu<4>;
}  // namespace My

#endif  //POINT_HXX
