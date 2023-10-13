# 2023-10-11

## Ordinamento

Ordinamento di array
- *in loco*
    - bubble sort
    - selection sort
    - insertion sort
- fanno uso di nuova memoria
    - counting sort

```cpp
void bubbleSort(int arr[], int size) {
    bool swaps;
    int x = size, lastSwap;

    do {
        swaps = false;
        for (int i = 0; i < x - 1; i++) {
            if (a[i] > arr[i + 1]) {
                int tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;

                swaps = true;
                lastSwap = i + 1;
            }
            x = lastSwap;
        }
    } while (swaps);
}
```

Caso migliore $O(n)$, caso peggiore $O(n^2)$

---

```cpp
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min = i;
        for (int j = i + 1; j < size; j++)
            if (arr[j] < arr[min])
                min = j;

        int tmp = arr[min];
        arr[min] = arr[i];
        arr[i] = tmp;
    }
}
```

Caso migliore $O(n^2)$, caso peggiore $O(n^2)$

Il selectionSort fa $n$ scambi in meno per ogni $n$ rispetto al bubbleSort.

---

```cpp
void insertionSort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int tmp = arr[i], j = i - 1;

        while ((j >= 0) && (arr[j] > tmp)) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = tmp;
    }
}
```

Caso migliore $O(n)$, caso peggiore $O(n^2)$

---

$arr[i] \in \{0, \ldots, k\}$ 

Usare il valore degli elementi di `arr` come indici di un nuovo array.

Fase 1: $O(n)$
Fase 2: $O(n + k)$ dove $k$ è il valore più grande.

La complessità dipende principalmente da $k$.

---

## Divide et impera

```
se problema "piccolo"
    risolvi direttamente
altrimenti
    dividi il problema in sotto problemi (divisione)
    risolvi i sottoproblemi              (soluzione)
    ricombina sotto soluzioni            (ricombinazione)
```

# Merge sort

```cpp
void mergeSort(int arr[], int inizio, int fine) {
    if (fine - inizio < 20) 
        insertionSort(arr, inizio, fine);
    else {
        int medio = fine + inizio / 2; // divisione in sotto problemi

        // sotto soluzioni
        mergeSort(arr, inizio, medio);
        mergeSort(arr, medio + 1, fine);

        merge(arr, inizio, fine, medio); // ricombinazione
    }
}

void merge(int arr, int inizio, int fine, int medio) {
    int A[fine - inizio];

    int i1 = inizio, i2 = medio + 1, i3 = 0;

    while ((i1 <= medio) && (i2 <= fined)) {
        if (arr[i1] < arr[i2]) {
            A[i3] = V[i1];
            i1++;
        } else {
            A[i3] = arr[i2];
            i2++;
        }
        i3++;
    } 

    while (i1 <= medio) {
        A[i3] = arr[i1];
        i1++;
        i3++;
    }

    while (i1 <= fin) {
        A[i3] = arr[i2];
        i2++;
        i3++;
    }

    for (i3 = 0, i1 = inizio; i1 <= fine; i3++, i1++)
        arr[i1] = A[i3];
}
```
