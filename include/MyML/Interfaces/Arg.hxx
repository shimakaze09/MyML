//
// Created by Admin on 10/12/2024.
//

#include <MyTemplate/Num.hxx>
#include <MyTemplate/TypeList.hxx>

#ifndef ARG_HXX
#define ARG_HXX

namespace My {
template <typename ArgList>
using Arg_T = At_t<At_t<ArgList, 0>, 0>;

template <typename ArgList>
constexpr size_t Arg_N = At_t<At_t<ArgList, 0>, 1>::value;

template <typename ArgList>
using Arg_F = At_t<ArgList, 1>;

template <typename ArgList>
using Arg_ImplV = At_t<ArgList, 2>;

template <typename ArgList>
using Arg_ImplP = At_t<ArgList, 3>;
}  // namespace My

#endif  //ARG_HXX
