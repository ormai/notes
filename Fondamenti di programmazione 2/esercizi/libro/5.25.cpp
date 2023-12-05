#include <iostream>
using std::cin, std::cout, std::endl;

#include <stdexcept>
using std::invalid_argument;

int main() {
  int a, b;
  cout << "Number to be divided: ";
  cin >> a;

  try {
    cout << "Number to divide with: ";
    cin >> b;
    if (!b)
      throw invalid_argument("Divisor can not be zero.");

    cout << "came back" << endl;
  } catch (invalid_argument e) {
    cout << e.what() << endl;
    cout << "Number to divide with: ";
    cin >> b;
    // if the user puts 0 again?
  }

  cout << a << " ÷ " << b << " = " << a / b << endl;

  return 0;
}
