/* Determinare se una parola letta da input è palindroma */

#include <cstdio>
#include <iostream>
#include <string>

constexpr int maxdim = 30;

void leggi_array(char[], int &);
bool palindroma(char[], int);

int main() {
  char word[maxdim];
  int size = 0;
  leggi_array(word, size);

  if (palindroma(word, size))
    printf("%s è palindroma.\n", word);
  else
    printf("%s non è palindroma.\n", word);

  return 0;
}

bool palindroma(char parola[], int dim) {
  // (dim - i) oppure (dim / 2) sono usabili come limite per i
  for (unsigned i = 0; i < dim / 2; ++i)
    if (parola[i] != parola[dim - i - 1])
      return false;
  return true;
}

void leggi_array(char parola[], int &dim) {
  char c;
  dim = 0;
  std::cout << "Inserisci la parola terminata da un punto" << std::endl;
  std::cin >> c;
  while ((c != '.') && (dim < maxdim)) {
    parola[dim] = c;
    dim++;
    std::cin >> c;
  }
}
