#include <iostream>
using std::cin, std::cout, std::endl;

int compare(const int &a, const int *const &b) {
  // second argument is a reference to a constant pointer to a constant int
  if (a > *b)
    return a;
  return *b;
}

int main() {
  int a, b;
  cout << "a: ";
  cin >> a;
  cout << "b: ";
  cin >> b;

  cout << compare(a, &b) << " is bigger." << endl;
  return 0;
}
