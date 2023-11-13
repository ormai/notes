# 2023-11-13

Problema: risalire dal padre al figlio. Si aggiunge un puntatore dal figlio al padre. La radice punta a `nullptr`.

Ogni nodo può avere due figli. È quindi composto da un array contenente puntatori ai due figli o `nullptr`.

[Implementazione](BinaryTree.cpp).

## Visite

Visitare: ci si sposta su un nodo
Valutare: si effettua un'operazione su un nodo ottenendo un risultato.

Esempio: stampa l'informazione di ogni nodo

```
            A
           / \
          B   C
         / \   \
        D   E   F
       /     \
      G       H
```

Anticipata:  A B D G H E C F

Posticipata: G H D E B F C A

Simmetrica:  G D H B E A C F

A livelli:   A B C D E F G H

```cpp
template <class T> void visitaSimmetrica(BinaryTree<T> A) {
    if (!A.nullo()) {
        visitaSimmetrica(A.child(left));
        cout << A.rootNode(); // valutazione
        visitaSimmetrica(A.child(right));
    }
}
```

```cpp
/* Restituisce l'albero che contiene v se esiste, altrimenti un
 * albero nullo.
 * Caso peggiore: O(n) */
BinaryTree<int> cerca(BinaryTree<int> A, int v) {
    if (A.null() || A.rootNode() == v)
        return A;

    BinaryTree<int> t = cerca(A.child(left), v);
    if (!t.null())
        return t;

    return cerca(a.child(right), v);
}
```
