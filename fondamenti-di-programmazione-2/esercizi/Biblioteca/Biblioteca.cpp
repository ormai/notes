#include "Biblioteca.hpp"

/* Classe Biblioteca */

Biblioteca::Biblioteca(initializer_list<Libro> libri,
                       initializer_list<Cliente> clienti)
    : scaffale(libri), tesserati(clienti) {}

void Biblioteca::aggiungiLibro(const Libro &libro) {
  scaffale.push_back(libro);
}

void Biblioteca::rimuoviLibro(const vector<Libro>::size_type index) {
  vector<Libro>::iterator it = scaffale.begin();
  advance(it, index);
  scaffale.erase(it);
}

Libro *Biblioteca::cercaLibro(const Libro &libro) {
  vector<Libro>::iterator e =
      std::find(scaffale.begin(), scaffale.end(), libro);

  if (e == scaffale.end())
    return nullptr;

  return &*e;
}

vector<Libro>::size_type Biblioteca::stampaScaffale() const {
  for (vector<Libro>::size_type i = 0; i < scaffale.size(); ++i)
    cout << '\t' << i + 1 << ": " << scaffale[i].getIsbn() << ", "
         << scaffale[i].getTitolo() << '\n';
  return scaffale.size();
}

vector<Libro>::size_type Biblioteca::stampaTesserati() const {
  for (vector<Cliente>::size_type i = 0; i < tesserati.size(); ++i) {
    cout << '\t' << i + 1 << ": " << tesserati[i].getId() << ", "
         << tesserati[i].getNome() << '\n';
  }
  return scaffale.size();
}

void Biblioteca::aggiungiCliente(const Cliente &cliente) {
  tesserati.push_back(cliente);
}

void Biblioteca::rimuoviCliente(const vector<Cliente>::size_type index) {
  vector<Cliente>::iterator it = tesserati.begin();
  advance(it, index);
  tesserati.erase(it);
}

Cliente *Biblioteca::cercaCliente(const Cliente &cliente) {
  vector<Cliente>::iterator e =
      std::find(tesserati.begin(), tesserati.end(), cliente);

  if (e == tesserati.end())
    return nullptr;

  return &*e;
}

bool Biblioteca::aggiungiPresito(const Libro &libro, const Cliente &cliente) {
  registroPrestiti.insert({libro, cliente});

  find(scaffale.begin(), scaffale.end(), libro)->setDisponibile(false);
  find(tesserati.begin(), tesserati.end(), cliente)->setEleggibile(false);

  /* Il caso in cui il libro non sia disponibile o che il cliente non sia
   * eleggibile non sussiste dato che Biblioteca::prestabili() e
   * Biblioteca::eleggibili() escludono entrambi i casi. */
  return true; // :)
}

void Biblioteca::riconsegna(const Libro &libro) {
  // libro è solo una copia
  find(scaffale.begin(), scaffale.end(), libro)->setDisponibile(true);
  find(tesserati.begin(), tesserati.end(), registroPrestiti[libro])
      ->setEleggibile(true);

  registroPrestiti.erase(libro);
}

void Biblioteca::stampaLibriPrestati() const {
  for (auto it = registroPrestiti.begin(); it != registroPrestiti.end(); ++it)
    cout << it->first.getTitolo() << " è stato prestato a "
         << it->second.getNome() << '\n';
}

void Biblioteca::stampaClientiConLibroInPrestito() const {
  for (auto it = registroPrestiti.begin(); it != registroPrestiti.end(); ++it)
    cout << it->second.getNome() << " ha preso in prestito "
         << it->first.getTitolo() << '\n';
}

vector<Libro> Biblioteca::prestati() const {
  vector<Libro> prestati;
  unsigned count = 0;
  for (vector<Libro>::size_type i = 0; i < scaffale.size(); ++i)
    if (!scaffale[i].getDisponibile()) {
      cout << '\t' << ++count << ": " << scaffale[i].getIsbn() << ", "
           << scaffale[i].getTitolo() << '\n';
      prestati.push_back(scaffale[i]);
    }
  return prestati;
}

vector<Libro> Biblioteca::prestabili() const {
  vector<Libro> disponibili;
  unsigned count = 0;
  for (vector<Libro>::size_type i = 0; i < scaffale.size(); ++i)
    if (scaffale[i].getDisponibile()) {
      cout << '\t' << ++count << ": " << scaffale[i].getIsbn() << ", "
           << scaffale[i].getTitolo() << '\n';
      disponibili.push_back(scaffale[i]);
    }
  return disponibili;
}

vector<Cliente> Biblioteca::clientiEleggibili() const {
  vector<Cliente> elegibili;
  unsigned count = 0;
  for (vector<Cliente>::size_type i = 0; i < tesserati.size(); ++i)
    if (tesserati[i].getEleggibile()) {
      cout << '\t' << ++count << ": " << tesserati[i].getId() << ", "
           << tesserati[i].getNome() << '\n';
      elegibili.push_back(tesserati[i]);
    }
  return elegibili;
}

/* Classe Libro */
Libro::Libro(const string &_isbn, const string &_titolo,
             const vector<string> &_autori, const string &_casaEditrice)
    : isbn(_isbn), titolo(_titolo), autori(_autori),
      casaEditrice(_casaEditrice) {}

void Libro::setDisponibile(const bool _disponibile) {
  disponibile = _disponibile;
}

bool Libro::operator==(const Libro &rhs) const {
  return isbn == rhs.isbn && titolo == rhs.titolo;
}

string Libro::getIsbn() const { return isbn; }
string Libro::getTitolo() const { return titolo; }
bool Libro::getDisponibile() const { return disponibile; }
bool Libro::operator<(const Libro &rhs) const {
  return (titolo < rhs.getTitolo());
}

/* Classe Cliente */

Cliente::Cliente(const unsigned &_id, const string &_nome)
    : id(_id), nome(_nome) {}

Cliente::Cliente(const Cliente &cliente) {
  id = cliente.id;
  nome = cliente.nome;
  eleggibile = cliente.eleggibile;
}

string Cliente::getNome() const { return nome; }
unsigned Cliente::getId() const { return id; }
bool Cliente::getEleggibile() const { return eleggibile; }
void Cliente::setEleggibile(const bool &_eleggibile) {
  eleggibile = _eleggibile;
}

bool Cliente::operator==(const Cliente &rhs) const { return id == rhs.id; }
