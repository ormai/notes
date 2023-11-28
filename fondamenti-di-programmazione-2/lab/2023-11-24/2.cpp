/* Sia G un grafo non orientato, a, b due suoi nodi. Determinare l’insieme di
 * nodi di G equidistanti da a e b. Un nodo x si dice equidistante da una coppia
 * di nodi (a, b) quando la lunghezza del suo cammino minimo verso a e verso b è
 * uguale. */

#include "../Grafo.cpp"
#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <vector>

std::vector<int> predecessori(const Grafo &, unsigned);
void ricostruisciCammino(const unsigned, const int, const std::vector<int> &,
                         std::list<unsigned> &);

int main() {
  Grafo grafo(5); // ../grafo-5-vertici.png
  grafo(0, 1, true);
  grafo(0, 4, true);
  grafo(1, 2, true);
  grafo(1, 3, true);
  grafo(1, 4, true);
  grafo(2, 3, true);
  grafo(3, 4, true);

  for (unsigned a = 0; a < grafo.n(); ++a)
    for (unsigned b = a + 1; b < grafo.n(); ++b) {
      // a e b sono una coppia di nodi distinti:

      std::set<unsigned> equidistanti;
      for (unsigned x = 0; x < grafo.n(); ++x) {
        // 1. Determina i predecessori di ogni nodo rispetto al nodo sorgente x.
        const std::vector<int> predecessoriDiX = predecessori(grafo, x);

        // 2. Forma il cammino da x a a/b, partendo da a/b e passando per i
        //    predecessori di ogni nodo, finché non si giunge ad x.
        std::list<unsigned> daXversoA, daXversoB;
        ricostruisciCammino(x, a, predecessoriDiX, daXversoA);
        ricostruisciCammino(x, b, predecessoriDiX, daXversoB);

        // 3. Se i due cammini hanno uguale lunghezza, allora i nodi a e b sono
        //    alla stessa distanza da x.
        if (daXversoA.size() == daXversoB.size())
          equidistanti.insert(x);
      }

      // Gli indici stampati sono incrementati di 1 perché nel diagramma
      // ../grafo-5-vertici.png gli indici dei nodi cominciano da 1.
      std::cout << "Nodi equidistanti da " << a + 1 << " e " << b + 1 << ": ";
      for (unsigned nodo : equidistanti)
        std::cout << nodo + 1 << ' ';
      std::cout << std::endl;
    }

  return 0;
}

/* Si costruisce il percorso dal nodoTerminale al nodoSorgente. Oni chiamata
 * ricorsiva sposta il nodoTerminale di uno più vicino al nodoSorgente,
 * basandosi sul pred(nodoTerminale).
 * Quando il predecessore del nodo terminale è proprio il nodo sorgente la
 * funzione sbatte contro il caso base, e si comincia a spingere ogni nodo nel
 * cammino, partendo proprio dal nodoSorgente e finendo col nodoTerminale. */
void ricostruisciCammino(const unsigned nodoSorgente, const int nodoTerminale,
                         const std::vector<int> &predecessore,
                         std::list<unsigned> &cammino) {
  if (nodoSorgente == nodoTerminale)
    cammino.push_back(nodoSorgente);
  else if (nodoTerminale == -1)
    return;
  else {
    ricostruisciCammino(nodoSorgente, predecessore[nodoTerminale], predecessore,
                        cammino);
    cammino.push_back(nodoTerminale);
  }
}

/* Calcola il predecessore di ogni nodo rispetto al nodoSorgente */
std::vector<int> predecessori(const Grafo &grafo, unsigned nodoSorgente) {
  std::vector<bool> visitati(grafo.n(), false);
  std::vector<int> predecessori(grafo.n(), -1);
  std::queue<unsigned> q;

  q.push(nodoSorgente);
  predecessori[nodoSorgente] = nodoSorgente;
  visitati[nodoSorgente] = true;

  while (!q.empty()) {
    unsigned u = q.front();
    q.pop();

    for (unsigned i = 0; i < grafo.n(); ++i)
      if (u != i && !visitati[i] && (grafo(u, i) || grafo(i, u))) {
        q.push(i);
        predecessori[i] = u;
        visitati[i] = true;
      }
  }

  return predecessori;
}
