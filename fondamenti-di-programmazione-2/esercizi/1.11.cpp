// Exercise 1.11: Write a program that prompts the user for two integers.
// Print each number in the range specified by those two integers.

#include <iostream>
using namespace std;

int main() {
  int n1, n2;
  if (cin >> n1 && cin >> n2) {
    while (n1 < n2) {
      cout << n1++ << endl;
    }
  }
  return 0;
}
