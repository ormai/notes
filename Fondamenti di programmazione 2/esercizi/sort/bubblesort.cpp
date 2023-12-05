#include "./common.cpp"

/* Ad ogni passata si confronta ogni elemento con il suo successivo,
 * scambiandoli se il primo è maggiore del secondo.
 *
 * Si ferma dopo una passata in cui non sono avvenuti scambi. */
void bubbleSort(int input[], const unsigned size) {
  bool swapped;
  int upperLimit = size;

  do {
    swapped = false;

    /* Al termine del ciclo for l'elemento più grande dell'array si troverà
     * nell'ultima posizione. Nell'iterazione successiva il secondo-massimo
     * verrà spostato nella penultima posizione. E così via.
     *
     * Ad ogni iterazione un elemento viene spostato nella posizione giusta,
     * nella parte finale dell'array. Quindi c'è un elemento in meno da
     * ordinare. Per questo si decrementa upperLimit. */
    for (int i = 0; i < upperLimit - 1; i++)
      if (input[i] > input[i + 1]) {
        swap(input[i], input[i + 1]);
        swapped = true;
      }

    upperLimit--;
  } while (swapped);
}

int main() {
  constexpr unsigned size = 20;
  int array[size] = {4, 2,  12, 9,  16, 14, 15, 11, 19, 8,
                     5, 13, 1,  10, 3,  17, 18, 20, 7,  6};

  printArray(array, size);
  bubbleSort(array, size);
  printArray(array, size);
  return 0;
}
