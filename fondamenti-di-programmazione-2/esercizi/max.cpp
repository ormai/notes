#include <iostream>
using namespace std;

int main() {
  int max, n;

  if (cin >> max) {
    while (cin >> n) {
      if (n > max)
        max = n;
    }
    cout << "\nIl massimo è: " << max << endl;
  }

  return 0;
}
