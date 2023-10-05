# 2023-10-05

Continuazione di [memoria dinamica](05-array_multidimensionali-gestione_dinamica_della_memoria.md).

```cpp
const int capacity = 10;
int *elenco = new int[capacity]; // crea un array di 10 interi
delete [] elenco;
```

Per avere un'array più grande di `capacity`:

1. creare un nuovo array vuoto con `new` con la nuova dimensione
2. ricopiare il contenuto vecchio array nel nuovo spazio
3. eliminare il vecchio array con `delete`

```cpp
const int dimBase = 10;

void resize(int *&, int &, int);

int main() {
    int capacity = dimBase;
    int *elenco = new int[capacity];
    int size = 0, elem;

    while (cin >> elem) {
        if (size < capacity)
            elenco[size++] = elem;
        else {
            resize(elenco, capacity, dimBase);
            elenco[size + 1] = elem;
        }
    }
    stampaArray(elenco, size);
    return 0;
}

void resize(int *&v, int &capacity, int increment) {
    // v è un puntatore ad intero passato per riferimento
    int *tmp = new int[capacity + increment]; // (1)

    for (int i = 0; i < capacity; i++) // (2)
        tmp[i] = v[i];

    delete [] v; // (3)

    v = tmp;

    capacity += increment
}
```

## Stringhe (C style)

```cpp
char str[n] = {'c', '+', '+', '\0'};
char *pstr = new char[10];
cin >> pstr; // lo spazio è interpretato come separatore
```

```cpp
#include <cstring>

int lunghezza = strlen(s);
int sonoUguali = strcmp(s1, s2);

if (str1 < str2); // in senso lessicografico

char concat[strlen(p1) + strlen(p2)] = strcat(p1, p2);

strcpy(p1, p2); // copia p2 in p1
```
