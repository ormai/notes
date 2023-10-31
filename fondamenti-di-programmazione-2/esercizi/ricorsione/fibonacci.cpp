#include <iostream>
using namespace std;

int fib(int);

int main() {
  int n;
  cin >> n;

  cout << fib(n) << endl;

  return 0;
}

int fib(int n) {
  if (n == 1 || n == 0)
    return n;

  return fib(n - 1) + fib(n - 2);
}
