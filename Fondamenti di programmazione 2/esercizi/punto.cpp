#include <cmath>
#include <iostream>

struct punto {
  int x;
  int y;
};

double distanza(const punto &, const punto &);

int main() {
  punto a, b;
  double d;

  std::cin >> a.x >> a.y;
  std::cin >> b.x >> b.y;

  std::cout << distanza(a, b) << std::endl;

  return 0;
}

double distanza(const punto &p1, const punto &p2) {
  return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
  // return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}
