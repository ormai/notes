// Exercise 1.9:
// Write a program that uses a while to sum the numbers from 50 to 100.

#include <iostream>

int main() {
  int i = 50, sum = 0;
  while (i < 100) {
    sum += i++;
  }
  std::cout << sum << std::endl;
  return 0;
}
