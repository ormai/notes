#include "./common.cpp"

/* Ad ogni iterazione input[i] è copiato in current. Ogni elemento a sinistra
 * di current che è più grande viene spostato a destra di uno. Ora il vecchio
 * current è stato sostituito nell'array ed è stato trovato un posto in cui
 * l'elemento a sinistra non è più grande di current. Qui viene copiato current.
 */
void insertionSort(int input[], const unsigned size) {
  for (int i = 0; i < size; i++) {
    int current = input[i], j = i - 1;

    while (j >= 0 && input[j] > current) {
      input[j + 1] = input[j];
      j--;
    }

    /* Se non si entra nel while e quindi se j non cambia, si ha che
     * input[j + 1] = input[i] = current e quindi si assegna lo stesso
     * elemento a se stesso. */
    input[j + 1] = current;
  }
}

int main() {
  constexpr unsigned size = 20;
  int array[size] = {12, 20, 13, 16, 4,  18, 17, 2, 3, 9,
                     10, 19, 15, 6,  11, 8,  14, 1, 7, 5};

  printArray(array, size);
  insertionSort(array, size);
  printArray(array, size);
  return 0;
}
