#define NDEBUG
#include <cassert>
#include <iostream>

int testFunction() {
  #ifndef NDEBUG
  std::cerr << __func__ << std::endl;
  #endif
  return 3;
}

int main() {
  using std::cout, std::endl;
  testFunction();
  assert(3 + 5 < 7);

  cout << __PRETTY_FUNCTION__ << endl;
  cout << __FUNCTION__ << endl;
  cout << __func__ << endl;
  cout << __FILE__ << endl;
  cout << __LINE__ << endl;
  cout << __TIME__ << endl;
  cout << __DATE__ << endl;
  cout << __BYTE_ORDER__ << endl;

  return 0;
}
