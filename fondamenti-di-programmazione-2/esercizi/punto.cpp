#include <iostream>
#include <cmath>
using namespace std;

struct punto {
  int x;
  int y;
};

double distanza(const punto&, const punto&);

int main() {
  punto a, b;
  double d;

  cin >> a.x >> a.y;
  cin >> b.x >> b.y;

  cout << distanza(a, b) << endl;
}

double distanza(const punto& p1, const punto& p2) {
  return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
  // return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

