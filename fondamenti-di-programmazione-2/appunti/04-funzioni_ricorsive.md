# 2023-10-02

## Funzioni ricorsive

È una funzione che direttamente (già nel proprio corpo) o indirettamente (tramite una o più funzioni diverse) chiama se stessa.

Quando si progetta una funzione ricorsiva è utile pensarla già funzionante.

```cpp
int fact(int n) {
    if (n == 1 || n == 0)
      return 1; // solo dopo scrivo il caso base

    return n * fact(n - 1); // scrivo prima il return
}
```

Chiamata iniziale a `fact(5)`:
- il caso base è `false`
- restituisce `5 * fact(4)`
    - nuova chiamata a `fact(4)`
        - il caso base è `false`
        - restituisce `4 * fact(3)`
            - nuova chiamata a `fact(3)`
                - il caso base è `false`
                - restituisce `3 * fact(2)`
                    - nuova chiamata a `fact(2)`
                        - il caso base è `false`
                        - restituisce `2 * fact(1)`
                            - nuova chiamata a `fact(1)`
                                - il caso base è `true` (non si arriva alla nuova chiamata di fact)
                            - il valore di ritorno è `1``
                    - il valore di ritorno è `2 * 1`
            - il valore di ritorno è `3 * 2`
    - il valore di ritorno è `4 * 6`
- il valore di ritorno `5 * 24 = 120`

Il risultato è calcolato nella *catena di ritorno*.

A volte una soluzione iterativa è da preferire sull'equivalente ricorsiva. 

---

Trovare il *massimo comun divisore* tra due numeri.

$mcd(x,y) = x$ se $y = 0$
$mcd(x,y) = mcd(y, r)$ se $y>0$ e $x = q * y + r$ ($r$ è il resto della divisione)

```cpp
int mcd(int x, int y) {
    int r = x % y;

    if (r == 0)
        return y;

    return mcd(y, r);
}
```

E se $x < y$? Funziona ancora?

Ad ogni chiamata ricorsiva si *riduce* la dimensione del problema.

La ricorsione in questa funzione avviene linearmente. La funzione di Fibonacci è un esempio di *ricorsione non lineare*, poiché ad ogni esecuzione si hanno più di una chiamata ricorsiva.

## Problema della torre di Hanoi

1. Si può muovere un solo disco per volta
2. Non si può mettere un disco più grande su uno più piccolo.

```
       _          |         |
      |_|         |         |
    _|___|_       |         |
   |_______|  ____|____ ____|____
      from       aux       to
      rod        rod       rod


       |          |         |
       |          |         |
    _______      ___        _
   |_______|  __|___|__ ___|_|___


       |          |         |
       |          _         |
    _______      |_|        |
   |_______|  __|___|__ _________


       |          |         |
       |          |         |
       _         ___     _______
   ___|_|___  __|___|__ |_______|


       |         |         _
       |         |        |_|
       |         |      _|___|_
   ____|____ ____|____ |_______|
```

```cpp
#include <iostream>
using namespace std;

void towerOfHanoi(int, char, char, char);

int main() {
    int n; // numero dischi
    cin >> n;

    towerOfHanoi(n, 'A', 'C', 'B');

    return 0;
}

void towerOfHanoi(int n, char fromRod, char toRod, char auxRod) {
    if (n == 1) {
        cout << "Move disk 1 from " << fromRod << " to " << toRod << endl;
        return;
    }

    towerOfHanoi(n - 1, fromRod, auxRod, toRod);
    // A conterrà solo il disco più grande, C sarà libero

    cout << "Move disk " << n << " from " << fromRod << " to " << toRod << endl;

    towerOfHanoi(n - 1, auxRod, toRod, fromRod);
}
```

## Array built-in

*Contenitori* di oggetti dello stesso tipo.

È una struttura che consente l'accesso diretto ([random access](https://en.wikipedia.org/wiki/Random_access)).

```cpp
tipo nome[dimensione];

// int a[10];
const int a[10]; // const rende impossibile cambiare la dimensione

cout << a[0] << endl; // primo elemento
cout << a[9] << endl; // ultimo elemento
```

```
a    +--------+ 0
     |        |
     +--------+ 1
     |        |
     +--------+ 2
     |        |
     +--------+ 3
     |        |
     +--------+ 4
     |        |
     +--------+ 5
     |        |
     +--------+ 6
     |        |
     +--------+ 7
     |        |
     +--------+ 8
     |        |
     +--------+ 9
```

```cpp
int dim;
cin >> dim;

int a[dim];
```

Inizializzazione:

```cpp
int sz = 5;
int ia1[sz] = {0, 1, 2}; // inizializza solo i primi 3 (bisogna conoscere la dimensione)
```

Non si può leggere tutto un array da input e non si può usare `==` con gli array.

```cpp
const int dim = 10;

int main() {
    int a[dim];

    cout << "Inserisci un valore: " << endl;

    for (int i = 0; i < dim; i++) {
        cin >> a[i];
    }

    cout << "L'array letto è:\n";

    for (int i = 0; i < dim; i++) {
        cout << a[i] << ' ';
    }
}
```

```cpp
for (auto elem: a) {
    // non si conosce la posizione
    cout << elem << endl;
}
```

Come passare un'array ad una funzione:

```cpp
void print(int[]);
void print(int[10]); // non necessario
void print(int*); // indirizzo dell'inizio dell'array
```

Gli array sono sempre passati per riferimento tranne se si passa `const int[]`.

Una funzione non può conoscere la dimensione di un'array. Un modo per risolvere questo problema è passare la dimensione con un parametro apposito alla funzione.

```cpp
void print(const int a[], const unsigned size) {
    for (int i = 0; i < size; ++i) {
        cout << a[i] << ' ';
    }
    cout << endl;
}
```

Controlla se un certo `x` appartiene ad un array

```cpp
bool cerca(const int v[], const int dim, const int x) {
    for (int i = 0; i < dim; ++i) {
        if (v[i] == x)
            return true;
    }

    return false;
}
```
