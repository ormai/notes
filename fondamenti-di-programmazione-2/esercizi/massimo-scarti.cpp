/* Massimo con scarti.
 *
 * Leggere un array di dim elementi. Determinare il massimo e stampare l'elenco
 * dei numeri contenuti nell'array ed il relativo scarto dal massimo.
 */

#include <iostream>
using namespace std;

// 1. leggere array
// 2. calcolare il massimo
// 3. stampare gli scarti

void leggi_array(int[], int);
int max(int[], int);
void stampa_scarti(int[], int, int);

int main() {
  int dim;
  cout << "Inserisci la dimensione dell'array" << endl;
  cin >> dim;

  int V[dim];

  leggi_array(V, dim);
  int massimo = max(V, dim);
  stampa_scarti(V, dim, massimo);

  return 0;
}

void leggi_array(int arr[], int dim) {
  cout << "Inserisci un array di " << dim << " elementi" << endl;

  for (int i = 0; i < dim; i++)
    cin >> arr[i];
}


int max(const int arr[], int dim) {
  int result = arr[0];

  // si assume che l'array contenga almeno un elemento
  for (int i = 1; i < dim; i++) {
    if (arr[i] > result)
      result = arr[i];
  }

  return result;
}

void stampa_scarti(const int arr[], int dim, int max) {
  for (int i = 0; i < dim; i++)
    cout << max << ": " << max - arr[i] << ", ";
  cout << endl;
}
