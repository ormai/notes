#include <iostream>
using std::cout, std::endl;

#include "6.8.h"

int main() {
  for (int i = 0; i < 10; ++i)
    cout << sequence() << endl;

  return 0;
}

int sequence() {
  static int count = 0;
  return count++;
}
