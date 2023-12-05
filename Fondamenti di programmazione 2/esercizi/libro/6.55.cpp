#include <iostream>
#include <vector>

inline int add(int a, int b) { return a + b; }
inline int subtract(int a, int b) { return a - b; }
inline int multiply(int a, int b) { return a * b; }
inline int divide(int a, int b) { return a / b; }

int main() {
  int x, y;
  std::cout << "x: ";
  std::cin >> x;
  std::cout << "y: ";
  std::cin >> y;

  // pointers to classes
  std::vector<int (*)(int, int)> operations{add, subtract, multiply, divide};

  for (auto e : operations)
    std::cout << e(x, y) << std::endl;

  return 0;
}
