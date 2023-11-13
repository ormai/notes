# 2023-11-08

### Strutture dati lineari

Per ogni elemento è facile ottenere il precedente e il successivo.

- Array built-in
    - Puntatori
- Vector
- String
- Liste
- Code
    - Code con priorità
- Stack
- Set
- Hash map
    - map (meno efficiente dell'unordered)
    - unordered_map
- class & struct (aggregate type)

### Strutture dati non lineari

Non è facile stabilire una precedenza tra gli elementi all'interno della struttura dati. Non sono presenti in STL. Sono più complicate delle lineari.

- Alberi
- Grafi

## Alberi

Utili per rappresentare gerarchie di oggetti. Definiti tramite **nodi** (contiene l'informazione) e **archi** (collegamento tra nodi).

Il nodo da cui un arco parte è detto *padre*, quello a cui arriva è detto *figlio*. Un figlio ha solo un padre, un padre può avere più figli. Un albero ha una **radice**, che è un nodo senza padre ed il nodo attraverso il quale si accede all'albero. I nodi senza figli sono detti *foglie*.

Alberi generici: numero massimo di figli non definito. Per $n$ nodi si hanno $n - 1$ archi.
Alberi binari: numero massimo di figli è $2$.
Alberi $n$-ari: numero massimo di figli è $n$.

### Alberi binari

Gli alberi binari sono per loro natura ricorsivi.
I nodi hanno un *livello*. Il livello di ciascun nodo è il livello del precedente + 1. La *profondità* dell'albero è pari al livello massimo di un certo nodo.

Albero degenere: ogni padre ha un solo figlio.
Albero pieno: ogni padre ha esattamente due figli.

Dato un albero binario con $n$ nodi, il caso in cui si ha la profondità massima è quello dell'albero degenere, cui si ha profondità pari a $O(n)$. In un albero pieno la relazione che lega la profondità al numero di nodi è $O(\log_2 n)$

Profondità $p$: massimo numero di nodi = $O(2^p)$.

## Albero bilanciato

Per ogni nodo vale: $profondità\ del\ sotto\ albero\ sinistro\ -\ profondità\ del\ sotto\ albero\ destro \leq 1$.

Ha profondità $O(\log n)$ dove $n$ sono i nodi.

## Rappresentare gli alberi

- Rappresentazione indicizzata, attraverso strutture dati statiche (come i vector).
    - Vettore dei padri. Ogni elemento del vettore contiene l'informazione del nodo e un l'indice del padre nello stesso vettore. Questo metodo è buono per rappresentare alberi generici. Se si aggiunge un nodo ed un arco all'albero è sufficiente aggiungere un elemento al vettore.
    ```
    +------+------+------+------+------+
    |      |      | info | F    |      |
    |      |      | padre| 2    |      |
    +------+------+------+------+------+
    ```
    - Vettore posizionale
    ```
    +-----+-----+------+----+-----+-----+-----+
    |     |  A  |  B  |  C  |  D  |  F  |  E  |
    +-----+-----+------+----+-----+-----+-----+

    ```
    La cella 0 non è usata. La cella 1 contiene sempre la radice. Le restanti celle contengono i figli della radice.
    Dato il nodo $v$ l'$i$-esimo figlio di $v$ è `P[d * v + i]`, dove $0\leq i \leq d - 1$ e $d$ è il numero massimo di figli. Il padre -> `int(v / d)`. Non funziona con gli alberi generici.
- Rappresentazione collegata, attraverso strutture dati dinamiche, quindi puntatori.
    - Puntatori ai figli: ogni nodo è composto dall'informazione e da una lista di puntatori ai figli.
    - Primo figlio-fratello. Ogni nodo ha due puntatori. Il primo punta al primo figlio, il secondo punta all'eventuale fratello.

Un albero può essere un puntatore alla radice. Ogni nodo è a sua volta la radice di un sotto albero.

```cpp
// definisce un tipo enumerativo
enum Direzione { SINISTRA = 0, DESTRA = 1 };
// rinomina 0 con SINISTRA

template<class T> class AlberoBinario {
public:
    bool nullo() const;
    AlberoBinario<T> figlio(Direzione d) const;
};

template<class T> int profondita(AlberoBinario<T> ab) {
    if (ab.nullo())
        return 0;
    int p1 = profondita(ab.figlio(SINISTRA));
    int p2 = profondita(ab.figlio(DESTRA));
    return (p1 > p2) ? p1 + 1 : p2 + 1;
    // return 1 + std::max(p1, p2)
    /*
    if (p1 > p2)
        return 1 + p1;
    return 1 + p2;
    */
}
```

Ragionamento bottom-up. Si comincia a calcolare la profondità partendo dalla foglia dell'albero, salendo alla radice. Il risultato si forma nella catena di ritorno della funzione ricorsiva.
