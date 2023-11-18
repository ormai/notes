#include "../../dispense/AlberoB.cpp"
#include <iostream>

// ogni volta che si scende ad un nodo figlio il livello aumenta e quando
// si torna ad un genitore diminuisce
unsigned livello = 1;

inline bool pari(int n) { return !(n % 2); }

bool pari_dispari(const AlberoB<int> &ab) {
  if (ab.nullo())
    return true;

  bool cond = pari(livello) == pari(ab.radice());

  ++livello;
  bool destra = pari_dispari(ab.figlio(SIN)),
       sinistra = pari_dispari(ab.figlio(DES));
  --livello;

  return cond && destra && sinistra;
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

  AlberoB<int> x{1}, y{2}, z{4};
  x.insFiglio(SIN, y);
  x.insFiglio(DES, z);

  std::cout << (pari_dispari(a) ? "true" : "false") << std::endl; // false

  std::cout << (pari_dispari(x) ? "true" : "false") << std::endl; // true

  return 0;
}
