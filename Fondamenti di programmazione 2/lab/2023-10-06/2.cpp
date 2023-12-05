/* Scrivere una funzione in C++ che calcoli la somma degli elementi in un
 * array, utilizzando la ricorsione.
 *
 * Suggerimento: Utilizzare la seguente segnatura per la funzione:
 *
 * int somma_rec(int a[], int n, int i, int s)
 *
 * dove n è la lunghezza dell’array a, s è la somma del sotto-array a[0..i] ad
 * ogni chiamata ricorsiva. La prima invocazione della funzione dovrà avvenire
 * come somma_rec(a, n, 0, 0).
 */

#include <iostream>
using namespace std;

int somma_rec(int[], const unsigned, int, int);
int sommaRicorsivaAlternativa(int[], const unsigned, int);

int main() {
  const unsigned size = 10;
  int arr[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  cout << somma_rec(arr, size, 0, 0) << endl;
  // cout << sommaRicorsivaAlternativa(arr, size, 0) << endl;

  return 0;
}

int somma_rec(int a[], const unsigned n, int i, int s) {
  if (i >= n)
    return s;

  return somma_rec(a, n, i + 1, s + a[i]);
}

int sommaRicorsivaAlternativa(int a[], const unsigned n, int i) {
  if (i == n - 1)
    return a[i];

  return a[i] + sommaRicorsivaAlternativa(a, n, i + 1);
}
