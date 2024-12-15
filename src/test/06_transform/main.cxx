//
// Created by Admin on 10/12/2024.
//

#include <iostream>

#include "MyML/Transform.hxx"

using namespace My;
using namespace std;

int main() {
  transformf trans;  // default constructor

  eulerf e(to_radian(13.f), to_radian(42.f), to_radian(71.f));
  transformf t(e);
  cout << e << endl;
  cout << e.to_quat().to_euler() << endl;
  cout << transformf(e).decompose_euler() << endl;

  quatf q({1, 1, 1}, to_radian(45.f));
  cout << q << endl;
  cout << transformf(q).decompose_quatenion() << endl;

  cout << transformf(q).decompose_euler() << endl;
  cout << q.to_euler() << endl;

  transformf::rotate_with<Axis::X>(to_radian(30.f)).print();
  transformf::rotate_with<Axis::Y>(to_radian(30.f)).print();
  transformf::rotate_with<Axis::Z>(to_radian(30.f)).print();

  cout << transformf::look_at(pointf3{0.f}, pointf3{0.f, 0.f, 1.f}) << endl;
  cout << transformf::perspective(to_radian(60.f), 16.f / 9.f, 0.1f, 100.f)
       << endl;
  cout << transformf::orthographic(10.f, 10.f, 0.1f, 100.f) << endl;

  cout << t.decompose_position() << endl;
  cout << t.decompose_mat3() << endl;
  cout << t.decompose_scale() << endl;
  cout << t.decompose_euler() << endl;
  cout << t.decompose_mat3() << endl;
  cout << t.decompose_rotation_matrix() << endl;

  cout << t * transformf(q) << endl;
  cout << t * pointf3{} << endl;
  cout << t * vecf3{} << endl;
  cout << t * normalf{} << endl;

  cout << transformf::rotate_with<Axis::X>(to_radian(180.f))
              .decompose_quatenion()
       << endl;

  cout << t.inverse() << endl;
}
