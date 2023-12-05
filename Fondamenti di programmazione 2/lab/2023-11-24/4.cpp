/* Sia G un grafo. Un nodo x di G si dice k-strategico se da x è possibile
 * raggiungere qualsiasi altro nodo con un cammino lungo al più k. Scrivere una
 * funzione che prenda in input un grafo G, un nodo x e un unsigned k che
 * restituisca true se e solo se il nodo x è k-strategico. */

#include "../Grafo.cpp"
#include <iostream>
#include <list>
#include <queue>
#include <vector>

void formaCammino(const unsigned, int, const std::vector<int> &,
                  std::list<unsigned> &);
std::vector<int> pred(const Grafo &, const unsigned);

int main() {
  unsigned n = 0;
  std::cout << "Numero di nodi: ";
  std::cin >> n;
  if (!n) {
    std::cout << "Un grafo senza nodi?" << std::endl;
    return -1;
  }
  Grafo G(n); // ../grafo-5-vertici.png

  int i = 1, j = 1;
  do {
    G(i - 1, j - 1, true);
    G(j - 1, i - 1, true);

    std::cout
        << "Arco (i, j). Indica i e j separati da spazio, -1 per terminare (1-"
        << n << "): ";
    std::cin >> i;
    if (i < 0)
      break;
    std::cin >> j;
  } while (i > 0 && i <= n || j > 0 && j <= n);

  unsigned x = 0;
  std::cout << "x: ";
  std::cin >> x;
  --x;

  unsigned k = 0;
  std::cout << "k: ";
  std::cin >> k;
  --k;

  bool condizione = true;

  const std::vector<int> predecessori = pred(G, x);
  for (int nodo = 0; nodo < G.n(); ++nodo) {
    std::list<unsigned> cammino;
    formaCammino(x, nodo, predecessori, cammino);
    if (cammino.size() > k)
      condizione = false;
  }

  std::cout << (condizione ? "true" : "false") << std::endl;

  return 0;
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
  std::vector<int> predecessori(g.n(), -1);
  std::queue<unsigned> q;

  q.push(s);
  visitati[s] = true;
  predecessori[s] = s;

  while (!q.empty()) {
    unsigned u = q.front();
    q.pop();

    for (unsigned i = 0; i < g.n(); ++i)
      if (i != u && !visitati[i] && (g(u, i) || g(i, u))) {
        visitati[i] = true;
        predecessori[i] = s;
        q.push(i);
      }
  }
  return predecessori;
}
