/* Scrivere una funzione che preso in input un grafo G, restituisca un
 * vector<unsigned> il cui i-esimo elemento sia il numero di nodi di G il cui
 * grado è i. */

#include "../Grafo.cpp"
#include <iostream>
#include <ostream>
#include <vector>

std::vector<unsigned> f(const Grafo &g) {
  std::vector<unsigned> gradi(g.n(), 0);
  for (int i = 0; i < g.n(); ++i)
    for (int j = 0; j < g.n(); ++j)
      if (g(i, j) || g(j, i))
        ++gradi[i];

  // il grado massimo possibile è g.n() - 1
  // Si deve considerare che l'indice comincia da 0 quindi si ha g.n()

  std::vector<unsigned> esercizio(g.n(), 0);
  for (unsigned grado : gradi)
    ++esercizio[grado];
  return esercizio;
}

int main() {
  Grafo grafo(5);    // ../grafo-5-vertici.png
  grafo(0, 1, true); // grado(0) = 2
  grafo(0, 4, true);
  grafo(1, 2, true); // grado(1) = 4
  grafo(1, 3, true);
  grafo(1, 4, true);
  grafo(2, 3, true); // grado(2) = 2
  grafo(3, 4, true); // grado(3) = 3
  // grado(4) = 3

  std::vector<unsigned> e = f(grafo); // 0 0 2 2 1
  for (int n : e)
    std::cout << n << ' ';
  std::cout << std::endl;
  return 0;
}
