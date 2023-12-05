/* Dato un grafo, restituisce per ogni nodo il numero di nodi adiacenti. Cioè
 * questa funzione calcola il grado di ciascun nodo nel caso di grafi non
 * orientati e il grado di uscita di ciascun nodo nel caso di grafi orientati.
 */
#include <vector>
#include "../../dispense/Grafo.cpp"

std::vector<int> numAdiacenti(const Grafo &G) {
  std::vector<int> grado(G.n());
  for (int i = 0; i < G.n(); ++i) {
    grado[i] = 0;
    for (int j = 0; j < G.n(); ++j) {
      if (G(i, j))
        ++grado[i];
    }
  }
  return grado;
}
