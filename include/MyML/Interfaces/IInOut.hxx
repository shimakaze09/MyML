//
// Created by Admin on 10/12/2024.
//

#pragma once

#include <iostream>

namespace My {
// virtual : in, out
template <typename Base, typename Impl, typename ArgList>
struct IInOut : Base {
  using Base::Base;

  friend std::ostream& operator<<(std::ostream& os, const Impl& x) {
    return x.out(os);
  }

  friend std::istream& operator>>(std::istream& is, Impl& x) {
    return x.in(is);
  }

 private:
  std::ostream& out(std::ostream& os) const {
    auto& x = static_cast<const Impl&>(*this);
    return x.impl_out(os);
  }

  std::istream& in(std::istream& is) {
    auto& x = static_cast<Impl&>(*this);
    return x.impl_in(is);
  }
};
}  // namespace My
