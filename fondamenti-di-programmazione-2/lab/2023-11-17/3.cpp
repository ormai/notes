/* Sia T un albero binario di interi positivi. Ogni percorso radice-foglia può
 * essere interpretato come l’intero che si ottiene concatenando tutte le cifre
 * nell’ordine in cui si incontrano.
 *
 * Ad esempio il seguente albero binario:
 *
 * 1
 *   2
 *   3
 *     4

 * codifica gli interi 12 (1 -> 2) e 134 (1 -> 3 -> 4) la cui somma è 146.
 *
 * Scrivere una funzione con segnatura:
 *
 * int somma_path(const AlberoB<int>&);
 *
 * che restituisce la somma degli interi rappresentati da ogni percorso
 * radice-foglia di T. */

#include "../AlberoB.cpp"
#include <iostream>
#include <string>

int somma_path(const AlberoB<int> &ab) {
  using std::stoi;
  using std::to_string;

  if (ab.nullo()) // caso in cui l'albero è nullo in partenza
    return 0;

  if (ab.foglia()) // caso base
    return ab.radice();

  // Per concatenare due interi usando epsressioni matematiche si deve conoscere
  // il numero di cifre del secondo numero. Più semplice con stringhe.

  int percorsoDestro = 0, percorsoSinistro = 0;
  std::string inizioPercorso = to_string(ab.radice());

  if (!ab.figlio(SIN).nullo())
    percorsoDestro =
        stoi(inizioPercorso + to_string(somma_path(ab.figlio(SIN))));

  if (!ab.figlio(DES).nullo())
    percorsoSinistro =
        stoi(inizioPercorso + to_string(somma_path(ab.figlio(DES))));

  return percorsoDestro + percorsoSinistro;
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

  AlberoB<int> w{1}, x{2}, y{3}, z{4};
  w.insFiglio(SIN, x);
  w.insFiglio(DES, y);
  y.insFiglio(SIN, z);

  std::cout << somma_path(a) << std::endl;
  std::cout << somma_path(w) << std::endl;

  return 0;
}
