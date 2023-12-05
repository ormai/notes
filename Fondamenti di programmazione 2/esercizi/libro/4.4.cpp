#include <iostream>
using std::cout, std::endl;

int main() {
  int exp = 12 / 3 * 4 + 5 * 15 + 24 % 4 / 2;
  int expParenthesized = ((((12 / 3) * 4) + (5 * 15)) + ((24 % 4) / 2));

  cout << exp << endl;
  cout << expParenthesized << endl;

  return 0;
}
