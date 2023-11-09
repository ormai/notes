#include <initializer_list>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

struct Documento {
  std::string nome = "";
  unsigned pagine = 0;
  bool bn = true;
};

struct menoPagine {
  bool operator()(const Documento &l, const Documento &r) const {
    return l.pagine > r.pagine;
  }
};

class Stampante {
  // std::queue<Documento> lavori = {};
  std::priority_queue<Documento, std::vector<Documento>, menoPagine> lavori;

public:
  Stampante() = default;
  Stampante(std::initializer_list<Documento> docs) {
    for (Documento doc : docs)
      lavori.push(doc);
  }

  void aggiungiStampa(const Documento &doc) { lavori.push(doc); }

  void stampa() {

    for (int i = 0; i <= lavori.size(); ++i) {
      Documento doc = lavori.top();
      std::cout << "---------------------------------\n"
                << "Nome: " << doc.nome << '\n'
                << "Numero di pagine: " << doc.pagine << '\n'
                << "Colori: " << (doc.bn ? "no" : "si") << '\n';

      lavori.pop();
    }
  }
};

int main() {
  Stampante s = {{"compiti.pdf", 3}, {"brocure.tif", 1, false}};
  s.stampa();

  s.aggiungiStampa({"BilancioMicrosoft.pdf", 86, false});
  s.aggiungiStampa({"RelazioneLaboratorio.docx", 5, true});
  s.stampa();

  return 0;
}
