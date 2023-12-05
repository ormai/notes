/* Scrivere una funzione che preso in input un grafo G, restituisca la coppia
 * dei nodi che hanno in comune più nodi adiacenti. La funzione dovrà avere la
 * seguente segnatura:
 *
 * pair<pair<unsigned,unsigned>,unsigned> esercizio(const Grafo& g);
 *
 * dove il valore di ritorno sarà un std::pair il cui primo elemento
 * è a sua volta un std::pair che denota la coppia di nodi con la proprietà
 * cercata, mentre il secondo elemento sarà il numero di nodi in comune. */

#include "../Grafo.cpp"
#include <iostream>
#include <utility>

/* Trovare la coppia di nodi del grafo con più nodi adicenti. */
std::pair<std::pair<unsigned, unsigned>, unsigned> esercizio(const Grafo &g) {
  unsigned maxNodi = 0, maxI = 0, maxJ = 0;

  for (int i = 0; i < g.n(); ++i)
    for (int j = i + 1; j < g.n(); ++j) {
      // coppia di nodi:

      unsigned nodiCorr = 0;
      for (int k = 0; k < g.n(); ++k)
        if ((g(i, k) || g(k, i)) && (g(j, k) || g(k, j))) // grafo non orientato
          ++nodiCorr;

      /* In caso di più coppie nodi che hanno lo stesso massimo numero di nodi
       * adicenti:
       * - con > restituisce la prima
       * - con >= restituisce l'ultima */
      if (nodiCorr > maxNodi) {
        maxNodi = nodiCorr;
        maxI = i;
        maxJ = j;
      }
    }

  return {{maxI, maxJ}, maxNodi};
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

  std::pair<std::pair<unsigned, unsigned>, unsigned> e = esercizio(grafo);

  std::cout << "I nodi " << e.first.first << " e " << e.first.second
            << " hanno in comune " << e.second << " nodi adicenti."
            << std::endl;

  return 0;
}
