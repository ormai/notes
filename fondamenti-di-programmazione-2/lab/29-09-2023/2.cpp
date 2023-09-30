/* Una famiglia S di insiemi di interi positivi può essere rappresentata da una
 * sequenza di interi seq(S), terminata da -1, in cui ogni insieme della
 * famiglia è separato dal successivo da uno 0.
 *
 * Esempio: la famiglia {{7, 3}, {5, 1, 7, 4}, {2}, {}, {3, 9}} è rappresentata
 * dalla sequenza 7,3,0,5,1,7,4,0,2,0,0,3,9,0,-1.
 *
 * Quesito 1. Si scriva un programma C++ che, letta una tale sequenza seq(S):
 * • fornisca in uscita la cardinalità della famiglia (cioè il numero degli
 *   insiemi che essa contiene); nell’esempio evidenziato sopra, il programma
 *   dovrebbe restituire 5;
 * • fornisca in uscita la cardinalità massima degli insiemi della famiglia;
 *   nell’esempio evidenziato sopra, il programma dovrebbe restituire 4;
 *
 * Quesito 2. Assumendo che la sequenza seq(S) contenga al più 100 interi, si
 * scriva un programma C++ che legga la sequenza, eventualmente la memorizzi,
 * e, assumendo di aver memorizzato nella variabile card_max, la massima
 * cardinalità degli insiemi della famiglia, fornisca in uscita l’insieme di S
 * di cardinalità massima.
 */

#include <iostream>
using namespace std;

int main() {
  int cardFamiglia = 0, cardInsieme = 0, maxCardInsieme, curr;

  while (cin >> curr && curr != -1) {
    if (curr == 0) {
      if (cardInsieme > maxCardInsieme)
        maxCardInsieme = cardInsieme;

      cardInsieme = 0;
      ++cardFamiglia;
    } else {
      ++cardInsieme;
    }
  }

  cout << cardFamiglia << "\n"
       << maxCardInsieme << endl;

  return 0;
}
