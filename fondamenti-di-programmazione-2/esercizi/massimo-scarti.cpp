/* Massimo con scarti.
 *
 * Leggere un array di dim elementi. Determinare il massimo e stampare l'elenco
 * dei numeri contenuti nell'array ed il relativo scarto dal massimo. */

#include <iostream>

// 1. leggere array
// 2. calcolare il massimo
// 3. stampare gli scarti

void readArray(int[], const unsigned);
int max(const int[], const unsigned);
void scarti(const int[], const unsigned, const int);

int main() {
  unsigned size;
  std::cout << "Dimensione: ";
  std::cin >> size;

  int arr[size];
  readArray(arr, size);
  scarti(arr, size, max(arr, size));
  return 0;
}

void readArray(int arr[], const unsigned size) {
  std::cout << "Inserisci un array di " << size << " elementi:" << std::endl;
  for (unsigned i = 0; i < size; ++i)
    std::cin >> arr[i];
}

int max(const int arr[], const unsigned dim) {
  int result = arr[0];
  for (int i = 1; i < dim; ++i)
    if (arr[i] > result)
      result = arr[i];
  return result;
}

void scarti(const int arr[], const unsigned size, const int max) {
  for (unsigned i = 0; i < size; ++i)
    std::cout << max << ": " << max - arr[i] << ", ";
  std::cout << std::endl;
}
