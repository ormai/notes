#include "./common.cpp"

void countingSort(int input[], const unsigned size) {
  // Trova l'elemento più grande in input.
  int max = input[0];
  for (int i = 1; i < size; i++)
    if (input[i] > max)
      max = input[i];

  int count[max + 1], output[size];

  // Inizializza tutti gli elementi di count a 0.
  for (int &i : count)
    i = 0;

  // Conta le occorrenze di ogni chiave in input.
  for (int i = 0; i < size; i++)
    count[input[i]]++;

  /* Trasforma il conto delle frequenze in indici da usare per costruire il
   * nuovo array ordinato. La differenza tra un indice ed il successivo tiene
   * conto delle ripetizioni della rispettiva chiave.
   *
   * Esempio: cont = [1, 1, 3, 3, 5, 9, ...], il terzo elemento c'è due volte.
   */
  for (int i = 1; i <= max; i++)
    count[i] += count[i - 1];

  /* Le chiavi dell'array di input sono usate come indici per accedere agli
   * indici appena calcolati. Tali indici in count sono usati per posizionare le
   * chiavi (input[i]) nelle correte posizioni all'interno dell'array di output,
   * ovvero: count[input[i]] è l'indice calcolato nello scorso loop, ed è usato
   * per accedere ad un elemento di count. Dopo che l'indice contenuto in count
   * è usato, questo viene decrementato, così una stessa chiave sarà posizionata
   * immediatamente a sinistra. Poter gestire correttamente le ripetizioni delle
   * chiavi è il motivo per cui l'operazione è fatta dalla fine all'inizio.
   */
  for (int i = size - 1; i >= 0; i--)
    output[--count[input[i]]] = input[i];

  // Travasa il nuovo array ordinato nell'array di input.
  for (int i = 0; i < size; i++)
    input[i] = output[i];
}

// NB: per 'chiave' si intende il valore numerico di un certo elemento di input.

int main() {
  const unsigned size = 20;
  int array[size] = {12, 1, 19, 15, 4,  2,  10, 18, 7, 5,
                     3,  6, 11, 13, 17, 16, 9,  14, 8, 20};

  printArray(array, size);
  countingSort(array, size);
  printArray(array, size);

  return 0;
}
