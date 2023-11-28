/* Implementare due classi GrafoAdj e GrafoEdgelist che modellino un grafo non
 * orientato, modellato mediante la classe astratta Grafo che implementa la
 * seguente interfaccia:
 *
 * class Grafo {
 * public:
 *
 *     /· Restituisce il numero di nodi nel grafo ·/
 *     unsigned num_nodi() const;
 *
 *     /· Restituisce il numero di archi nel grafo ·/
 *     unsigned num_archi() const;
 *
 *     /· Restituisce true se e solo se l'arco (i,j) esiste nel grafo ·/
 *     bool operator()(unsigned i, unsigned j) const;
 *
 *     /· Se set=true, aggiunge un arco.
 *     Altrimenti lo rimuove. ·/
 *
 *     void operator()(unsigned i, unsigned j, bool set);
 *     /· Restituisce un vector g, dove g[i] è il grado del
 *
 *     nodo i-esimo nel grafo. ·/
 *     vector<unsigned> gradi() const;
 *
 *     /· Restituisce il grado del nodo j ·/
 *     unsigned grado(unsigned j) const
 *
 *     /· Restituisce i nodi adiacenti al nodo x ·/
 *     vector<unsigned> vicinato(unsigned x) const;
 * };

 * In particolare, la classe GrafoAdj dovrà essere implementata modellando un
 * grafo mediante la matrice di adiacenza(come la classe Grafo vista a lezione),
 * mentre la classe GrafoEdgelist dovrà essere implementata modellando un grafo
 * tramite lista di adiacenza. */

#include <algorithm>
#include <iterator>
#include <list>
#include <numeric>
#include <vector>

class Grafo {
public:
  /* Restituisce il numero di nodi nel grafo */
  virtual unsigned num_nodi() const = 0;

  /* Restituisce il numero di archi nel grafo */
  virtual unsigned num_archi() const = 0;

  /* Restituisce true se e solo se l'arco (i,j)
  esiste nel grafo */
  virtual bool operator()(unsigned i, unsigned j) const = 0;

  /* Se set=true, aggiunge un arco.
  Altrimenti lo rimuove. */
  virtual void operator()(unsigned i, unsigned j, bool set) = 0;

  /* Restituisce un vector g, dove g[i] è il grado del
  nodo i-esimo nel grafo. */
  virtual std::vector<unsigned> gradi() const = 0;

  /* Restituisce il grado del nodo j */
  virtual unsigned grado(unsigned j) const = 0;

  /* Restituisce i nodi adiacenti al nodo x */
  virtual std::vector<unsigned> vicinato(unsigned x) const = 0;
};

class GrafoAdj : public Grafo {
  using adjacencyMatrix = std::vector<std::vector<bool>>;

  adjacencyMatrix adj; // matrice di adiancenza

  unsigned num_nodi() const { return adj.size(); }

  unsigned num_archi() const {
    unsigned edges = 0;
    for (int i = 0; i < adj.size(); ++i)
      for (int j = 0; j < adj[0].size(); ++j)
        edges += adj.at(i).at(j);
    return edges;
  }

  bool operator()(unsigned i, unsigned j) const { return adj.at(i).at(j); }

  void operator()(unsigned i, unsigned j, bool set) { adj.at(i).at(j) = set; }

  std::vector<unsigned> gradi() const {
    std::vector<unsigned> g(adj.size());
    for (int i = 0; i < adj.size(); ++i)
      for (int j = 0; j < adj.at(0).size(); ++j)
        g.at(i) += adj.at(i).at(j); // da bool a unsigned
    return g;
  }

  unsigned grado(unsigned j) const {
    return std::accumulate(adj.at(j).begin(), adj.at(j).end(), 0);
  }

  std::vector<unsigned> vicinato(unsigned x) const {
    std::vector<unsigned> v;
    for (int i = 0; i < adj.at(x).size(); ++i)
      if (adj.at(x).at(i))
        v.push_back(i);
    return v;
  }
};

class GrafoEdgelist : public Grafo {
  using adjacencyList = std::list<std::list<int>>;
  adjacencyList adj; // lista di adiacenza

public:
  unsigned num_nodi() const { return adj.size(); }

  unsigned num_archi() const {
    unsigned sum = 0;
    for (std::list<int> node : adj)
      sum += node.size();
    return sum; // dividi per due in caso di grafo non orientato
  }

  bool operator()(unsigned i, unsigned j) const {
    adjacencyList::const_iterator it = adj.begin();
    std::advance(it, i);
    return std::find(it->begin(), it->end(), j) != it->end();
  }

  void operator()(unsigned i, unsigned j, bool set) {
    adjacencyList::iterator it = adj.begin(), jt = adj.begin();
    std::advance(it, i);
    std::advance(jt, j);
    if (set) {
      it->push_back(j);
      jt->push_back(i);
    } else {
      it->erase(std::find(it->begin(), it->end(), j));
      jt->erase(std::find(jt->begin(), jt->end(), i));
    }
  }

  std::vector<unsigned> gradi() const {
    std::vector<unsigned> g(adj.size());
    adjacencyList::const_iterator it = adj.begin();
    for (int i = 0; i < adj.size(); ++i)
      g[i] = it++->size();
    return g;
  }

  unsigned grado(unsigned j) const {
    adjacencyList::const_iterator it = adj.begin();
    std::advance(it, j);
    return it->size();
  }

  std::vector<unsigned> vicinato(unsigned x) const {
    adjacencyList::const_iterator it = adj.begin();
    std::advance(it, x);

    std::vector<unsigned> a(it->size());
    for (int node : *it)
      a.push_back(node);
    return a;
  }
};
