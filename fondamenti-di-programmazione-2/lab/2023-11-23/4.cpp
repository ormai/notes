/* Sia G un grafo orientato. Scrivere una funzione che restituisca il numero di
 * triangoli contenuti in G. Definiamo triangolo una terna di nodi (a, b, c)
 * (con a < b < c) tale che (a, b) ∈ E(G), (b, c) ∈ E(G), (c, a) ∈ E(G). */

#include "../Grafo.cpp"
#include <iostream>

unsigned triangoli(const Grafo &G) {
  unsigned count = 0;
  for (int a = 0; a < G.n(); ++a)
    for (int b = a + 1; b < G.n(); ++b)
      for (int c = b + 1; c < G.n(); ++c)
        if (G(a, b) && G(b, c) && G(c, a)) {
          std::cout << "a: " << a << " b: " << b << " c: " << c << std::endl;
          ++count;
        }
  return count;
}

int main() {
  Grafo grafo(6); // ../grafo-6-vertici.png
  grafo(0, 1, true);
  grafo(0, 3, true);

  grafo(1, 4, true);
  grafo(4, 0, true); // chiude il triangolo 0->1->4

  grafo(2, 4, true);
  grafo(2, 5, true);

  grafo(3, 1, true);

  grafo(4, 3, true);

  grafo(5, 5, true);

  unsigned t = triangoli(grafo);

  std::cout << "Numero di triangoli: " << t << std::endl;
  return 0;
}
