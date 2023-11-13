// Leggere una sequenza di n cifre binarie con n letto da input individuare la
// lunghezza massima della sotto sequenza costituita da cifre uguali

#include <iostream>

int main() {
  int n, curr, charSequenza, lunghezza = 0, lunghezzaMax = 0;

  std::cin >> n;

  if (std::cin >> curr) {
    charSequenza = curr;
    lunghezza = 1;
    --n;
  }

  while (n > 0) {
    if (std::cin >> curr) {
      if (curr == charSequenza) {
        lunghezza += 1;
      } else {
        if (lunghezza > lunghezzaMax)
          lunghezzaMax = lunghezza;

        charSequenza = curr;
        lunghezza = 1;
      }
    } else
      return -1;
    --n;
  }

  std::cout << lunghezzaMax << std::endl;
  return 0;
}
