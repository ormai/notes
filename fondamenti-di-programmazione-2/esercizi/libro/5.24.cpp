#include <iostream>
using std::cin, std::cout, std::endl;

#include <stdexcept>

int main() {
  int a, b;
  cout << "Number to be divided: ";
  cin >> a;
  cout << "Number to divide with: ";
  cin >> b;

  if (!b)
    throw std::invalid_argument("Divisor can not be zero.");

  cout << a << " ÷ " << b << " = " << a / b << endl;

  return 0;
}
