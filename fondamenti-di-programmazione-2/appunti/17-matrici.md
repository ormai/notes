# 2023-11-03

## Matrici

```cpp
std::vector<std::vector<int>> matrix;
```

```cpp
// per evitare la notazione del template
typedef std::vector<int> vectorInt;

// oppure:
using vectorInt = std::vector<int>;

vectorInt<vectorInt> v;
```

I vector contenuti nel vector esterno potrebbero avere dimensione diversa. Nel caso di una matrice simmetrica ciò consente di risparmiare spazio, avendo una matrice più piccola.

*Matrice simmetrica*: $m(i, j) = m(j, i)$, gli elementi sopra la diagonale principale sono simmetrici a quelli sotto.
