// Individuare il massimo e il submassimo tra 10 numeri positivi letti da input.
// submassimo: il secondo massimo

#include <iostream>
using namespace std;
int main() {
  int max, submax, curr;

  // inizializza max e submax e assicurati che non siano invertiti
  if (cin >> max && cin >> submax) {
    if (submax > max) {
      int tmp = max;
      max = submax;
      submax = tmp; // swap
    }
  } else
    return -1;

  // elabora i restanti otto valori
  for (int i = 0; i < 8; ++i) {
    if (cin >> curr) {
      if (curr > max) {
        submax = max;
        max = curr;
      } else if (curr > submax) {
        submax = curr;
      }
    } else
      return -1;
  }

  cout << "Il massimo è: " << max << '\n'
       << "Il submassimo è: " << submax << endl;

  return 0;
}
