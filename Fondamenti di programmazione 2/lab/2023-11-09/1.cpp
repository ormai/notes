#include <cassert>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <list>

/* La sequenza è sempre ordinata.
 * ordina_finestra() e inverti_finestra() non sono implementati.
 * concatena() è sostituito dall'operatore += */
class Sequenza {
  std::list<unsigned> m_seq = {};

public:
  Sequenza() = default;
  Sequenza(std::initializer_list<unsigned> l) : m_seq(l) { m_seq.sort(); }

  /* @return il numero di elementi della Sequenza */
  unsigned size() const { return m_seq.size(); }

  /* Aggiunge un elemento alla fine della sequenza
   * @param e elemento da aggiungere */
  void append(const unsigned &e) { m_seq.push_back(e); }

  /* Estrae un intervallo di elementi dalla sequenza */
  Sequenza estrai_finestra(unsigned i, unsigned j) {
    assert(i < j && j < m_seq.size());
    Sequenza tmp;
    std::list<unsigned>::iterator it = m_seq.begin();
    std::advance(it, i);
    while (it != m_seq.end())
      tmp.append(*it++);
    return tmp;
  }

  void inserisci_elementi(const std::list<unsigned> &new_values) {
    for (unsigned value : new_values)
      m_seq.push_front(value);
    m_seq.sort();
  }

  void rimuovi_per_valori(const unsigned l, const unsigned u) {
    std::list<unsigned>::iterator it = m_seq.begin();
    while (it != m_seq.end()) {
      if (*it >= l && *it <= u)
        m_seq.erase(it);
      else
        ++it;
    }
  }

  void rimuovi_per_posizione(unsigned i, unsigned j) {
    assert(j < m_seq.size());
    std::list<unsigned>::iterator it = m_seq.begin();
    std::advance(it, i);

    while (i++ <= j)
      m_seq.erase(it++);
  }

  unsigned &operator[](const unsigned n) {
    assert(n < m_seq.size());
    std::list<unsigned>::iterator it = m_seq.begin();
    std::advance(it, n);
    return *it;
  }

  unsigned operator[](const unsigned n) const {
    assert(n < m_seq.size());
    std::list<unsigned>::const_iterator it = m_seq.begin();
    std::advance(it, n);
    return *it;
  }

  void operator+=(const Sequenza &seq) {
    for (unsigned i = 0; i < seq.size(); ++i)
      m_seq.push_back(seq[i]);
    m_seq.sort();
  }

  friend std::ostream &operator<<(std::ostream &os, const Sequenza &seq) {
    for (unsigned e : seq.m_seq)
      os << e << ' ';
    return os;
  }
};

int main() {
  Sequenza seq = {93, 24, 55, 87, 3, 44}, seq2 = {1, 2, 9};
  std::cout << seq << std::endl;

  seq[2] = 99;

  std::cout << seq << std::endl;

  seq.rimuovi_per_posizione(2, 4);

  std::cout << seq << std::endl;

  seq += seq2;

  std::cout << seq << std::endl;

  return 0;
}
