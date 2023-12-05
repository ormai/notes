#include <iostream>
using std::cout, std::endl;

int main() {
  int i = 38;
  double d = 934.134;

  cout << (i *= static_cast<int>(d)) << endl;

  return 0;
}
