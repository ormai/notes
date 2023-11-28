/* Scrivere una funzione con segnatura:
 *
 * bool pari_dispari(const AlberoB<int>&);
 *
 * che restituisca true se e solo se l’albero binario soddisfa le seguenti
 * condizioni:
 * - sui livelli dispari compaiono solo numeri dispari;
 * - sui livelli pari compaiono solo numeri pari.
 * Il livello di un nodo è definito induttivamente come:
 * - la radice di un albero appartiene al livello 1;
 * - dato un nodo appartenente al livello L, i suoi figli appartengono al
 *   livello L + 1. */

#include "../AlberoB.cpp"
#include <iostream>

bool pariDispari(const AlberoB<int> &ab, unsigned livello) {
  if (ab.nullo())
    return true;

  bool destra = pariDispari(ab.figlio(SIN), livello + 1),
       sinistra = pariDispari(ab.figlio(DES), livello + 1);

  return livello % 2 == ab.radice() % 2 && destra && sinistra;
}

bool pari_dispari(const AlberoB<int> &ab) { return pariDispari(ab, 1); }

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

  AlberoB<int> x{1}, y{2}, z{4};
  x.insFiglio(SIN, y);
  x.insFiglio(DES, z);

  std::cout << (pari_dispari(a) ? "true" : "false") << std::endl; // false

  std::cout << (pari_dispari(x) ? "true" : "false") << std::endl; // true

  return 0;
}
