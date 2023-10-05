/* Determinare se una parola letta da input è palindroma */

#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

const int maxdim = 30;

void leggi_array(char[], int&);
bool palindroma(char[], int);

int main () {
  char V[maxdim];
  int dim = 0;
  leggi_array(V, dim);

  if (palindroma(V, dim))
    printf("%s è palindroma.\n", V);
  else
    printf("%s non è palindroma.\n", V);
}

bool palindroma(char parola[], int dim) {
  // (dim - i) oppure (dim / 2) sono usabili come limite per i
  for (int i = 0; i < dim / 2; i++) {
    if (parola[i] != parola[dim - i - 1])
      return false;
  }

  return true;
}

void leggi_array(char parola[], int &dim) {
  char c;
  dim = 0;
  cout << "Inserisci la parola terminata da un punto" << endl;
  cin >> c;
  while ((c != '.') && (dim < maxdim)) {
    parola[dim] = c;
    dim++;
    cin >> c;
  }
}

