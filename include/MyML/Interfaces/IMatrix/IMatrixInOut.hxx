//
// Created by Admin on 10/12/2024.
//

#ifndef IMATRIXINOUT_HXX
#define IMATRIXINOUT_HXX

#include <MyTemplate/SI.hxx>
#include "../../Basic.hxx"
#include "../IInOut.hxx"
#include "IMatrix.hxx"

namespace My {
template <typename Base, typename Impl, typename ArgList>
struct IMatrixInOut
    : SIVT_CRTP<TemplateList<IArrayInOut, IMatrix>, Base, Impl, ArgList> {
  static constexpr size_t N = Arg_N<ArgList>;

  using SIVT_CRTP<TemplateList<IArrayInOut, IMatrix>, Base, Impl,
                  ArgList>::SIVT_CRTP;

  void print(std::ostream& os = std::cout) const noexcept {
    auto& x = static_cast<const Impl&>(*this);

    for (size_t row = 0; row < N; row++) {
      for (size_t col = 0; col < N - 1; col++)
        os << rmv_epsilon(x[col][row]) << " ";
      os << rmv_epsilon(x[N - 1][row]) << std::endl;
    }
  }
};
}  // namespace My

#endif  //IMATRIXINOUT_HXX
