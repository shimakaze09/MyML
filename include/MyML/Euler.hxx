//
// Created by Admin on 10/12/2024.
//

#ifndef EULER_HXX
#define EULER_HXX

#include "Quat.hxx"
#include "Vec.hxx"

#include <MyTemplate/SI.hxx>
#include "Interfaces/IArray/IArray.hxx"
#include "Interfaces/IArray/IArray1D_Util.hxx"

namespace My {
template <typename T>
struct quat;

// same with Unity3D
// Z -> X -> Y
// roll -> pitch -> yaw
// Tait¨CBryan angles, extrinsic rotations (math: x-y-z, game: z-x-y)
// ref: https://en.wikipedia.org/wiki/Euler_angles
template <typename T>
struct euler : SIIT_CRTP<TemplateList<IArray1D_Util, IArray>, euler<T>,
                         TypeList<TypeList<T, Size<3>>, T>> {
  using SIIT_CRTP<TemplateList<IArray1D_Util, IArray>, euler<T>,
                  TypeList<TypeList<T, Size<3>>, T>>::SIIT_CRTP;

  const quat<T> to_quat() const noexcept {
    // slow
    /*auto qX = quat<T>::rotate_with<Axis::X>((*this)[0]);
    auto qY = quat<T>::rotate_with<Axis::Y>((*this)[1]);
    auto qZ = quat<T>::rotate_with<Axis::Z>((*this)[2]);
    return qY * qX * qZ;*/

    // fast
    T x = (*this)[0] / 2;
    T y = (*this)[1] / 2;
    T z = (*this)[2] / 2;

    T cX = std::cos(x);
    T cY = std::cos(y);
    T cZ = std::cos(z);

    T sX = std::sin(x);
    T sY = std::sin(y);
    T sZ = std::sin(z);

    T real = cX * cY * cZ + sX * sY * sZ;

    T imagX = sX * cY * cZ + cX * sY * sZ;
    T imagY = cX * sY * cZ - sX * cY * sZ;
    T imagZ = cX * cY * sZ - sX * sY * cZ;

    return {imagX, imagY, imagZ, real};
  }
};

using eulerf = euler<float>;
}  // namespace My

#endif  //EULER_HXX
