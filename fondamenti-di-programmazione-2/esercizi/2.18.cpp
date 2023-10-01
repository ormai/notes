#include <iostream>
using namespace std;

int main() {
  int n = 42;
  int *pn = &n;

  cout << n << '\t' << *pn << '\t' << pn << endl;

  // dereference
  *pn = 86; // n è ora 86
  //
  pn = nullptr; // cambia il valore del ptr

  // cout << n << ' ' << *pn << endl; // da segmentation fault (core dumped)
  cout << n << "\t\t" << pn << endl;

  return 0;
}
