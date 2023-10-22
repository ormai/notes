#include <iostream>
using std::ostream, std::istream, std::cin, std::cout, std::endl;

class EsameSuperato {
public:        // forse era meglio una struct
  unsigned id; // chiave primaria
  unsigned voto;
  unsigned cfu;
};

class Studente {
public:
  Studente() {}
  Studente(const unsigned _matricola, const unsigned _eta)
      : numero_esami_superati(0), esami_superati{}, totale_cfu(0) {
    matricola = _matricola;
    eta = _eta;
  }

  // Getters
  unsigned get_matricola() const { return matricola; }
  unsigned get_eta() const { return eta; }
  unsigned get_numero_esami_superati() const { return numero_esami_superati; }
  unsigned get_totale_cfu() const { return totale_cfu; }

  // Setters
  void set_matricola(const unsigned _matricola) { matricola = _matricola; }
  void set_eta(const unsigned _eta) { eta = _eta; }
  void set_numero_esami_superati(const unsigned _numero_esami_superati) {
    numero_esami_superati = _numero_esami_superati;
  }

  // Metodi generici

  void aggiungiEsame(unsigned id_esame, unsigned voto, unsigned cfu);
  float getMediaPonderata() const;

  int getVotoI(unsigned i) const {
    return -1 ? i > numero_esami_superati : esami_superati[i - 1].voto;
  }

  unsigned numeroEsamiAllaLaurea() const {
    return ESAMI_TOTALI - numero_esami_superati;
  }

  bool studenteMeritevole() const;

  // Operators
  bool operator>=(const Studente &studente) {
    return true ? getMediaPonderata() >= studente.getMediaPonderata() : false;
  }

  bool operator<=(const Studente &studente) {
    return true ? getMediaPonderata() <= studente.getMediaPonderata() : false;
  }
  bool operator>(const Studente &studente) {
    const unsigned lhs_media_ponderata = getMediaPonderata(),
                   rhs_media_ponderata = studente.getMediaPonderata();

    if ((lhs_media_ponderata > rhs_media_ponderata) ||
        (lhs_media_ponderata == rhs_media_ponderata &&
         totale_cfu > studente.get_totale_cfu()) ||
        (totale_cfu == studente.get_totale_cfu() && eta > studente.get_eta()))
      return true;

    return false;
  }
  bool operator<(const Studente &studente) {
    const unsigned lhs_media_ponderata = getMediaPonderata(),
                   rhs_media_ponderata = studente.getMediaPonderata();

    if ((lhs_media_ponderata < rhs_media_ponderata) ||
        (lhs_media_ponderata == rhs_media_ponderata &&
         totale_cfu < studente.get_totale_cfu()) ||
        (totale_cfu == studente.get_totale_cfu() && eta < studente.get_eta()))
      return true;

    return false;
  }
  bool operator==(const Studente &studente) {
    if (totale_cfu == studente.get_totale_cfu() &&
        getMediaPonderata() == studente.getMediaPonderata() &&
        eta == studente.get_eta())
      return true;
    return false;
  }
  bool operator!=(const Studente &studente) {
    if (totale_cfu != studente.get_totale_cfu() &&
        getMediaPonderata() != studente.getMediaPonderata() &&
        eta != studente.get_eta())
      return true;
    return false;
  }

  friend ostream &operator<<(ostream &, Studente &);
  friend istream &operator>>(istream &, Studente &);

private:
  unsigned matricola;
  unsigned eta;

  static const unsigned ESAMI_TOTALI = 24;
  unsigned numero_esami_superati;
  EsameSuperato esami_superati[ESAMI_TOTALI];
  unsigned totale_cfu;
};

ostream &operator<<(ostream &os, Studente &studente) {
  os << "__________________________________________________________\n"
     << "Matricola: " << studente.matricola << '\n'
     << "Età: " << studente.eta << '\n'
     << "Esami sostenuti: " << studente.numero_esami_superati << '\n';

  if (studente.numero_esami_superati > 0) {
    for (int i = 0; i < studente.numero_esami_superati; ++i) {
      if (studente.esami_superati[i].id < 10)
        os << "   ";
      else if (studente.esami_superati[i].id < 100)
        os << "  ";
      else if (studente.esami_superati[i].id < 1000)
        os << " ";

      os << studente.esami_superati[i].id << " | "
         << studente.esami_superati[i].voto << " | ";

      if (studente.esami_superati[i].cfu < 10)
        os << ' ';
      os << studente.esami_superati[i].cfu << '\n';
    }
  }
  return os;
}

istream &operator>>(istream &is, Studente &studente) {
  unsigned matricola, eta;
  cout << "Matricola: ";
  cin >> matricola;
  cout << "Età: ";
  cin >> eta;

  studente.set_matricola(matricola);
  studente.set_eta(eta);
  return is;
}

void Studente::aggiungiEsame(unsigned _id_esame, unsigned _voto,
                             unsigned _cfu) {
  for (int i = 0; i < numero_esami_superati; ++i)
    if (esami_superati[i].id == _id_esame)
      return; // l'esame già esiste

  esami_superati[numero_esami_superati].id = _id_esame;
  esami_superati[numero_esami_superati].voto = _voto;
  esami_superati[numero_esami_superati].cfu = _cfu;

  totale_cfu += _cfu;
  ++numero_esami_superati;
}

float Studente::getMediaPonderata() const {
  float somma_parziale = 0;
  for (int i = 0; i < numero_esami_superati; i++)
    somma_parziale += (esami_superati[i].voto * esami_superati[i].cfu);

  return (somma_parziale / totale_cfu);
}

bool Studente::studenteMeritevole() const {
  return true ? getMediaPonderata() >= 28.00 && eta < 21 && totale_cfu >= 30
              : false;
}

int main() {
  // TESTING
  Studente WalterBianchi(869430, 20);
  WalterBianchi.aggiungiEsame(138, 27, 6);
  WalterBianchi.aggiungiEsame(745, 29, 6);
  WalterBianchi.aggiungiEsame(93, 18, 12);
  WalterBianchi.aggiungiEsame(34, 21, 9);

  cout << WalterBianchi << endl;
  cout << WalterBianchi.getMediaPonderata() << endl;
  cout << WalterBianchi.get_numero_esami_superati() << endl;
  cout << WalterBianchi.numeroEsamiAllaLaurea() << endl;
  cout << WalterBianchi.getVotoI(3) << endl;

  Studente JohnDoe(569369, 25);
  JohnDoe.aggiungiEsame(524, 23, 6);
  JohnDoe.aggiungiEsame(962, 25, 9);
  JohnDoe.aggiungiEsame(125, 30, 12);
  cout << JohnDoe << endl;

  if (JohnDoe > WalterBianchi)
    cout << "John rules!" << endl;

  return 0;
}
