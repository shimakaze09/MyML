//
// Created by Admin on 10/12/2024.
//

#ifndef RAY_HXX
#define RAY_HXX

#include "Point.hxx"
#include "Vec.hxx"

#include "Line.hxx"

#include <array>

#include "Interfaces/ILine.hxx"

namespace My {
template <typename T, size_t N>
struct ray : SIIT_CRTP<TemplateList<IInOut, ILine>, ray<T, N>,
                       TypeList<Arg_Empty, T, vec<T, N>, point<T, N>>> {
  using Base = SIIT_CRTP<TemplateList<IInOut, ILine>, ray<T, N>,
                         TypeList<Arg_Empty, T, vec<T, N>, point<T, N>>>;

  T tmin;
  T tmax;

  ray(const point<T, N>& p, const vec<T, N>& dir, T tmin = EPSILON<T>,
      T tmax = std::numeric_limits<T>::max())
      : tmin{tmin}, tmax{tmax} {
    this->init_ILine(p, dir);
  }

  const line<T, N> to_line() const noexcept;

  void print(std::ostream& os = std::cout) const;

  // (isIntersect, (w, u, v), t)
  const std::tuple<bool, std::array<T, 3>, T> intersect_triangle(
      const point<T, 3>& v0, const point<T, 3>& v1,
      const point<T, 3>& v2) const;

 private:
  template <typename Base, typename Impl, typename ArgList>
  friend struct IInOut;
  std::ostream& impl_out(std::ostream& os) const;
  std::istream& impl_in(std::istream& is);

  static const ray impl_move(const ray& r, const point<T, N>& p) noexcept {
    return {p, r.dir(), r.tmin, r.tmax};
  }
};

template <size_t N>
using rayf = ray<float, N>;
using rayf1 = rayf<1>;
using rayf2 = rayf<2>;
using rayf3 = rayf<3>;
}  // namespace My

#include "detail/Ray.inl"

#endif  //RAY_HXX
