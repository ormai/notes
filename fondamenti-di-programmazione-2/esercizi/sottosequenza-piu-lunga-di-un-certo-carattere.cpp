// Leggere una sequenza di n cifre binarie con n letto da input individuare la
// lunghezza massima della sottosequenza costituita da cifre uguali

#include <iostream>
using namespace std;

int main() {
  int n, curr, charSequenza, lunghezza = 0, lunghezzaMax = 0;

  cin >> n;

  if (cin >> curr) {
    charSequenza = curr;
    lunghezza = 1;
    --n;
  }

  while (n > 0) {
    if (cin >> curr) {
      if (curr == charSequenza) {
        lunghezza += 1;
      } else {
        if (lunghezza > lunghezzaMax)
          lunghezzaMax = lunghezza;

        charSequenza = curr;
        lunghezza = 1;
      }
    } else return -1;
    --n;
  }

  cout << lunghezzaMax << endl;
  return 0;
}
