#include "./common.cpp"

void merge(int[], int, int, int);

void mergeSort(int input[], int start, int end) {
  if (end - start < 20)
    auxiliaryInsertionSort(input, start, end);
  else {
    int middle = (end + start) / 2; // divisione in sotto problemi

    // sotto soluzioni
    mergeSort(input, start, middle);
    mergeSort(input, middle + 1, end);

    merge(input, start, end, middle); // ricombinazione
  }
}

void merge(int input[], int start, int end, int middle) {
  int mergedOutput[end - start];

  int i1 = start, i2 = middle + 1, i3 = 0;

  // i1 è usato per attraversare il primo pezzo da fondere: da start a middle.
  // i2 è usato per attraversare il secondo pezzo da fondere: da middle a end.
  // i3 attraversa l'array parzialmente fuso, ovvero il risultato.

  while (i1 <= middle && i2 <= end) {
    // Determina se il successivo si trova nel primo o nel secondo sotto array
    if (input[i1] < input[i2]) {
      mergedOutput[i3] = input[i1];
      i1++;
    } else {
      mergedOutput[i3] = input[i2];
      i2++;
    }
    i3++;
  }

  // Se il secondo sotto-array è più corto del primo e nel primo sono rimasti
  // elementi da fondere: semplicemente travasali.
  while (i1 <= middle) {
    mergedOutput[i3] = input[i1];
    i1++;
    i3++;
  }

  // Similmente per il secondo.
  while (i2 <= end) {
    mergedOutput[i3] = input[i2];
    i2++;
    i3++;
  }

  // Travasa il risultato completo nell'array di input. Con un approccio
  // diverso questa funzione non sarebbe void e si restituirebbe mergedOutput;
  for (i3 = 0, i1 = start; i1 <= end; i3++, i1++)
    input[i1] = mergedOutput[i3];
}

int main() {
  const unsigned size = 20;
  int inputay[size] = {9,  17, 8,  15, 5, 4, 11, 16, 13, 2,
                       12, 7,  14, 18, 3, 6, 20, 10, 19, 1};

  printArray(inputay, size);
  mergeSort(inputay, 0, size - 1);
  printArray(inputay, size);

  return 0;
}
