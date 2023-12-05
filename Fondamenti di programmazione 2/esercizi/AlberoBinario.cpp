#ifndef ALBERO_BINARIO
#define ALBERO_BINARIO

#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <string>

/* - Classe AlberoBinario
 * - Funzione profondita
 * - Funzione bilanciato
 * - Funzione profonditaBilanciato
 * - Funzione cerca
 * - Funzione leggi
 * - Funzione somma */

enum Direzione { sinistra = 0, destra = 1 };

template <class T> class AlberoBinario {
  // Nodo è di tipo generico U diverso da dal tipo T dell'AlberoBinario
  template <class U> struct Nodo {
    U informazione; // Dato satellite
    // se si trattasse di un oggetto non si potrebbe fare
    Nodo *genitore = 0, *figli[2] = {0, 0};

    Nodo(const U &_informazione) : informazione(_informazione) {}

    ~Nodo() {
      delete figli[sinistra];
      delete figli[destra];
    }
  };

protected:
  Nodo<T> *radice = nullptr;

public:
  AlberoBinario() = default;
  AlberoBinario(const T &datoSatellite) : radice(new Nodo<T>(datoSatellite)) {}

  /* @return true se l'AlberoBinario non ha un nodo radice ed è quindi nullo,
   *         false altrimenti */
  bool nullo() const { return radice == nullptr; }

  /* @return true se l'AlberoBinario non ha figli,
             false altrimenti */
  bool foglia() const {
    return !nullo() && figlio(sinistra).nullo() && figlio(destra).nullo();
  }

  /* @return Il dato satellite del nodo radice */
  const T &nodoRadice() const {
    assert(!nullo());
    return radice->informazione;
  }

  /* @param destra o sinistra: quale dei due figli
   * @return Il sotto AlberoBinario figlio */
  AlberoBinario<T> &figlio(Direzione direzione) {
    assert(!nullo());
    return radice->figli[direzione];
  }

  /* @param destra o sinistra: quale dei due figli inserire
   * @param L'AlberoBinario da inserire come figlio.
   * @return il sotto albero appena inserito così da permettere una catena di
   *         inserimenti. */
  AlberoBinario<T> &inserisciFiglio(Direzione direzione,
                                    AlberoBinario<T> alberoBinario) {
    assert(!nullo());

    // il sotto nodo in cui si vuole inserire il figlio deve essere nullo
    assert(figlio(direzione).nullo());

    if (!alberoBinario.nullo()) {
      radice->figli[direzione] = alberoBinario.radice;
      alberoBinario.radice->genitore = radice;
    }
    return alberoBinario;
  }

  void modificaRadice(const T &nuovoValore) {
    assert(!nullo());
    radice->informazione = nuovoValore;
  }
};

/* @param L'AlberoBinario del quale si vuole conoscere la profondità
 * @return la profondità dell'albero. */
template <class T> unsigned profondita(const AlberoBinario<T> &alberoBinario) {
  if (alberoBinario.nullo())
    return 0;

  return 1 + std::max(profondita(alberoBinario.figlio(sinistra)),
                      profondita(alberoBinario.figlio(destra)));
}

/* @param L'AlberoBinario del quale si vuole sapere se è bilanciato o meno
 * @return true se l'AlberoBinario è bilanciato,
 *         false altrimenti */
template <class T> bool bilanciato(const AlberoBinario<T> &alberoBinario) {
  if (alberoBinario.nullo())
    return true;

  // le chiamate ricorsive sono troppe, troppe ripetizioni
  // complessità esponenziale
  return std::abs(profondita(alberoBinario.figlio(sinistra)) -
                  profondita(alberoBinario.figlio(destra))) <= 1 &&
         bilanciato(alberoBinario.figlio(sinistra)) &&
         bilanciato(alberoBinario.figlio(destra));
}

/* @param l'AlberoBinario del quale si vuole conosce la profondità e se è
 *        bilanciato
 * @param profondità dell'AlberoBinario restituita per riferimento nello stesso
 *        parametro
 * @return true se l'AlberoBinario è bilanciato,
 *          false altrimenti */
template <class T>
bool profonditaBilanciato(const AlberoBinario<T> &alberoBinario,
                          int &profonditaMassima) {
  if (alberoBinario.nullo()) {
    profonditaMassima = 0;
    return true;
  }

  int profonditaSinistra, profonditaDestra;

  bool bilanciatoSinistra =
      profonditaBilanciato(alberoBinario.figlio(sinistra), profonditaSinistra);
  bool bilanciatoDestra =
      profonditaBilanciato(alberoBinario.figlio(destra), profonditaDestra);

  profonditaMassima = std::max(profonditaSinistra, profonditaDestra) + 1;

  return bilanciatoSinistra && bilanciatoDestra &&
         std::abs(profonditaSinistra - profonditaDestra) <= 1;
}

/* @param l'AlberoBinario nel quale si vuole fare la ricerca
 * @param l'oggetto da cercare
 * @return AlberoBinario nullo se l'oggetto non è stato trovato, oppure il
 *         sottoAlbero la cui radice contiene l'ogetto */
template <class T>
AlberoBinario<T> cerca(const AlberoBinario<T> &alberoBinario,
                       const T &obiettivo) {
  if (alberoBinario.nullo() || alberoBinario.nodoRadice() == obiettivo)
    return alberoBinario;

  const AlberoBinario<T> sottoAlberoSinistro =
      cerca(alberoBinario.figlio(sinistra), obiettivo);

  if (!sottoAlberoSinistro.nullo())
    return sottoAlberoSinistro;

  return cerca(alberoBinario.figlio(destra), obiettivo);
}

/* @param AlberoBinario nullo da riempire
 * La lettura di ogni nodo avviene su una riga distinta e usa il formato
 * figlio:padre direzione
 * 5:10 s
 * 6:10 d */
template <class T> void leggi(AlberoBinario<T> &alberoBinario) {
  std::string input;
  bool primaRiga = true;

  // std::cout << "Inserisci nodo (figlio:padre direzione): ";
  while (std::getline(std::cin, input) && input != "-1") {
    if (primaRiga) {
      alberoBinario.modificaRadice(std::stoi(input));
      primaRiga = false;
    } else {
      std::string::size_type duePunti = input.find(':'),
                             spazio = input.find(' ');

      Direzione direzione = sinistra;
      if (input[spazio] + 1 == 'd')
        direzione = destra;

      AlberoBinario<T> nodo =
          cerca(alberoBinario,
                std::stoi(input.substr(duePunti + 1, spazio - duePunti)));

      if (!nodo.nullo()) {
        AlberoBinario<T> daInserire(std::stoi(input.substr(0, duePunti)));
        nodo.inserisciFiglio(direzione, daInserire);
      }
    }
    // std::cout << "Inserisci nodo (figlio:padre direzione): ";
  }
}

/* @param AlberoBinario
 * @return la somma dei nodi */
template <class T> int somma(const AlberoBinario<T> &alberoBinario) {
  if (alberoBinario.nullo())
    return 0;

  return alberoBinario.nodoRadice() + somma(alberoBinario.figlio(sinistra)) +
         somma(alberoBinario.figlio(destra));
}

#endif
