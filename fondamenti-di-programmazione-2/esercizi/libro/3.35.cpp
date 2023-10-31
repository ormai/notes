#include <iostream>

int main() {
  constexpr unsigned size = 10;
  int array[size];

  int *start = std::begin(array);
  int *end = std::end(array);

  // int *start = &array[0];
  // int *end = &array[size];

  while (start < end) {
    *start = 0;
    start++;
  }

  for (int e : array)
    std::cout << e << std::endl;

  return 0;
}

