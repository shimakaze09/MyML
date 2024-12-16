//
// Created by Admin on 17/12/2024.
//

#ifndef TRIANGLE_HXX
#define TRIANGLE_HXX

#include "Point.hxx"
#include "Val.hxx"
#include "Vec.hxx"

namespace My {
template <typename T, size_t N>
struct triangle : SIIT_CRTP<TemplateList<IArrayInOut>, triangle<T, N>,
                            TypeList<TypeList<point<T, N>, Size<3>>, T>> {
  using SIIT_CRTP<TemplateList<IArrayInOut>, triangle<T, N>,
                  TypeList<TypeList<point<T, N>, Size<3>>, T>>::SIIT_CRTP;

  T area() const noexcept {
    auto v01 = (*this)[1] - (*this)[0];
    auto v02 = (*this)[2] - (*this)[0];
    return v01.cross(v02).norm() * static_cast<T>(0.5);
  }
};
}  // namespace My

#endif  //TRIANGLE_HXX
