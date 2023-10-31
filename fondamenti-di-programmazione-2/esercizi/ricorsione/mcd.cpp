#include <iostream>
using namespace std;

int mcd(int, int);

int main() {
  int x, y;
  cin >> x >> y;

  cout << mcd(x, y) << endl;

  return 0;
}

int mcd(int x, int y) {
  int r = x % y;

  if (r == 0)
    return y;

  return mcd(y, r);
}
