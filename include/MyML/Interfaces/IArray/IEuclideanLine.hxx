//
// Created by Admin on 15/12/2024.
//

#ifndef IEUCLIDEANLINE_HXX
#define IEUCLIDEANLINE_HXX

#include "../ILine.hxx"
#include "IEuclideanA.hxx"

#include <vector>

namespace My {
// euclidean affine space
template<typename Base, typename Impl, typename ArgList>
struct IEuclideanLine : SIVT_CRTP<TemplateList<IEuclideanA, ILine>, Base, Impl, ArgList> {
  using ImplP = Arg_ImplP<ArgList>;
  using ImplV = Arg_ImplV<ArgList>;
  using F = Arg_F<ArgList>;
  static constexpr size_t N = ImplP::N;
  static_assert(ExistInstance_v<typename ImplP::AllVBs, IEuclideanA>);
  static_assert(ExistInstance_v<typename ImplV::AllVBs, IEuclideanV>);
  static_assert(ImplP::N == ImplV::N);
  using SIVT_CRTP<TemplateList<IEuclideanA, ILine>, Base, Impl, ArgList>::SIVT_CRTP;
};
}

#endif //IEUCLIDEANLINE_HXX
