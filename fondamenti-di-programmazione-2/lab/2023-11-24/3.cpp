/* Sia G un grafo, x un suo vertice. Denotiamo con δx(i) l’insieme di nodi di
 * G la cui distanza minima da x è i. Scrivere una funzione che restituisca un
 * vector<vector<unsigned>> il cui j-esimo elemento sia esattamente δx(j). */

#include "../Grafo.cpp"
#include <iostream>
#include <list>
#include <queue>
#include <vector>

std::vector<int> pred(const Grafo &, const unsigned);
void formaCammino(const unsigned, int, const std::vector<int> &,
                  std::list<unsigned> &);

int main() {
  Grafo G(5); // ../grafo-5-vertici.png
  G(0, 1, true);
  G(0, 4, true);
  G(1, 2, true);
  G(1, 3, true);
  G(1, 4, true);
  G(2, 3, true);
  G(3, 4, true);


  for (unsigned x = 0; x < G.n(); ++x) {
    // Per ogni nodo x di G:
    std::vector<std::vector<unsigned>> delta(G.n()); // δx

    const std::vector<int> predecessori = pred(G, x);
    for (unsigned nodo = 0; nodo < G.n(); ++nodo) {
      // Per ogni altro nodo di G:

      std::list<unsigned> cammino;
      formaCammino(x, nodo, predecessori, cammino);
      delta[cammino.size() - 1].push_back(nodo); // aggiungi nodo a δx(i);
    }

    // Stampa δx;
    std::cout << "δ" << x + 1 << ":\n";
    for (std::vector<unsigned> riga : delta) {
      for (unsigned nodo : riga) {
        std::cout << nodo + 1 << ' ';
      }
      std::cout << std::endl;
    }
  }
}

void formaCammino(const unsigned s, int t, const std::vector<int> &pred,
                  std::list<unsigned> &cammino) {
  if (s == t)
    cammino.push_back(s);
  else if (t == -1)
    return;
  else {
    formaCammino(s, pred[t], pred, cammino);
    cammino.push_back(s);
  }
}

std::vector<int> pred(const Grafo &g, const unsigned s) {
  std::vector<bool> visitati(g.n(), false);
  std::queue<unsigned> q;
  std::vector<int> predecessori(g.n(), -1);

  q.push(s);
  visitati[s] = true;
  predecessori[s] = s;

  while (!q.empty()) {
    unsigned u = q.front();
    q.pop();

    for (unsigned i = 0; i < g.n(); ++i)
      if (i != u && !visitati[i] && (g(u, i) || g(i, u))) {
        q.push(i);
        predecessori[i] = u;
        visitati[i] = true;
      }
  }

  return predecessori;
}
