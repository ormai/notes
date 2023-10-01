/* Scrivere un programma che riceva in input una sequenza di dati relativi ai
 * tassi di inquinamento registrati giorno per giorno in una certa località ed
 * in un certo periodo di tempo e determini e stampi il numero dei picchi
 * massimi dell’inquinamento.
 *
 * Un picco massimo di inquinamento è un massimo relativo nella sequenza, ossia
 * un dato che è maggiore sia di quello ad esso precedente sia di quello ad
 * esso seguente. Per ogni piccolo il programma deve visualizzare il valore del
 * tasso di inquinamento ed il giorno in cui si verifica (i giorni vanno
 * contati a partire da 1). Il programma deve altresì visualizzare il numero
 * dei picchi rilevati ed il numero totale dei dati in input. Il primo e
 * l’ultimo dato non possono essere dei picchi massimi di inquinamento.
 *
 * Ad esempio, se l’input è:
 *
 * 50 100 20 3 40 60 10 20 5 40 20 60 70 50 -1
 *
 * l’output sarà:
 *
 * 100 2
 * 60 6
 * 20 8
 * 40 10
 * 70 13
 * Numero di picchi massimi rilevati: 5
 * Numero totale dei dati 14
 */

#include <iostream>
using namespace std;

int main() {
  int giorno = 2, picchi = 0, avantieri, ieri, oggi;

  if (cin >> avantieri && avantieri != -1
      && cin >> ieri && ieri != -1
      && cin >> oggi) {

    while (oggi != -1) {
      if (ieri > avantieri && ieri > oggi) {
        cout << ieri << ' ' << giorno << endl;
        ++picchi;
      }

      avantieri = ieri;
      ieri = oggi;
      cin >> oggi;

      ++giorno;
    }

    cout << "Numero di picchi massimi rilevati: " << picchi << '\n'
         << "Numero totale dei dati " << giorno << endl;
  }

  return 0;
}
