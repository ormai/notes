#include "../../dispense/AlberoB.cpp"
#include <iostream>
#include <string>

unsigned depth = 0;

template <typename T> void stampa_albero(const AlberoB<T> &ab) {
  if (ab.nullo()) {
    return;
  }

  // https://stackoverflow.com/questions/166630/how-can-i-repeat-a-string-a-variable-number-of-times-in-c
  std::cout << std::string(depth, ' ') << ab.radice() << '\n';

  ++depth;
  stampa_albero(ab.figlio(SIN));
  stampa_albero(ab.figlio(DES));
  --depth;
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
