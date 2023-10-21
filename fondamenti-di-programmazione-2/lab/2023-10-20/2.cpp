#include <iostream>
using std::istream, std::ostream, std::cout, std::endl;

template <class T> class Insieme {
  T *insieme;
  void aumentaCapacity();
  unsigned elementi; // numero effettivo di elementi contenuti
  unsigned capacity; // dimensione in memoria dell'insieme

public:
  Insieme<T>() : elementi(0), capacity(1) { insieme = new T[capacity]; }
  Insieme<T>(Insieme<T> &_insieme) {
    const unsigned dim = _insieme.dimensione();
    insieme = new T[dim];
    capacity = dim;
    for (unsigned i = 0; i < _insieme.dimensione(); ++i)
      insieme[i] = _insieme[i];
  }
  ~Insieme<T>() { delete[] insieme; }

  bool vuoto() const;
  bool svuota();
  unsigned dimensione() const { return elementi; }
  bool aggiungi(const T &e);
  bool rimuovi(const T &e);
  bool contiene(const T &e) const;

  Insieme<T> unione(const Insieme<T> &o) const;
  Insieme<T> intersezione(const Insieme<T> &o) const;
  Insieme<T> differenza(const Insieme<T> &o) const;

  void unisci(const Insieme<T> &o);
  void interseca(const Insieme<T> &o);
  void meno(const Insieme<T> &o);

  // importanti per accedere agli elementi di insieme usando [] su un istanza
  // di Insieme
  T operator[](unsigned int i) const { return insieme[i]; }
  T &operator[](unsigned int i) { return insieme[i]; }
};

template <class T> void Insieme<T>::aumentaCapacity() {
  capacity *= 2; // duplica la capacità
  T *tmp = new T[capacity];

  for (unsigned i = 0; i < elementi; ++i)
    tmp[i] = insieme[i];

  delete[] insieme;
  insieme = tmp;
}

template <class T>
ostream &operator<<(ostream &os, const Insieme<T> &_insieme) {
  const unsigned dim = _insieme.dimensione();
  os << "{ ";
  for (unsigned i = 0; i < dim; ++i) {
    os << _insieme[i];
    if (i + 1 != dim)
      os << ", ";
  }
  os << " }";
  return os;
}

template <class T> bool Insieme<T>::vuoto() const {
  if (elementi == 0)
    return true;
  return false;
}

template <class T> bool Insieme<T>::svuota() {
  if (elementi != 0) {
    elementi = 0;
    return true;
  }
  return false;
}

template <class T> bool Insieme<T>::aggiungi(const T &e) {
  if (contiene(e)) // un Insieme non può contenere due volte lo stesso elemento
    return false;

  if (elementi == capacity)
    aumentaCapacity();

  insieme[elementi] = e; // come push_back()
  elementi++;

  return true;
}

template <class T> bool Insieme<T>::rimuovi(const T &e) {
  // evito di usare contiene() così da non fare altre n operazioni
  for (unsigned i = 0; i < elementi; ++i) {
    if (insieme[i] == e) {
      // sposta gli elementi dopo e indietro di un posto
      --elementi;
      for (unsigned j = i; j < elementi; ++j)
        insieme[j] = insieme[j + 1];
      return true;
    }
  }
  return false;
}

template <class T> bool Insieme<T>::contiene(const T &e) const {
  for (unsigned i = 0; i < elementi; ++i) {
    if (insieme[i] == e)
      return true;
  }
  return false;
}

template <class T> Insieme<T> Insieme<T>::unione(const Insieme<T> &o) const {
  Insieme<T> tmp;

  for (unsigned int i = 0; i < dimensione(); ++i) {
    tmp.aggiungi(insieme[i]);
  }

  for (unsigned i = 0; i < o.dimensione(); ++i)
    tmp.aggiungi(o[i]);

  return tmp;
}

template <class T>
Insieme<T> Insieme<T>::intersezione(const Insieme<T> &o) const {
  Insieme<T> tmp;

  for (unsigned i = 0; i < o.dimensione(); ++i)
    if (contiene(o[i]))
      tmp.aggiungi(o[i]);

  for (unsigned i = 0; i < dimensione(); ++i)
    if (o.contiene(insieme[i]))
      tmp.aggiungi(insieme[i]);

  return tmp;
}

template <class T>
Insieme<T> Insieme<T>::differenza(const Insieme<T> &o) const {
  Insieme<T> tmp;

  for (unsigned i = 0; i < dimensione(); ++i)
    if (!o.contiene(insieme[i]))
      tmp.aggiungi(insieme[i]);

  return tmp;
}

template <class T> void Insieme<T>::unisci(const Insieme<T> &o) {
  for (unsigned i = 0; i < o.dimensione(); ++i)
    aggiungi(o[i]);
}

template <class T> void Insieme<T>::interseca(const Insieme<T> &o) {
  unsigned i = 0;
  while (i < dimensione()) {
    if (!o.contiene(insieme[i]))
      rimuovi(insieme[i]);
    else
      ++i;
  }
}

template <class T> void Insieme<T>::meno(const Insieme<T> &o) {
  for (unsigned i = 0; i < o.dimensione(); ++i)
    rimuovi(o[i]);
}

int main() {
  Insieme<int> a;
  a.aggiungi(9);
  a.aggiungi(3);
  a.aggiungi(137);
  a.aggiungi(123);
  a.aggiungi(10);
  cout << a << endl;

  Insieme<int> b;
  b.aggiungi(1);
  b.aggiungi(2);
  b.aggiungi(7);
  b.aggiungi(3);
  cout << b << endl;

  cout << a.unione(b) << endl;
  cout << a.intersezione(b) << endl;
  cout << a.differenza(b) << endl;

  // copia
  Insieme<int> c = b;
  cout << b << endl;

  if (!b.vuoto())
    b.svuota();
  cout << b << endl;

  return 0;
}
