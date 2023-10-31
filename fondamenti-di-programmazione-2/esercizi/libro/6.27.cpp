#include <initializer_list>
using std::initializer_list;

#include <iostream>
using std::cout, std::endl;

int sum(initializer_list<int> addends) {
  int s = 0;
  for (int a : addends)
    s += a;
  return s;
}

int main() {
  cout << sum({1, 2, 3, 37, 4, 5, 6}) << endl;
  return 0;
}
