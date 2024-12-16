//
// Created by Admin on 10/12/2024.
//

#ifndef IEUCLIDEANA_HXX
#define IEUCLIDEANA_HXX

#include "IEuclideanV.hxx"

#include "../IAffine.hxx"
#include "../IMetric.hxx"

namespace My {
// euclidean affine space
template <typename Base, typename Point, typename ArgList>
struct IEuclideanA
    : SIVT_CRTP<TemplateList<IMetric, IAffine, IArray>, Base, Point, ArgList> {
  static constexpr size_t N = Arg_N<ArgList>;
  using F = Arg_F<ArgList>;
  using Vector = Arg_Vector<ArgList>;

  static_assert(ExistInstance_v<typename Vector::AllVBs, IEuclideanV>);
  static_assert(Vector::N == N);

  using SIVT_CRTP<TemplateList<IMetric, IAffine, IArray>, Base, Point,
                  ArgList>::SIVT_CRTP;

  inline static F distance2(const Point& x, const Point& y) noexcept {
    return (x - y).norm2();
  }

  inline F distance2(const Point& y) const noexcept {
    auto& x = static_cast<const Point&>(*this);
    return distance2(x, y);
  }

 private:
  template <typename Base, typename Impl, typename ArgList>
  friend struct IAffineSubspace;

  inline const Point impl_affine_subspace_add(const Vector& v) const noexcept {
    auto& p = static_cast<const Point&>(*this);
    Point rst;
    for (size_t i = 0; i < N; i++)
      rst[i] = p[i] + v[i];
    return rst;
  }

  inline Point& impl_affine_subspace_add_to_self(const Vector& v) noexcept {
    auto& p = static_cast<Point&>(*this);
    for (size_t i = 0; i < N; i++)
      p[i] += v[i];
    return p;
  }

  inline const Point impl_affine_subspace_minus(
      const Vector& v) const noexcept {
    auto& p = static_cast<const Point&>(*this);
    Point rst;
    for (size_t i = 0; i < N; i++)
      rst[i] = p[i] - v[i];
    return rst;
  }

  inline Point& impl_affine_subspace_minus_to_self(const Vector& v) noexcept {
    auto& p = static_cast<Point&>(*this);
    for (size_t i = 0; i < N; i++)
      p[i] -= v[i];
    return p;
  }

  template <typename Base, typename Impl, typename ArgList>
  friend struct IAffine;

  inline const Vector impl_affine_minus(const Point& y) const noexcept {
    auto& x = static_cast<const Point&>(*this);
    Vector rst;
    for (size_t i = 0; i < N; i++)
      rst[i] = x[i] - y[i];
    return rst;
  }

  template <typename Base, typename Impl, typename ArgList>
  friend struct IMetric;

  inline static F impl_distance(const Point& x, const Point& y) noexcept {
    return std::sqrt(distance2(x, y));
  }
};
}  // namespace My

#endif  //IEUCLIDEANA_HXX
