int fib(int n) {
  if (n <= 1)
    return n;

  return fib(n - 1) + fib(n - 2);
}

#include <iostream>

int main() {
  int n;
  std::cout << "n: ";
  std::cin >> n;

  std::cout << fib(n) << std::endl;
  return 0;
}

