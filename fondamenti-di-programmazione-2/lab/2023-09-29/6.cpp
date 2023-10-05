/* Scrivere un programma in C++ che presa in input una sequenza x1, . . . , xk
 * di numeri interi positivi, terminata da un numero negativo, stampi il suo
 * istogramma (vedi esempio). In particolare, l’i-esima riga in output
 * consisterà in xi asterischi consecutivi.
 *
 * Esempio: Consideriamo la sequenza 4, 5, 3, 2, 8, -1. Il suo istogramma è:
 * ****
 * *****
 * ***
 * **
 * ********
 */

#include <iostream>
using namespace std;

int main() {
  int x;

  while (cin >> x && x > 0) {
    for (int i = 0; i < x; ++i) {
      cout << '*';
    }
    cout << endl;
  }

  return 0;
}
