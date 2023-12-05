/* Un albero può essere rappresentato graficamente in modo testuale. Ad esempio,
 * il seguente albero binario (non differisce molto per alberi generici):
 *
 *                     1
 *                    / \
 *                   7   9
 *                  / \   \
 *                 2   6   \
 *                    / \   \
 *                   5  11   9
 *                          /
 *                         5
 *
 * avrà la seguente rappresentazione testuale:
 *
 * 1
 *   7
 *     2
 *     6
 *       5
 *       11
 *   9
 *     9
 *       5
 *
 * Scrivere una funzione con segnatura:
 *
 * template<typename T> void stampa_albero(const AlberoB<T>&)
 *
 * che stampi su standard output la rappresentazione grafica dell’albero in
 * input. */

#include "../AlberoB.cpp"
#include <iostream>
#include <string>

template <typename T>
void stampaAlbero(const AlberoB<T> &ab, unsigned profondita) {
  if (ab.nullo())
    return;

  // costruttore di string(numeroDiRipetizioni, carattere)
  std::cout << std::string(profondita, ' ') << ab.radice() << '\n';

  stampaAlbero(ab.figlio(SIN), profondita + 1);
  stampaAlbero(ab.figlio(DES), profondita + 1);
}

// Per non cambiare il prototype
template <typename T> void stampa_albero(const AlberoB<T> &a) {
  stampaAlbero(a, 0);
}

int main() {
  AlberoB<int> a{1}, b{7}, c{9}, d{2}, e{6}, f{9}, g{5}, h{11}, i{5};
  a.insFiglio(SIN, b);
  a.insFiglio(DES, c);
  b.insFiglio(SIN, d);
  b.insFiglio(DES, e);
  e.insFiglio(SIN, g);
  e.insFiglio(DES, h);
  c.insFiglio(DES, f);
  f.insFiglio(SIN, i);

  stampa_albero(a);

  return 0;
}
