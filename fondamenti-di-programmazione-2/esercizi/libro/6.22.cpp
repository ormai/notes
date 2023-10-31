#include <iostream>
using std::cin, std::cout, std::endl;

void swap(int *const &a, int *const &b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int main() {
  int a, b;
  cout << "a: ";
  cin >> a;
  cout << "b: ";
  cin >> b;

  swap(&a, &b);

  cout << "a: " << a << ", b: " << b << endl;
  return 0;
}
