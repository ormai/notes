// Individuare il massimo e il submassimo tra 10 numeri positivi letti da input.
// submassimo: il secondo massimo

#include <iostream>

int main() {
  int max, submax, curr;

  // inizializza max e submax e assicurati che non siano invertiti
  if (std::cin >> max && std::cin >> submax) {
    if (submax > max) {
      max += submax;
      submax = max - submax;
      max -= submax;
    }
  } else
    return -1;

  // elabora i restanti otto valori
  for (int i = 0; i < 8; ++i) {
    if (std::cin >> curr) {
      if (curr > max) {
        submax = max;
        max = curr;
      } else if (curr > submax)
        submax = curr;
    } else
      return -1;
  }

  std::cout << "Il massimo è: " << max << '\n'
            << "Il submassimo è: " << submax << std::endl;

  return 0;
}
