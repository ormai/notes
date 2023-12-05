#include <vector>
using std::vector;

#include <iostream>
using std::cout, std::endl;

class Programmatore {
  unsigned id{0};
  unsigned eta{0};
  unsigned stipendio{0};
  unsigned anni_esperienza{0};
  bool senior{false};

public:
  Programmatore() = default;
  Programmatore(const unsigned &_id, const unsigned &_eta,
                const unsigned &_stipendio, const unsigned &_anni_esperienza,
                const bool &_senior)
      : id(_id), eta(_eta), stipendio(_stipendio),
        anni_esperienza(_anni_esperienza), senior(_senior) {}

  // Getters
  unsigned get_id() const { return id; }
  unsigned get_eta() const { return eta; }
  unsigned get_stipendio() const { return stipendio; }
  unsigned get_anni_esperienza() const { return anni_esperienza; }
  bool get_senior() const { return senior; }

  // Setters
  void set_id(const unsigned _id) { id = _id; }
  void set_eta(const unsigned _eta) { eta = _eta; }
  void set_stipendio(const unsigned _stipendio) { stipendio = _stipendio; }
  void set_anni_esperienza(const unsigned _anni_esperienza) {
    anni_esperienza = _anni_esperienza;
  }
  void set_senior(const bool _senior) { senior = _senior; }

  bool operator==(const Programmatore &p) { return (id == p.id); }
  bool operator!=(const Programmatore &p) { return (id != p.id); }
};

class GestoreProgrammatori {
  vector<Programmatore> programmatori{};

public:
  GestoreProgrammatori() = default;
  GestoreProgrammatori(const vector<Programmatore> &vp) : programmatori(vp) {}

  void assumiProgrammatore(const Programmatore &p);
  void licenziaProgrammatore(const Programmatore &p);
  float getMaxStipendioPerCategoria(bool senior) const;
  const Programmatore &getSeniorMenoEsperto() const;
  unsigned promuoviASenior();
};

void GestoreProgrammatori::assumiProgrammatore(const Programmatore &p) {
  programmatori.push_back(p);
}

void GestoreProgrammatori::licenziaProgrammatore(const Programmatore &p) {
  for (auto it = programmatori.begin(); it < programmatori.end(); ++it) {
    if (*it == p) {
      programmatori.erase(it);
      return;
    }
  }
}

float GestoreProgrammatori::getMaxStipendioPerCategoria(bool senior) const {
  float max = 0;
  for (auto it = programmatori.begin(); it < programmatori.end(); ++it)
    if (it->get_senior() == senior) {
      unsigned s = it->get_stipendio();
      if (s > max)
        max = s;
    }

  return max;
}

const Programmatore &GestoreProgrammatori::getSeniorMenoEsperto() const {
  unsigned min = 100; // anni di esperienza
  unsigned minPos = 0;
  for (unsigned i = 1; i < programmatori.size(); ++i) {
    unsigned e = programmatori[i].get_anni_esperienza();
    if (programmatori[i].get_senior() && e < min) {
      min = e;
      minPos = i;
    }
  }
  return programmatori[minPos];
}

unsigned GestoreProgrammatori::promuoviASenior() {
  unsigned conteggioPromozione = 0;
  unsigned menoEsperto = getSeniorMenoEsperto().get_anni_esperienza();

  cout << "ciao" << menoEsperto << endl;

  for (unsigned i = 0; i < programmatori.size(); ++i) {
    Programmatore p = programmatori[i];
    if (!p.get_senior() && p.get_anni_esperienza() >= menoEsperto) {
      p.set_senior(true);
      ++conteggioPromozione;
    }
  }

  return conteggioPromozione;
}

int main() {
  // TESTING
  GestoreProgrammatori manager;

  Programmatore Aldo(936, 32, 65000, 6, false),
      Giovanni(410, 44, 148000, 20, true), Giacomo(772, 35, 76000, 10, true);

  manager.assumiProgrammatore(Aldo);
  manager.assumiProgrammatore(Giovanni);
  manager.assumiProgrammatore(Giacomo);

  cout << manager.getMaxStipendioPerCategoria(true) << endl;
  cout << manager.getMaxStipendioPerCategoria(false) << endl;

  cout << manager.getSeniorMenoEsperto().get_id() << endl;

  cout << manager.promuoviASenior() << endl;

  manager.licenziaProgrammatore(manager.getSeniorMenoEsperto());

  return 0;
}
