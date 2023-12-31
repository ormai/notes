/* Letta una sequenza di numeri terminata da -1 e lunga più di 100.
 * memorizzarla opportunamente in un array e compattare l'array, cioè eliminare
 * tutti i numeri duplicati ed eliminare i buchi così generati spostando a
 * sinistra i valori rimanenti. */

#include <iostream>

void printArr(const int[], const int);
void compactArr(int[], int &);

int main() {
  const int maxDim = 200;
  int arr[maxDim], tmp, size = 0;

  while (std::cin >> tmp && tmp != -1 && size <= maxDim)
    arr[size++] = tmp;

  printArr(arr, size);
  compactArr(arr, size);
  printArr(arr, size);
  return 0;
}

void compactArr(int arr[], int &size) {
  for (unsigned i = 0; i < size; ++i)
    for (unsigned j = i + 1; j < size; ++j)
      if (arr[i] == arr[j]) {
        for (int k = j; k < size - 1; ++k) // sposta tutto indietro di un posto
          arr[k] = arr[k + 1];
        arr[size-- - 1] = 0; // reimposta l'ultimo elemento a 0
      }
}

void printArr(const int arr[], const int size) {
  for (unsigned i = 0; i < size; ++i)
    std::cout << arr[i] << ' ';
  std::cout << std::endl;
}
