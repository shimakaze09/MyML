//
// Created by Admin on 20/12/2024.
//

#include <MyML/Scale.hxx>
#include <MyML/Vec.hxx>
#include <iostream>

using namespace std;
using namespace My;

int main(int argc, char* argv[]) {
  vecf4 a;
  vecf4 b;
  cin >> a >> b;
  cout << a + b << endl;
  cout << a.dot(b) << endl;

  scalef4 sa;
  scalef4 sb;
  cin >> sa >> sb;
  cout << sa * sb << endl;
  cout << sa.inverse() << endl;
  xsimd::batch<float, 4> test;

  return 0;
}