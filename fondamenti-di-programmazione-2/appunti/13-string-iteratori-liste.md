# 2023-10-23

## string

```cpp
#include <string>
using std::string;

string sobject("hello"); // chiama il costruttore (inizializzazione diretta)
string sobject = "hello"; // usa l'operatore = (inizializzazione per copia)
string s1 = "Hello, ";
string sobject = s1;
string s2 = "World";
string sobject = s1 + s2; // "Hello, World"
```

Le `string` sono una specializzazione di `vector`.

## Iteratori

`begin()`, `end()`. Tipo di dato `std::string::iterator`. 

Consentono di *iterare* sugli elementi della struttura dati (vector, string, built-in array, ...). Sono simili a puntatori ma possono essere più complessi.

`*it` dereferenzia l'iteratore. Non si tratta della classica dereferenziazione di un puntatore, ma si sta usando l'overloading dell'operatore `*` definito appositamente per l'iteratore di quella certa struttura dati.

```cpp
#include <string>
#include <iostream>

int main() {
  std::string s;

  for (std::string::iterator it = s.begin(); it != s.end(); ++it)
    std::cout << *it << std::endl; // output verso cout di tutti i caratteri della stringa.
}
```

Si usa `!=`, invece che `<`, quasi per convenzione. Notare che si stanno confrontando indirizzi di memoria, non numeri sequenziali.

Invece che specificare il tipo dell'iteratore per esteso, si può usare `auto` oppure `decltype(s.begin())`.

## algorithm

```cpp
#include <algorithm>

std::sort(vec.begin(), vec.end()); // di default ordina in modo crescente relativamente al tipo di dato, si può anche ordinare in modo decrescente
auto pos = std::unique(vec.begin(), vec.end()); // i duplicati sono spostati alla fine di vec e restituisce la posizione del primo duplicato piazzato ala fine
vec.erase(pos, vec.end()); // elimina i duplicati che si trovano alla fine
```

## Container STL

```
array
vector
deque
forward_list
list

stack
queue
priority_queue

set
multiset
map
multimap

unordered_set
unordered_multiset
unordered_map
unordered_multimap
```
## Liste concatenate (linked lists)

`forward_list`

È una struttura dati **lineare** (è possibile stabilire un elemento che precede ed uno che segue) e **dinamica** (riferito al modo in cui la memoria è gestita).

Gli elementi della lista sono legati da puntatori. Quindi gli elementi della lista, detti **nodi**, sono costituiti da due componenti: l'oggetto che contengono e il puntatore che li lega. La lista termina quando il puntatore dell'ultimo elemento è `nullptr`.

Questa struttura dati è conveniente perché non bisogna specificare una dimensione fissa. La `capacity` è virtualmente *infinita*. E se si vuole rimuovere un elemento è sufficiente assegnare al puntatore di un oggetto l'indirizzo dell'oggetto che segue (ricordandosi di eliminare l'oggetto dalla memoria con `delete`). Similmente se si vuole aggiungere un elemento nel mezzo (costo $O(1)$). Si ha però uno svantaggio nell'accesso di un elemento nel mezzo, per accedervi bisogna sempre partire dall'inizio. Il costo è $O(i)$, ma che generalmente si approssima a $O(n)$

La dimensione in memoria rispetto ad un array è maggiore, poiché per ogni elemento della lista si ha anche un puntatore.

Il primo elemento della lista è detto *testa* (*head*) ed è l'unico modo per accedere alla lista. Una volta perso questo puntatore si perde accesso a tutta la lista.

Solitamente si ha anche un puntatore all'ultimo elemento della lista, detto *coda* (*tail*). Può essere utile quando si aggiunge un elemento alla fine o quando si vuole accedere ad un elemento che si sa essere più vicino alla *tail*, piuttosto che alla *head*.

## Liste list

`list`

Ogni nodo della lista tiene conto del nodo che segue e di quello di precede, quindi due puntatori. A differenza della `forward_list` è molto più facile muoversi indietro, oltre che avanti.

Implementazione nel pdf del professore.

## Iteratori su liste


```
    +---+  +---+  +---+  +---+  +---+
    |   |->|   |->|   |->|   |->|   |
    +---+  +---+  +---+  +---+  +---+
    first         curr          last
```

Dereferenziando il puntatore a curr si ottiene il suo valore. Incrementando di 1 l'interatore si esegue `i.next()`, decrementando di 1 si esegue `i.back()`.
