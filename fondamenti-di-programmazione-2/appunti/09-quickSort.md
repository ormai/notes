# 2023-10-12

## Quick sort

Caso peggiore $O(n^2)$: l'array è già ordinato, oppure l'*elemento di partizione* è scelto male.
Caso medio $O(n \log n)$

```cpp
void quickSort(int arr[], int inizio, int fine) {
    if (fine - inizio < 20)
        insertionSort(arr, inizio, fine);
    else {
        int posOrd = partiziona(arr, inizio, fine); // divisione

        // calcolo delle sotto soluzione
        quickSort(arr, inizio, posOrd - 1);
        quickSort(arr, posOrd + 1, fine);

        // non è necessario fare alcuna ricombinazione
    }
}

int partizione(int arr[], int inizio, int fine) {
    int i = inizio, j = fine + 1;

    while (i < j) {
        do
            j++;
        while (arr[inizio] < arr[j]);

        do
            i++;
        while (arr[inizio] >= arr[i] && i < j);

        if (i < j)
            scambia(arr[i], arr[j]);

        scambia(arr[inizio], arr[j]);

        return j;
    }
}
```
