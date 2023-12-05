#include <iostream>
using std::cout, std::cin, std::endl;

#include "6.8.h"

int main() {
  int n;
  cout << "Type a number: ";
  cin >> n;

  cout << '|' << n << "| = " << abs(n) << endl;

  return 0;
}

int abs(int n) {
  if (n < 0)
    return -n;

  return n;
}
