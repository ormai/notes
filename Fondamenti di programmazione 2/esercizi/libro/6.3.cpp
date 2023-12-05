#include <iostream>
using std::cout, std::cin, std::endl;

#include "6.8.h"

int main() {
  int n;
  cout << "Type an integer: ";
  cin >> n;

  cout << "The factorial of " << n << " is " << fact(n) << endl;

  return 0;
}

int fact(int n) {
  int result = n;
  while (n > 1)
    result *= --n;

  return result;
}
