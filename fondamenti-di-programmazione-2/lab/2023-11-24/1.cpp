/* Sia G un grafo. Scrivere una funzione che preso in input un nodo x, un
 * insieme di nodi A ⊆ V (G), determini un y ∈ A a distanza minima da x. La
 * funzione dovrà avere la seguente segnatura:
 * unsigned esercizio(const Grafo& g, const vector<unsigned>& A, unsigned x); */

#include "../Grafo.cpp"
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

unsigned esercizio(const Grafo &G, const std::vector<unsigned> &A, unsigned x) {
  std::vector<bool> visitati(G.n(), false);

  std::queue<unsigned> q;
  q.push(x);
  visitati[x] = true;

  while (!q.empty()) {
    unsigned n = q.front();
    q.pop();

    if (std::find(A.begin(), A.end(), n) != A.end())
      return n;

    // metti in coda i nodi non visitati adiacenti ad n
    for (int i = 0; i < G.n(); ++i)
      if (n != i && !visitati[i] && (G(n, i) || G(i, n))) {
        q.push(i);
        visitati[i] = true;
      }
  }

  return G.n();
}

int main() {
  Grafo G(5); // ../grafo-5-vertici.png
  G(0, 1, true);
  G(0, 4, true);
  G(1, 2, true);
  G(1, 3, true);
  G(1, 4, true);
  G(2, 3, true);
  G(3, 4, true);

  std::cout << "y: " << esercizio(G, {1, 4}, 0) << std::endl; // 1
  std::cout << "y: " << esercizio(G, {4, 1}, 3) << std::endl; // 1
  std::cout << "y: " << esercizio(G, {0, 2}, 3) << std::endl; // 2
  std::cout << "y: " << esercizio(G, {0}, 0) << std::endl;    // 0

  return 0;
}
