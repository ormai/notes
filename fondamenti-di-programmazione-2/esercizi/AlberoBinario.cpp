#ifndef ALBERO_BINARIO
#define ALBERO_BINARIO

#include <cassert>
#include <cmath>

enum Direzione { sinistra = 0, destra = 1 };

template <class T> class AlberoBinario {
  // Nodo è di tipo generico U diverso da dal tip T dell'AlberoBinario
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

  /* Il tipo dell'albero T è usato per costruire un nodo di tipo T
   * i tipi T e U vengono associati. */
  AlberoBinario(const T &a) { radice = new Nodo<T>(a); }

  /* @return true se l'AlberoBinario non ha un nodo radice ed è quindi nullo,
   *         false altrimenti */
  bool nullo() { return radice == nullptr; }

  /* @return true se l'AlberoBinario non ha figli,
             false altrimenti */
  bool foglia() {
    return !nullo() && figlio(sinistra).nullo() && figlio(destra).nullo();
  }

  /* @return Il dato satellite del nodo radice */
  const T &nodoRadice() const {
    assert(!nullo());
    return radice->informazione;
  }

  /* @param destra o sinistra: quale dei due figli
   * @return Il sotto AlberoBinario figlio */
  AlberoBinario<T> figlio(Direzione direzione) const {
    assert(!nullo());
    AlberoBinario<T> tmp;
    tmp.radice->figli[direzione];
    return tmp;
  }

  /* @param destra o sinistra: quale dei due figli inserire
   * @param L'AlberoBinario da inserire come figlio. */
  void inserisciFiglio(Direzione direzione, AlberoBinario<T> &alberoBinario) {
    assert(!nullo());

    // il sotto nodo in cui si vuole inserire il figlio deve essere nullo
    assert(figlio(direzione).nullo());

    if (!alberoBinario.nullo()) {
      radice->figli[direzione] = alberoBinario.radice;
      alberoBinario.radice->genitore = radice;
    }
  }
};

/* @param L'AlberoBinario del quale si vuole conoscere la profondità
 * @return la profondità dell'albero. */
template <class T> unsigned profondita(AlberoBinario<T> alberoBinario) {
  if (alberoBinario.nullo())
    return 0;

  unsigned profonditaSinistra = profondita(alberoBinario.figlio(sinistra)),
           profonditaDestra = profondita(alberoBinario.figlio(destra));

  return (profonditaSinistra > profonditaDestra) ? profonditaSinistra + 1
                                                 : profonditaDestra + 1;
}

/* @param L'AlberoBinario del quale si vuole sapere se è bilanciato o meno
 * @return true se l'AlberoBinario è bilanciato,
 *         false altrimenti */
template <class T> bool bilanciato(AlberoBinario<T> alberoBinario) {
  if (alberoBinario.nullo())
    return true;

  // le chiamate ricorsive sono troppe, troppe ripetizioni
  // complessità esponenziale
  return std::abs(profondita(alberoBinario.figlio(sinistra)) -
                  profondita(alberoBinario.figlio(destra))) <= 1 &&
         balanced(alberoBinario.figlio(sinistra)) &&
         balanced(alberoBinario.figlio(destra));
}

/* @param l'AlberoBinario del quale si vuole conosce la profondità e se è
 *        bilanciato
 * @param profondità dell'AlberoBinario restituita per riferimento nello stesso
 *        parametro
 * @return true se l'AlberoBinario è bilanciato,
 *          false altrimenti */
template <class T>
bool profonditaBilanciato(AlberoBinario<T> alberoBinario,
                          unsigned &profonditaMassima) {
  if (alberoBinario.nullo()) {
    profonditaMassima = 0;
    return true;
  }

  int profonditaSinistra, profonditaDestra;

  bool bilanciatoSinistra = profonditaBilanciato(alberoBinario.figlio(sinistra),
                                                 profonditaSinistra),
       bilanciatoDestra =
           profonditaBilanciato(alberoBinario.figlio(destra), profonditaDestra);

  // restituisci nel parametro
  profonditaMassima = std::max(profonditaSinistra, profonditaDestra) + 1;

  return bilanciatoSinistra && bilanciatoDestra &&
         std::abs(profonditaSinistra - profonditaDestra) <= 1;
}

#endif
