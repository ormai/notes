#include <iostream>
using std::ostream, std::cout, std::cin, std::endl;

#include <cstring>
using std::strlen, std::strcpy;

class Esercizio {
  int id;
  char *descrizione;
  int difficolta;

public:
  Esercizio(){};
  Esercizio(int, char *, int);
  int get_id() const { return id; }
  char *get_descrizione() const { return descrizione; }
  int get_difficolta() const { return difficolta; }
  bool operator<(Esercizio &e) { return difficolta < e.difficolta; }
};

ostream &operator<<(ostream &os, const Esercizio &e) {
  char istogrammaDifficolta[e.get_difficolta()];

  for (char &c : istogrammaDifficolta)
    c = '*';

  os << '[' << e.get_id() << ", " << e.get_descrizione() << ", "
     << istogrammaDifficolta << ']';
  return os;
}

Esercizio::Esercizio(int _id, char *_descrizione, int _difficolta) {
  id = _id;

  descrizione = new char[strlen(_descrizione)];
  strcpy(descrizione, _descrizione);

  difficolta = _difficolta;
};

struct quesitoEsame {
  Esercizio esercizio;
  int ripetizioni;
};

class BancaDatiEsercizi {
  quesitoEsame elenco[1000];
  int dim;

  bool esiste(int);
  void inserisci_in_ordine(Esercizio &, Esercizio *, int, int &);
  void aggiornaRipetizioni(const Esercizio &);

public:
  BancaDatiEsercizi() : dim(0) {}

  bool aggiungiEsercizio(Esercizio);
  bool creaEsame(int, int, int, Esercizio *);
};

bool BancaDatiEsercizi::esiste(int id) {
  for (int i = 0; i < dim; i++) {
    if (elenco[i].esercizio.get_id() == id)
      return true;
  }
  return false;
}

bool BancaDatiEsercizi::aggiungiEsercizio(Esercizio e) {
  if (!esiste(e.get_id())) {
    elenco[dim].esercizio = e;
    elenco[dim].ripetizioni = 0;
    dim++;
    return true;
  }
  return false;
}

void BancaDatiEsercizi::inserisci_in_ordine(Esercizio &e, Esercizio *candidati,
                                            int nCandidati, int &size) {
  int j = size - 1;

  while (j >= 0 && e.get_difficolta() < candidati[j].get_difficolta()) {
    while (j >= 0 && e < candidati[j]) {
      candidati[j + 1] = candidati[j];
      j--;
    }
    candidati[j + 1] = e;
    size++;
  }
}

bool BancaDatiEsercizi::creaEsame(int n, int diff_M, int rep_M,
                                  Esercizio *esame) {
  // FASE 1: estrai gli esercizi con rep < rep_M
  Esercizio *candidati = new Esercizio[dim];
  int nCandidati = 0;
  for (int i = 0; i < dim; i++)
    if (elenco[i].ripetizioni < rep_M)
      inserisci_in_ordine(elenco[i].esercizio, candidati, nCandidati, dim);

  // FASE 2: inserisci controllando diff_M
  int difficolta = 0, esamiInseriti = 0, i = 0;

  delete[] esame; // per essere sicuro che sia pulito
  esame = new Esercizio[n];

  while (esamiInseriti < n && i < dim) {
    int difficoltaCorrente = candidati[i].get_difficolta();
    if ((difficoltaCorrente + difficolta) < diff_M) {
      esame[esamiInseriti++] = candidati[i++];
      difficolta += difficoltaCorrente;
    } else
      i++;
  }

  delete[] candidati;

  // FASE 3: verifica se sei riuscito a creare l'esame

  if (esamiInseriti != n) {
    delete[] esame;
    return false;
  } else {
    for (int i = 0; i < n; i++)
      aggiornaRipetizioni(esame[i]);
    return true;
  }
}

void BancaDatiEsercizi::aggiornaRipetizioni(const Esercizio &e) {
  for (int i = 0; i < dim; i++) {
    if (elenco[i].esercizio.get_id() == e.get_id()) {
      elenco[i].ripetizioni++;
      return;
    }
  }
}

int main() {
  // TEST
  BancaDatiEsercizi b;

  Esercizio numeriTriangolari(93, "Numeri triangolari", 5);

  cout << numeriTriangolari << endl;

  b.aggiungiEsercizio(numeriTriangolari);
}
