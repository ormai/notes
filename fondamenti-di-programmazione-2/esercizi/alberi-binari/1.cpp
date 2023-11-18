/* Dato un albero binario di interi scrivere una funzione che restituisca true
 * se vale la seguente condizione: per ogni nodo, il valore della radice è
 * maggiore della somma dei valori nel sotto albero sinistro più la somma dei
 * valori del sotto albero destro. */

#include "../AlberoBinario.cpp"

bool esercizio(AlberoBinario<int> alberoBinario, int &sommaParziale) {
  if (alberoBinario.nullo()) {
    sommaParziale = 0;
    return true;
  }

  int sommaSinistra, sommaDestra;
  bool esercizioSinistra, esercizioDestra;

  esercizioSinistra = esercizio(alberoBinario.figlio(sinistra), sommaSinistra);
  esercizioDestra = esercizio(alberoBinario.figlio(destra), sommaDestra);

  sommaParziale = alberoBinario.nodoRadice() + sommaSinistra + sommaDestra;

  std::cout << sommaParziale << std::endl;

  return alberoBinario.nodoRadice() > sommaSinistra + sommaDestra &&
         esercizioSinistra && esercizioDestra;
}

int main() {
  AlberoBinario<int> input(0);
  leggi(input);

  int somma = 0;

  std::cout << (esercizio(input, somma) ? "ok" : "no") << std::endl;

  return 0;
}
