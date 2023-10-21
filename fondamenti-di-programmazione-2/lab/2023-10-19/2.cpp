#include <vector>
using std::vector;

#include <iostream>
using std::cin, std::cout, std::endl;

template <class T>
void printSequenza(vector<T> s, const unsigned inizio,
                   typename vector<T>::size_type fine) {
  cout << '[';
  for (decltype(fine) i = 0; i < fine; i++) {
    cout << s[i];
    if (i != fine - 1)
      cout << ", ";
  }
  cout << ']' << endl;
}

int main() {
  // PRIMO PUNTO
  vector<char> sequenza;
  char input;
  while (cin >> input && input != '0')
    sequenza.push_back(input);

  // SECONDO PUNTO
  printSequenza(sequenza, 0, sequenza.size());

  // TERZO PUNTO
  bool trovata = false;
  for (decltype(sequenza.size()) i = 0; not trovata and i < sequenza.size();
       i++) {

    char fondamenti[] = "fondamenti";
    if (sequenza[i] == fondamenti[0]) {
      trovata = true;
      const unsigned lunghezza_fondamenti = 10;
      for (decltype(i) j = 0;
           j < lunghezza_fondamenti and i + j < sequenza.size(); j++) {
        if (sequenza[j + i] != fondamenti[j]) {
          trovata = false;
          break;
        }
      }
    }

    char programmazione[] = "programmazione";
    if (not trovata and sequenza[i] == programmazione[0]) {
      trovata = true;
      const unsigned lunghezza_programmazione = 14;
      for (decltype(i) j = 0;
           j < lunghezza_programmazione and i + j < sequenza.size(); j++) {
        if (sequenza[j + i] != programmazione[j]) {
          trovata = false;
          break;
        }
      }
    }

    const unsigned lunghezza_oggetti = 7;
    char oggetti[] = "oggetti";
    if (not trovata and sequenza[i] == oggetti[0]) {
      trovata = true;
      for (decltype(i) j = 0; j < lunghezza_oggetti and i + j < sequenza.size();
           j++) {
        if (sequenza[j + i] != oggetti[j]) {
          trovata = false;
          break;
        }
      }
    }
  }

  if (trovata)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  // QUARTO PUNTO

  const char fortuna[] = "fortuna";
  bool contenuta = true;
  for (unsigned i = 0; i < 7; i++) {
    bool carattereContenuto = false;
    for (decltype(sequenza.size()) j = 0; j < sequenza.size(); j++) {
      if (fortuna[i] == sequenza[j]) {
        carattereContenuto = true;
        break;
      }
    }

    if (!carattereContenuto) {
      contenuta = false;
      break;
    }
  }

  if (contenuta)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  // QUINTO PUNTO

  auto it = sequenza.begin();
  while (it < sequenza.end()) {
    bool erased = false;
    const char vocali[] = "aeiouAEIOU";
    for (char vocale : vocali)
      if (*it == vocale) {
        sequenza.erase(it);
        erased = true;
      }

    // L'iteratore avanza solo quando non è stato rimosso nessun elemento
    if (not erased)
      ++it;
  }

  printSequenza(sequenza, 0, sequenza.size());

  return 0;
}
