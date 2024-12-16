//
// Created by Admin on 15/12/2024.
//

#ifndef ILINE_HXX
#define ILINE_HXX

#include "IAffine.hxx"
#include "ILinear.hxx"

#include <tuple>

namespace My {
template <typename Base, typename Impl, typename ArgList>
struct ILine : std::tuple<Arg_ImplP<ArgList>, Arg_ImplV<ArgList>>,
               SIVT_CRTP<TemplateList<IAffine>, Base, Impl, ArgList> {
  using ImplP = Arg_ImplP<ArgList>;
  using ImplV = Arg_ImplV<ArgList>;
  using F = Arg_F<ArgList>;

  static_assert(ExistInstance_v<typename ImplP::AllVBs, IAffine>);
  static_assert(ExistInstance_v<typename ImplV::AllVBs, ILinear>);

  using SIVT_CRTP<TemplateList<IAffine>, Base, Impl, ArgList>::SIVT_CRTP;
  using std::tuple<Arg_ImplP<ArgList>, Arg_ImplV<ArgList>>::tuple;

  ImplP& point() noexcept { return std::get<ImplP>(*this); }

  const ImplP& point() const noexcept { return std::get<ImplP>(*this); }

  ImplV& dir() noexcept { return std::get<ImplV>(*this); }

  const ImplV& dir() const noexcept { return std::get<ImplV>(*this); }

  const ImplP at(F t) const noexcept { return point() + t * dir(); }
};
}  // namespace My
#endif  //ILINE_HXX
