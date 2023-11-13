int fact(int n) {
  if (n <= 1)
    return 1;

  return n * fact(n - 1);
}

#include <iostream>

int main() {
  int n;
  std::cout << "n: ";
  std::cin >> n;

  std::cout << fact(n) << std::endl;
  return 0;
}
