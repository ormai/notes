#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP

#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <vector>

using std::advance;
using std::cin;
using std::cout;
using std::getline;
using std::endl;
using std::find;
using std::initializer_list;
using std::map;
using std::pair;
using std::string;
using std::vector;

class Cliente {
private:
  unsigned id = 0;
  string nome = "";
  bool eleggibile = true; // non ha già un libro in prestito

public:
  Cliente() = default;
  Cliente(const unsigned &id, const string &nome);
  Cliente(const Cliente &cliente);

  bool operator==(const Cliente &rhs) const;

  unsigned getId() const;
  string getNome() const;
  bool getEleggibile() const;
  void setEleggibile(const bool &eleggibile);
};

class Libro {
private:
  string isbn = 0;
  string titolo = "";
  vector<string> autori = {};
  string casaEditrice = "";
  bool disponibile = true; // true: disponibile, false: in prestito

public:
  Libro(const string &isbn, const string &titolo, const vector<string> &autori,
        const string &casaEditrice);

  bool operator==(const Libro &rhs) const;
  bool operator<(const Libro &rhs) const;

  void setDisponibile(const bool _disponibile);

  string getIsbn() const;
  string getTitolo() const;
  bool getDisponibile() const;
};

class Biblioteca {
private:
  map<Libro, Cliente> registroPrestiti = {};
  vector<Libro> scaffale;
  vector<Cliente> tesserati;

public:
  Biblioteca() = default;
  Biblioteca(initializer_list<Libro> listaDiLibri,
             initializer_list<Cliente> listaDiClienti);

  void aggiungiLibro(const Libro &nuovoLibro);
  void rimuoviLibro(const vector<Libro>::size_type posizione);

  /* @param libro Elemento di scaffale che si vuole cercare
   * @return Puntatore all'elemento, se esiste, altrimenti nullptr */
  Libro *cercaLibro(const Libro &libro);

  void aggiungiCliente(const Cliente &nuovoCliente);
  void rimuoviCliente(const vector<Cliente>::size_type posizione);

  /* @param cliente Elemento di tesserati che si vuole cercare
   * @return Puntatore all'elemento, se esiste, altrimenti nullptr */
  Cliente *cercaCliente(const Cliente &cliente);

  /* @param libro: indice di un elemento di scaffale
   * @param cliente: indice di un elemento di tesserati
   * @return false se il libro o il cliente sono già nel registro
   *         true altrimenti */
  bool aggiungiPresito(const Libro &libro, const Cliente &cliente);

  /* @param libro Libro che si vuole consegnare */
  void riconsegna(const Libro &libro);

  /* Stampa i libri prestati, con indicazione del cliente */
  void stampaLibriPrestati() const;

  /* Stampa i clienti che hanno preso un libro in prestito, con indicazione del
   * libro */
  void stampaClientiConLibroInPrestito() const;

  /* Stampa i campi isbn e titolo di ogni Libro in scaffale con un indice come
   * prefisso.
   * @return Numero di elementi in scaffale */
  vector<Libro>::size_type stampaScaffale() const;

  /* Stampa i campi id e nome di ogni Cliente in tesserati con un indice come
   * prefisso.
   * @return Numero di elementi di tesserati */
  vector<Cliente>::size_type stampaTesserati() const;

  /* Crea una copia di scaffale che contiene solo i Libri non disponibili. Allo
   * stesso tempo stampa questi libri. */
  vector<Libro> prestati() const;

  /* Crea una copia di scaffale che contiene solo i Libri disponibili. Allo
   * stesso tempo stampa questi libri. */
  vector<Libro> prestabili() const;

  /* Crea una copia di tesserati che contiene solo i Clienti che non hanno
   * già preso un libro in prestito, ovvero sono 'eleggibili'. */
  vector<Cliente> clientiEleggibili() const;
};

#endif
