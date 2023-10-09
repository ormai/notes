# 2023-10-09

## Complessità computazionale

Il tempo di esecuzione dipende dall'hardware e dall'input dato all'algoritmo.

Esempio:
una istruzione $10^{-6} s$

| Operazioni | $n = 10$ | $n = 10000$ | $n=10^6$ |
| - | - | -  | - |
| $n$ | $10^{-5} s$ | $10^{-2}$ | $1 s$ |
| $n^2$ | $10^{-3} s = 0.1 ms$ | $100 s$ | $10^6 s$ |
| $n\log n$ | $0.0003 s$ | $0.13 s$ | $19 s$ |

### Modello di costo

- Dimensione dell'input ($n$)
- Operazioni di costo unitario (definire cosa costa *uno*)
    - lettura, scrittura (i/o)
    - assegnamento, operazioni aritmetiche, `return` (e combinazioni di queste)
    - accesso ad elementi di array (a prescindere dalla loro dimensione)
    - valutazione di espressioni booleane (`if ((b1 && b2) || (!b4))`)

```cpp
i = 1; 
while (i <= n) // n è la dimensione dell'input
    i = i + 1;
```
- $1$ assegnamento esterno
- $n + 1$ valutazioni
- $n \times 1$ assegnamenti interni
- tot: $2n + 2$

---

```cpp
i = 1; 
while (i <= n) {// n è la dimensione dell'input
    i = i + 1;
    j = j + 3 + 42;
}
```

- $1$
- $n + 1$
- $n * 2$
- tot: $3n + 2$

---

```cpp
i = 1; 
while (i <= 2 * n) // n è la dimensione dell'input
    j = j + 3 + 42;
```

- $1$
- $2n + 1$
- $2n$
- tot: $4n + 2$

---

```cpp
i = 1; 
while (i * i <= n) // n è la dimensione dell'input
    i = i + 1;
```
- $1$
- $\sqrt n + 1$
- $\sqrt n$
- tot: $2\sqrt n + 2$

---

```cpp
i = 0;
while ( i <= 13 && A[i] != 8)
    i = i + 1
```

- caso peggiore
- caso medio
- caso migliore

### Notazione asintotica

$f(n) \in O(g(n))$ se $\exists\ c, n_0 : 0 \leq  f(n) \leq c\cdot g(n)\ \forall n\leq n_0$

- $O(n)$ andamento lineare
- $O(\log n)$ andamento logaritmico
- $O(n^2)$ andamento polinomiale
- $O(2^n)$ andamento esponenziale
- $O(1)$, $O(c)$, andamento costante

---

- istruzioni $O(1)$
- blocchi $\max O(f_i)$
- costrutti selettivi
    ```cpp
    if ( /* condizione */ ) { // f(cond)
        /* blocco if */       // f(if)
    } else {
        /* blocco else */     // f(else)
    }
    ```
    $f(cond) + f(if)$ o $f(cond) + f(else)$
- cicli $O(kmax + (f(cond) + f(corpo)))$
- funzioni
    - parametri
    - corpo
    - `return`

```cpp
void stampaStelle(int ns) {
    for (int i = 0; i < ns; i++)
        cout << '*';
    cout << endl;
}
```

$O(ns)$ il resto si trascura.

```cpp
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        stampaStelle(n);

    return 0;
}
```

$O(n^2)$ in totale

---

```cpp
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        stampaStelle(i);

    return 0;
}
```

iterazioni: 1 + 2 + 3 + 4 + 5 + n

$\displaystyle \sum_{i=0}^n i = \cfrac{n(n+1)}{2}=\cfrac{n^2}{2}+\cfrac n2$

Quindi $O(n^2)$ andamento quadratico.

### Problemi di ricerca di un elemento in un insieme

```cpp
bool ricercaLineare(int insieme[], int x, int n) {
    bool trovato = false,
    for (int i = 0; i < n; i++) {
        if (insieme[i] == x)
            trovato = true;
    }
    return trovato;
}
```

Versione 1: caso peggiore $O(n)$, caso migliore $O(n)$

```cpp
bool ricercaLineare(int insieme[], int x, int n) {
    bool trovato = false,
    for (int i = 0; i < n && !trovato; i++) {
        if (insieme[i] == x)
            trovato = true;
    }
    return trovato;
}
```

Versione 2: caso peggiore $O(n)$, caso migliore $O(1)$

```cpp
bool ricercaLineare(int insieme[], int x, int n) {
    bool trovato = false,
    for (int i = 0; i < n && !trovato && insieme[i] <= x; i++) {
        if (insieme[i] == x)
            trovato = true;
    }
    return trovato;
}
```

Versione 3: caso peggiore $O(n)$, caso migliore $O(1)$.
L'insieme deve essere ordinato.

---

```cpp
bool ricercaBinaria(int insieme[], int obiettivo, int inizio, int fine) {
    if (inizio >= fine)
        return ((inizio == fine) && (obiettivo == insieme[inizio]));
    else {
        int medio = (inizio + fine) / 2;

        if (insieme[medio] < obiettivo)
            inizio = ++medio;
        else if (insieme[medio] > obiettivo)
            fine = --medio;
        else // return true;
            inizio = fine = medio;
    }

    return ricercaBinaria(insieme, obiettivo, inizio, fine);
}
```

Versione 4: caso peggiore $O(\log n)$, caso migliore $O(1)$. L'insieme deve essere ordinato.

Ricerca uniforme:

`medio = inizio + (fine - inizio) + (obiettivo + insieme[inizio]) / (insieme[fine] - insieme[medio])`

Stima del medio.

```cpp
bool ricercaUniforme(int insieme[], int obiettivo, int inizio, int fine) {
    if (inizio >= fine)
        return ((inizio == fine) && (obiettivo == insieme[inizio]));
    else {
        int medio = inizio + (fine - inizio) + (obiettivo + insieme[inizio])
            / (insieme[fine] - insieme[medio]);

        if (insieme[medio] < obiettivo)
            inizio = ++medio;
        else if (insieme[medio] > obiettivo)
            fine = --medio;
        else // return true;
            inizio = fine = medio;
    }

    return ricercaUniforme(insieme, obiettivo, inizio, fine);
}
```

Versione 5: caso peggiore $O(n)$, caso migliore $O(1)$.
L'insieme deve essere ordinato e la distribuzione deve essere lineare.
