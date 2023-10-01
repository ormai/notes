# 2023-09-25

Un programma è composto da un insieme di funzioni

```c++
int main() {
    // corpo
    return 0;
}
```

Non usiamo parametri e valori di ritorno in questo corso (se non 0).

Usiamo la versione **c++ 11**. Il compilatore è `g++`.

```bash
g++ -std=c++11 programma.cpp -o programma_compilato
```

## Stream di input output

Scrivere in output:

```c++
#include <iostream>

int main() {
    std::cout <<  "Inserire due interi" << std::endl; // scrive in output

    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2; // legge da input

    std::cout << "La somma di " << v1 << " e " << v2 << " è " << v1 + v2 << std:endl;

    return 0;
}
```

- `#include` è una direttiva per il compilatore.
    (Esiste un `PATH` per tutte le librerie).
- `cout` non è un'istruzione ma uno stream o buffer di dati^[https://en.wikipedia.org/wiki/Data_buffer]
- `std` imposta lo scope (o namespace ?)
- `<<` è un operatore che indirizza lo stream

Per evitare di scrivere `std` ogni volta usare la direttiva `using namespace::std;`

```c++
#include <iostream>
using namespace::std;

int main() {
    cout <<  "Inserire due interi" << endl; // scrive in output

    int v1 = 0, v2 = 0;
    cin >> v1 >> v2; // legge da input

    cout << "La somma di " << v1 << " e " << v2 << " è " << v1 + v2 << endl;

    return 0;
}
```

## Variabili

Tipi:

- int
    - short int
    - long int
    - long long int
    - ...
- unsigned int
- float
- double
- char
- bool

`int i1;` è meglio non fare assunzioni sul valore di `i1`. È sempre meglio inizializzare una variabile se il valore iniziale è importante: `int i1 = 0;`

```c++
bool b = true;
bool c = false;
```

I bool occupano sempre un byte anche se usano un solo bit.

Modi per inizializzare una variabile
- `int n = 0;`
- `int n{0};` list initialization
- `int n = {0};` idem con `=`
- `int u(0);` per gli oggetti

```c++
bool i = 42; // è true perché solo 0 è false, mentre tutto il resto true
int j = i; // i non conterrà 42 ma 1
int k = 3.14; // k sarà 3
float pi = k; // pi sarà solo 3 perché il .14 è stato perso
```

## Visibilità delle variabili (scope)

- global scope
    ```c++
    #include <iostream>
    using namespace::std;

    const int reused = 42; // globale
    // const per impedire di modificarla

    int main() {
        int unique = 0
        cout << reused << " " << unique << endl;

        int reused = 0; // crea una nuova variabile locale
        cout << reused << " " << unique << endl;
        cout << ::reused << endl // per accedere alla variabile globale
    }
    ```

## Caratteri speciali

- `\n` 
- `\t`
- `\\`

## Tipo auto

Il compilatore cerca di capire di che tipo è la variabile.

`auto i;` non va bene perché non c'è modo di individuare il tipo.
`auto i = 0;` i è interpreta come `int`
`auto val = val1 + val2;` val assume il tipo del risultato della somma.

## Operatori

- `>>` opera su uno *stream*.
- `++` opera sugli interi. Può essere applicato prima o dopo (prefix o postfix).
    ```cpp
    int i = 9;
    cout << i++ << endl; // 9
    cout << ++i << endl; // 11
    ```
- `!`
    ```cpp
    bool b1 = true, b2 = !b1; // b2 sarà false
    ```
- `&` and (meglio &&)
- `|` or (meglio ||)
    ```cpp
    if (x & y & z) {} // valuta tutto
    if (x && y && z) {} // se x o y è falso si ferma e non valuta z
    ```

## Compound types

- riferimenti
    ```cpp
    int val = 1024;
    int &refval = val; // alias, non un nuova variabile

    refval = 2; // val diventa 2 e quindi anche refval

    int i = refval; // i = val = refval
    ```
- puntatori (pointers)
    ```cpp
    int *ip1, *ip2; // int qui è riferito a ciò a cui puntano ip1 e ip2

    double dp, *dp2;

    int val = 42;
    int *p = &val; // p conterrà l'indirizzo di val in memoria

    cout << p << endl; // stampa l'indirizzo
    cout << *p << endl; // stampa 42 contenuto nella cella di memoria a cui punta *p
    // quest'ultima è detta dereferenziazione
    ```

Un puntatore può
- puntare ad un oggetto
- puntare immediatamente dopo l'oggetto
- valore nullo (null pointer)
    ```cpp
    int *x1 = nullptr;
    ```
