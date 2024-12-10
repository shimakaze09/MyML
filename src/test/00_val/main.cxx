//
// Created by Admin on 10/12/2024.
//

#include <iostream>

#include "MyML/Val.hxx"

using namespace My;
using namespace std;

int main() {
  valf3 v(1, 2, 3);
  valf3 u = {0, 2, 3};
  cout << sizeof(valf3) << endl;
  cout << (u == v ? "u==v" : "u!=v") << endl;
  cout << (u < v ? "u<v" : "u>=v") << endl;
  cout << v << endl;
  //cin >> v;
  cout << v << endl;
  cout << u << endl;
  //cout << v.abs() << endl;
  cout << valf3(abs(v[0]), abs(v[1]), abs(v[2])) << endl;
  //cout << v.max_dim() << endl;
  cout << valf3::mix({valf3{1.f, 2.f, 3.f}, valf3{2.f}, valf3{1.f, 2.f, 3.f}},
                     {0.f, 1.f, 2.f})
       << endl;
}
