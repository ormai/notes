# 2023-09-27

Esiste un legame tra struct e classi.

`struct` serve a definire tipi personalizzati (o concetti).

```cpp
struct punto {
    int x;
    int y;
};
```

```cpp
#include <iostream>
#include <cmath>
using namespace::std;

int main() {
    punto p1, p2;

    double distanza;

    cin >> p1.x >> p1.y;
    cin >> p2.x >> p2.y;
    distanza = sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
    cout << distanza << endl;

    return 0;
}
```

```cpp
punto p1; p1.x = 3; p1.y = 4;
punto *pp1 = &p1;
cout << (*pp1).x << (*pp1).y << endl; // prima la deferenziozione e poi l'accesso a x
cout << pp1->x << pp2->y << endl; // alternativa
```

## Cicli

```cpp
while ( /* condizione */ ) { /* istruzioni */ }
```

Almeno una volta il corpo viene eseguito:

```cpp
do { /* istruzioni */ } while ( /* condizione */ )
```

```cpp
for (/* inizializzazione */; /* controllo */ ; /* aggiornamento */) { /* istruzioni */ }
```

```cpp
int main() {
    int sum = 0, val = 1;
    while (val <= 10) {
        sum += val;
        ++val;
    }
    cout << sum << endl;
    return 0;
}
```

```cpp
do {
    sum += val;
    ++val;
} while (val <= 10);
```

```cpp
for (int val = 1, val <= 10; ++val) {
    sum += val;
}
cout << sum << endl;
```

```cpp
// leggere un numero indefinito di interi
int main() {
    int sum = 0, val = 0;

    while (cin >> val)
        sum += val;

    cout << sum;
    return 0;
}
```

## Controllo condizionale

```cpp
if ( /* condizione */ ) { /* istruzioni */ }

if ( /* condizione */ ) { /* istruzioni */ } else { /* istruzioni */ }

if ( /* condizione */ ) /* singola istruzione */;
```

## Funzioni

```cpp
int // tipo di ritorno
main // nome
(int v1, int v2) // parametri (questi sono formali, quelli usati all'interno delle funzioni sono attuali)
{} // corpo
```

I tipi di ritorno possono essere tutti i tipi base (`int`, `char`, `bool`, ...), i tipi composti (ptr e ref), e quelli definiti tramite `struct`. In più si può usare `void`.

### Passaggio di parametri

- per valore
    ```cpp
    f(10)
    ```
- per riferimento (la funzione usa una **copia** del valore passato)
    ```cpp
    f(x)
    ```
- per riferimento costante (il valore usato nella funzione è un alias di quello passato. Il valore originale cambia)
    ```cpp
    f(&x)
    ```

    ```cpp
    const int val = 38;
    f(&x) // se si prova a cambiare x nella funzione si produce un errore.
    ```

    ```cpp
    void reset(int &i) {
        i = 0;
    }

    int main() {
        int x;
        cin >> x;
        reset(x);
    }
    ```
