/* Dato un AlberoBinario<int> A e un intero pesoMax vericare se la somma degli
 * elementi di ciascun livello è minore o guguale a pesoMax */

#include "../AlberoBinario.cpp"
#include <queue>

bool esercizio(AlberoBinario<int> &alberoBinario, int &pesoMassimo) {
  if (alberoBinario.nullo())
    return true;

  std::queue<AlberoBinario<int>> sottoAlberi;
  std::queue<int> livelli;
  sottoAlberi.push(alberoBinario);
  livelli.push(1);

  int somma = 0, livelloCorrente = 0, livelloPrecedente = 0;

  while (!sottoAlberi.empty()) {
    AlberoBinario<int> sottoAlbero = sottoAlberi.front();
    sottoAlberi.pop();

    livelloCorrente = livelli.front();
    livelli.pop();

    if (livelloCorrente == livelloPrecedente)
      somma += sottoAlbero.nodoRadice();
    else {
      if (somma > pesoMassimo)
        return false;
      livelloPrecedente = livelloCorrente;
      somma = sottoAlbero.nodoRadice();
    }

    if (!sottoAlbero.figlio(sinistra).nullo()) {
      sottoAlberi.push(sottoAlbero.figlio(sinistra));
      livelli.push(livelloCorrente + 1);
    }

    if (!sottoAlbero.figlio(destra).nullo()) {
      sottoAlberi.push(sottoAlbero.figlio(destra));
      livelli.push(livelloCorrente + 1);
    }
  }

  return somma > pesoMassimo;
}

int main() {
  AlberoBinario<int> input(0);
  leggi(input);

  int pesoMassimo = 0;
  std::cout << "Peso massimo: ";
  std::cin >> pesoMassimo;

  std::cout << (esercizio(input, pesoMassimo) ? "ok" : "no") << std::endl;

  return 0;
}
