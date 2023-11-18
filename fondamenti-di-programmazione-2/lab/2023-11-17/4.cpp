#include "../../dispense/AlberoB.cpp"
#include <iostream>

bool percorsoVero(const AlberoB<bool> &foglia) {
  bool condizione = true;
  if (foglia.radice()) {
    AlberoB<bool> genitore = foglia.padre();
    while (!genitore.nullo() && condizione) {
      if (!genitore.radice())
        condizione = false;
      genitore = genitore.padre();
    }
  } else
    return false;
  return condizione;
}

bool path_congiunzione(const AlberoB<bool> &T) {
  if (T.foglia())
    return percorsoVero(T);

  bool sinistra = false, destra = false;
  if (!T.figlio(SIN).nullo())
    sinistra = path_congiunzione(T.figlio(SIN));
  if (!T.figlio(DES).nullo())
    destra = path_congiunzione(T.figlio(DES));

  return sinistra || destra;
}

bool path_disgiunzione(const AlberoB<bool> &T) {
  if (T.foglia()) {
    AlberoB<bool> genitore = T.padre();
    while (!genitore.nullo()) {
      if (genitore.radice())
        return true;
      genitore = genitore.padre();
    }
    return false;
  }

  bool sinistra = false, destra = false;
  if (!T.figlio(SIN).nullo())
    sinistra = path_disgiunzione(T.figlio(SIN));
  if (!T.figlio(DES).nullo())
    destra = path_disgiunzione(T.figlio(DES));

  return sinistra || destra;
}

int main() {
  AlberoB<bool> a{true}, b{false}, c{false}, d{false}, e{false}, f{false},
      g{false}, h{false}, i{false};
  a.insFiglio(SIN, b);
  a.insFiglio(DES, c);
  b.insFiglio(SIN, d);
  b.insFiglio(DES, e);
  e.insFiglio(SIN, g);
  e.insFiglio(DES, h);
  c.insFiglio(DES, f);
  f.insFiglio(SIN, i);

  std::cout << (path_congiunzione(a) ? "true" : "false") << std::endl;
  std::cout << (path_disgiunzione(a) ? "true" : "false") << std::endl;

  return 0;
}
