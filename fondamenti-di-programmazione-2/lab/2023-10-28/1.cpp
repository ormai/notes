#include <algorithm>
using std::sort;
#include <vector>
using std::vector;
#include <iostream>
using std::ostream, std::cout, std::endl;

template <class T> class Sequenza {
private:
  vector<T> m_seq{};

public:
  Sequenza() = default;
  Sequenza(const unsigned &size) : m_seq(size) {}
  Sequenza(const Sequenza &s) {
    for (auto i = 0; i < s.size(); ++i)
      m_seq.push_back(s[i]);
  }

  unsigned size() const { return m_seq.size(); }
  Sequenza estrai_finestra(unsigned i, unsigned j) const;
  void inverti_finestra(unsigned i, unsigned j);
  void inserisci_elementi(unsigned i, const vector<T> &new_values);
  void posponi(const T &e) { m_seq.push_back(e); }
  void rimuovi_per_valori(T l, T u);
  void rimuovi_per_posizione(unsigned i, unsigned j);
  void ordina_finestra(unsigned i, unsigned j, bool asc);
  Sequenza concatena(const Sequenza &a);

  T operator[](unsigned int i) const { return m_seq[i]; }
  T &operator[](unsigned int i) { return m_seq[i]; }

  Sequenza operator=(const Sequenza &s);

  friend ostream &operator<<(ostream &os, const Sequenza<T> &seq) {
    const unsigned dim = seq.size();
    for (unsigned i = 0; i < dim; ++i) {
      os << seq[i];
      if (i + 1 != dim)
        os << ", ";
    }
    return os;
  }
};

template <class T>
Sequenza<T> Sequenza<T>::estrai_finestra(unsigned i, unsigned j) const {
  Sequenza finestra;
  while (i <= j) {
    finestra.posponi(m_seq[i]);
    ++i;
  }
  return finestra;
}

template <class T> void Sequenza<T>::inverti_finestra(unsigned i, unsigned j) {
  while (i <= j) {
    T tmp = m_seq[i];
    m_seq[i] = m_seq[j];
    m_seq[j] = tmp;
    ++i;
    --j;
  }
}

template <class T>
void Sequenza<T>::inserisci_elementi(unsigned i, const vector<T> &new_values) {
  for (T e : new_values)
    m_seq.push_back(e);
}

template <class T> void Sequenza<T>::rimuovi_per_valori(T l, T u) {
  auto it = m_seq.begin();
  while (it != m_seq.end())
    (*it <= u && *it >= l) ? m_seq.erase(it) : ++it;
}

template <class T>
void Sequenza<T>::rimuovi_per_posizione(unsigned i, unsigned j) {
  const auto start = m_seq.begin() + i;

  for (auto it = start; it != start + j; ++it)
    m_seq.erase(it);
}

template <class T>
void Sequenza<T>::ordina_finestra(unsigned i, unsigned j, bool asc) {
  auto start = m_seq.begin();
  if (asc)
    sort(start + i, start + i + j);
  else // decrescente
    sort(start + i, start + i + j, [](T a, T b) { return a > b; });
}

template <class T> Sequenza<T> Sequenza<T>::concatena(const Sequenza<T> &a) {
  Sequenza<T> concatenata = *this;
  for (unsigned i = 0; i < a.size(); ++i)
    concatenata.posponi(a[i]);
  return concatenata;
}

template <class T> Sequenza<T> Sequenza<T>::operator=(const Sequenza<T> &s) {
  Sequenza<T> tmp;
  for (auto i = 0; i < s.size(); ++i)
    tmp.posponi(s[i]);
  return tmp;
}

int main() {
  // TESTING
  Sequenza<int> seq;
  vector<int> a{1, 2, 3, 4, 5, 6};
  seq.inserisci_elementi(0, a);

  cout << seq << endl;
  seq.inverti_finestra(2, seq.size() - 1);
  cout << seq << endl;
  cout << seq.estrai_finestra(2, 4) << endl;
  // seq.rimuovi_per_posizione(2, 3);
  // seq.rimuovi_per_valori(1, 6);
  seq.ordina_finestra(0, 6, false);
  cout << seq << endl;

  Sequenza<int> sec;
  vector<int> b{9, 8, 7};
  sec.inserisci_elementi(0, b);

  cout << seq.concatena(sec) << endl;

  return 0;
}
