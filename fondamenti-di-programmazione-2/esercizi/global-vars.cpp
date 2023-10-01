#include <iostream>
using namespace std;

const int reused = 42; // globale
// const per impedire di dmodificarla

int main() {
  int unique = 0;
  cout << reused << ' ' << unique << endl;

  int reused = 0; // crea una nuova variabile locale
  cout << reused << ' ' << unique << endl;
  cout << ::reused << endl; // per accedere alla variabile globale
  return 0;
}
