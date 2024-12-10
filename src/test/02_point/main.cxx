//
// Created by Admin on 10/12/2024.
//

#include <iostream>

#include "MyML/Point.hxx"

using namespace My;
using namespace std;

int main(){
  pointf3 o(1, 1, 1);
  pointf3 p(2, 2, 2);
  vecf3 v(1, 2, 3);
  cout << o << endl;
  cout << p + v << endl;
  cout << p - v << endl;
  o += v;
  cout << o << endl;
  o -= v;
  cout << o << endl;
  cout << p - o << endl;
  cout << pointf3::distance(p, o) << endl;

  pointi3 ip(3, 3, 3);
  cout << ip << endl;
  cout << pointf3::distance(o, o + v) << endl;
}
