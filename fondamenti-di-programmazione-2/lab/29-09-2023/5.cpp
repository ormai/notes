/* Scrivere una funzione che preso in input un numero intero positivo n, stampi
 * i primi n numeri della sequenza di Fibonacci.
 *
 * La sequenza di Fibonacci è così definita, dove F(i) denota l’i-esimo numero
 * della sequenza:
 * • F(0) = 0;
 * • F(1) = 1;
 * • Per n > 1, F(n) = F(n − 1) + F(n − 2).
 */

#include <iostream>
using namespace std;

long long int fibonacci(int);

int main() {
  int n;
  cin >> n;

  cout << fibonacci(n) << endl;

  return 0;
}

long long int fibonacci(int n) {
  if (n == 0) return 0;
  if (n == 1) return 1;

  return fibonacci(n - 1) + fibonacci(n - 2);
}
