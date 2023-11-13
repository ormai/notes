int mcd(int x, int y) {
  int r = x % y;

  if (!r)
    return y;

  return mcd(y, r);
}

#include <iostream>
int main() {
  int x, y;
  std::cout << "x: ";
  std::cin >> x;
  std::cout << "y: ";
  std::cin >> y;

  std::cout << mcd(x, y) << std::endl;

  return 0;
}
