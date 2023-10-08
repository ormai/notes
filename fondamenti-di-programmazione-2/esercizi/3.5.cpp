#include <iostream>
#include <string>
using namespace std;

int main() {
  string longer, curr;

  while (cin >> curr)
    longer += curr + ' ';

  cout << longer << endl;

  return 0;
}
