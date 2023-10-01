/* Dati due numeri interi positivi c, a ∈ N, il logaritmo intero di c in base a
 * è un numero b ∈ N tale che c = ab. Scrivere una funzione con segnatura
 * int log_int(int c, int a) che calcoli il logaritmo intero di c in base a, o
 * restituisca −1 se non esiste.
 */

#include <iostream>
using namespace std;

int log_int(int, int);

int main() {
  int c, a;
  cin >> c >> a;

  cout << log_int(c, a) << endl;

  return 0;
}

int log_int(int c, int a) { // b = log_a c
  int b = 0, prodottoParziale = 1;

  // b conta quante volte bisogna moltiplicare a per se stessa finché non si
  // ottiene c (o non lo si supera)

  while (prodottoParziale < c) {
    prodottoParziale *= a; 
    ++b;
  }

  if (prodottoParziale == c)
    return b;

  return -1;
}
