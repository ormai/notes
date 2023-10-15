#include "./common.cpp"

int partition(int[], int, int);

void quickSort(int input[], int start, int end) {
  if (end - start < 20)
    auxiliaryInsertionSort(input, start, end);
  else {
    int pivot = partition(input, start, end); // divisione in sotto problemi

    // calcolo delle sotto soluzione
    quickSort(input, start, pivot - 1); // elementi minori di pivot
    quickSort(input, pivot + 1, end); // elementi maggiori di pivot

    // non è necessario fare alcuna ricombinazione
  }
}

/* È necessario inferire un pivot che possa partizionare l'array in due sotto
 * array con un numero di elementi più simile possibile.
 */
int partition(int input[], int start, int end) {
  int i = start, j = end + 1;

  while (i < j) { // finché non si incontrano
    do
      j--;
    while (input[start] < input[j]);
    // input[start] >= input[j]
    // input[j] < input[start]

    do
      i++;
    while (input[start] >= input[i] && i < j);
    // input[i] >= input[start]
    // input[start] < input[i]

    if (i < j)
      swap(input[i], input[j]);

    swap(input[start], input[j]);
  }

  return j;
}

int main() {
  const unsigned size = 40;
  int array[size] = {8, 10, 11, 18, 17, 12, 14, 6,  4,  15,
                     9, 5,  19, 3,  20, 2,  7,  13, 16, 1,
                     8, 10, 11, 18, 17, 12, 14, 6,  4,  15,
                     9, 5,  19, 3,  20, 2,  7,  13, 16, 1};

  printArray(array, size);
  quickSort(array, 0, size - 1);
  printArray(array, size);

  return 0;
}
