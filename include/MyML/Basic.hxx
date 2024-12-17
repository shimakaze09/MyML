//
// Created by Admin on 10/12/2024.
//

#pragma once

#include <cmath>
#include <random>

namespace My {
template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
constexpr auto EPSILON = static_cast<T>(0.000001);

template <typename T, typename = std::enable_if_t<std::is_floating_point_v<T>>>
constexpr auto PI = static_cast<T>(3.141592653589793);

enum class Axis : size_t { X = 0, Y = 1, Z = 2 };

template <typename T>
inline const T rmv_epsilon(T val) noexcept;

template <typename T>
inline constexpr T to_radian(T degree) noexcept;

template <typename T, typename = std::enable_if_t<std::is_floating_point_v<T>>>
inline constexpr T to_degree(T radian) noexcept;

template <typename T>
inline T sgn(T v) noexcept;

template <typename T>
bool is_zero(T v) noexcept;

template <typename T>
bool is_nan(T v) noexcept;

template <typename T, typename F>
T lerp(T x, T y, F t) noexcept;

// 1 - epsilon, T: float / double
template <typename T>
constexpr T one_epsilon() noexcept;

// range: [0, 1), T: float / double
template <typename T>
float rand01() noexcept;

// range: [0, 2^64-1]
size_t randi() noexcept;
}  // namespace My

#include "detail/Basic.inl"
