/* Scrivere una funzione int power(int a, int b) che presi in input due numeri
 * interi positivi a, b ∈ N restituisca ab.
 *
 * Per l’implementazione, si ricordi che:
 * • ab = a · ab−1;
 * • a1 = a;
 * • a0 = 1.
 */

#include <iostream>
using namespace std;

long long int power(int a, int b);

int main() {
  int a, b;
  cin >> a >> b;

  cout << power(a, b) << endl;

  return 0;
}

long long int power(int a, int b) {
  if (b == 1) return a;
  if (b == 0) return b;

  return a * power(a, b - 1);
}
