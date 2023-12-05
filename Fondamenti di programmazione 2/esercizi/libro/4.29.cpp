#include <iostream>
using std::cout, std::endl;

int main() {
  int x[10];
  int *p = x;

  cout << (sizeof(x) / sizeof(*x)) << endl; // 4 * 10 / 4 = 10 byte
  cout << (sizeof(p) / sizeof(*p)) << endl; // 8 / 4 = 2 byte

  return 0;
}
