# 2023-11-02

## Coda (queue)

La priorità degli elementi consiste nel valore stesso di ciascun elemento.

```cpp
template <class T> class Coda : protected list<T> {
  // con protected la classe vede anche i membri protetti di list

  bool empty() { return list<T>::empty() };
  unsigned size();
  const T &front();
  const T &back();
  void push(const T &n);
  void pop();
  void print();
}
```

[std::queue](https://devdocs.io/cpp/container/queue)

## Coda prioritaria (priority queue)

```
    massima
    priorità
    +---+  +---+  +---+  +---+
    | 4 |->| 3 |->| 2 |->| 1 |
    +---+  +---+  +---+  +---+
                ^
                |
              +---+
              | 3 |
              +---+
```

[std::priority_queue](https://devdocs.io/cpp/container/priority_queue)

## Stampare gli elementi di uno stack

Per operare su uno stack conviene spesso usare una funzione ricorsiva, poiché
le chiamate ricorsive formano uno stack a loro volta.

```cpp
#include <iostrem>
#include <stack>

void printStack(std::stack<int> &s) {
  /* Lo stack è passato per valore ad ogni chiamata, quindi viene copiato.
   * Non lo si può passare per riferimento non costante perché si vuole tenere
   * lo stack originale intatto. Non lo si può neanche passare per riferimento
   * costante perché la funzione rimuove l'elemento in cima allo stack ad ogni
   * chiamata. */

  if (s.empty()) // contempla il caso in cui lo stack sia vuoto in partenza
    return;

  int top = s.top();
  s.pop();

  printStack(s); // stampa lo stack meno l'elemento in cima appena rimosso

  std::cout << top << ' ';
  s.push(top); // rimetti l'elemento al suo posto
}
```
