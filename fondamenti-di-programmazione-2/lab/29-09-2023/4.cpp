/* Implementare due funzioni con segnatura int somma(int x, int y) e int
 * prodotto(int x, int y) che presi in input due numeri interi x, y ∈ N
 * calcolino rispettivamente x + y e x · y.
 *
 * L’implementazione della funzione prodotto dovrà fare uso nella sua
 * definizione della funzione somma: 3 · 5 = 3 + 3 + 3 + 3 + 3 = 5 + 5 + 5.
 *
 */

#include <iostream>
using namespace std;

int somma(int, int);
int prodotto(int, int);

int main() {
  int x, y;
  cin >> x >> y;

  cout << somma(x, y) << '\n'
       << prodotto(x, y) << endl;

  return 0;
}

int somma(int x, int y) {
  return x + y;
}

int prodotto(int x, int y) {
  int sum = 0;
  for (int i = 0; i < y; ++i) {
    sum += x;
  }
  return sum;
}
