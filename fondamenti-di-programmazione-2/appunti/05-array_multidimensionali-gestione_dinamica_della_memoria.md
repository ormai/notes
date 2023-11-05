# 2023-10-04

Array multidimensionali: array che contengono array.

```cpp
int arr[3][4]; // tre righe e quattro colonne
int arr2[10][20][30]; // array tridimensionale
```

Inizializzazione:

```cpp
int arr[3][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}};
int arr[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}; // meno chiaro
```

Accesso:

```cpp
std::cout << arr[i][j];
```

Passaggio di array multidimensionali alle funzioni:

```cpp
const int dimRow;
const int dimCol;

void print(int arr[][dimCol], int dimRow, int dimCol) {
    for (int i = 0; i < dimRow; i++) {
        for (int j = 0; j < dimCol, j++)
            cout << arr[i][j] << ' ';
        cout << endl;
    }
}
```

```cpp
// bisogna specificare la dimensione dalla seconda in avanti
void print(int arr[][dimDue][dimTre], int dimRow, int dimCol);
```

## Puntatori ed array

Il nome di un array è, in realtà, l'indirizzo del suo primo elemento.

```cpp
int arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
auto arr2 = arr; // arr2 è un puntatore: int *arr2 = &arr;
int *p = arr; // si inizializza p con l'indirizzo di arr
arr2 = 42; // non si può

cout << arr2 << endl; // stampa un indirizzo: 0x...
cout << *arr2 << endl; // stampa 0

cout << arr2[1] << endl; // stampa 1
// vai all'indirizzo di arr2 più un offset pari a 1 per la dimensione di int (4)

arr2++; // indirizzo dell'oggetto che segue arr2. Effettivamente 4 byte dopo arr2
cout << *arr2 << endl; // stampa 1
arr2[-1] // per poter accedere nuovamente a 0
```

Funzioni incluse in c++ (restituiscono puntatori):

```cpp
begin(arr) // restituisce l'indirizzo della prima cella di arr
end(arr) // restituisce l'indirizzo dell'ultima cella di arr
```

sono degli iteratori.

```cpp
// differenza di puntatori
auto n = end(arr) - begin(arr); // numero di oggetti che arr contiene (lunghezza)
// il tipo di n sarà int o unsigned?
```

```cpp
int *first = begin(ia);
int *last = end(ia);

while (beg != last) {
    cout << *first << endl;
    first++;
}
```

```cpp
while (first != last && *first >= 0) {
    ++first
}
// intera attraverso l'array finché non lo attraverso tutto oppure trova un elemento negativo.
```

## Puntatori: gestione dinamica della memoria

```cpp
int x = 0;
```

Crea un nuovo spazio in memoria. Non si ha una variabile con con nome, ma vi si accede tramite il puntatore

```cpp
int *p = new int; // definizione
int *p = new int = 3; // definizione & inizializzazione
```

```
       memoria
      |       |
x --> +-------+
      |       |
      +-------+
      |       |
      :       :
      |       |
pi -> +-------+   ---+
      |       |      |
      +-------+      |
      |       |      |
      :       :      |
      |       |      |
      +-------+   <--+
      |       |
      +-------+
```

```cpp
delete pi; // distrugge l'oggetto a cui pi punta, ma pi resta indefinito
```

([doc](https://devdocs.io/cpp/language/delete))

```cpp
int i, *pi1 = &i, *pi2 = nullptr;
double *pd = new double(33), *pd2 = pd;

delete i; // non si può fare perché è un intero e non è stato creato con new
delete pi1; // comportamento indefinito perché punta ad una normale intero
delete pd; // ok cancella 33 dalla memoria
delete pd2; // pd2 ora punta a qualcosa di indefinito. Il risultato dell'istruzione è indefinito
delete pi2; // cancella nullptr
```

```cpp
const int capacity = 10;
int *elenco = new int[capacity]; // crea un array di 10 interi
delete [] elenco;
```
