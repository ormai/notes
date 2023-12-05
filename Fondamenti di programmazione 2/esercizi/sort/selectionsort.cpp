#include "./common.cpp"

int getIndexOfMinimum(int[], int, int);

/* L'input viene diviso in due. A sinistra dell'elemento corrente vi è l'array
 * parzialmente ordinato. A destra il resto dell'array disordinato.
 *
 * Passando da sinistra a destra, l'elemento corrente viene scambiato con
 * l'elemento più piccolo della parte disordinata della lista.
 *
 * In questo modo il primo elemento a sinistra diventa l'elemento più piccolo
 * dell'array. Segue il secondo elemento più piccolo, poi il terzo elemento più
 * piccolo e così via. */
void selectionSort(int input[], const unsigned size) {
  for (unsigned i = 0; i < size - 1; ++i)
    swap(input[getIndexOfMinimum(input, i, size)], input[i]);
}

/* @return indice dell'elemento più piccolo compresto tra start (incluso e
 * end (elscuso.) */
int getIndexOfMinimum(int input[], int start, int end) {
  int min = start;
  for (int i = start + 1; i < end; ++i)
    if (input[i] < input[min])
      min = i;
  return min;
}

int main() {
  constexpr unsigned size = 20;
  int array[size] = {6, 10, 8, 20, 12, 9, 15, 14, 2,  13,
                     1, 4,  7, 17, 18, 5, 16, 3,  11, 19};

  printArray(array, size);
  selectionSort(array, size);
  printArray(array, size);
  return 0;
}
