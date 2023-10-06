/* Sia M una matrice di interi di dimensione n × n, con n ∈ N. Scrivere una
 * funzione C++ che restituisca true se e solo se M ammette un punto di sella.
 * Un elemento M(i,j) della matrice M è un punto di sella se esso è
 * contemporaneamente il minimo della riga i e il massimo della colonna j.
 *
 * • Si può supporre che n < N, dove N è una costante intera nota a tempo di
 * compilazione (cioè, non è necessario allocare memoria dinamica)
 */

#include <iostream>
using namespace std;

const unsigned N = 10;
bool puntoDiSella(int[][N], int);

int main() {
  cout << "Dimesione della matrice quadrata (<= 10): ";
  int n;
  cin >> n;

  int M[N][N];

  cout << "Elementi della matrice quadrata: ";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> M[i][j];
    }
  }

  if (puntoDiSella(M, n)) // sarà sempre vero, per qualsiasi M
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  
  return 0;
}

bool puntoDiSella(int mat[][N], int size) {
  bool cond;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      cond = true;
      int element = mat[i][j];

      for (int r = 0; r < size; r++) {
        if (mat[r][j] > element) { // allora non è il massimo della colonna
          cond = false;
          break;
        }
      }

      if (!cond)
        break;

      for (int c = 0; c < size; c++) {
        if (mat[i][c] < element) { // allora non è il minimo della riga
          cond = false;
          break;
        }
      }

      if (cond) // termina il prima possibile
        return cond;
    }
  }
  return cond;
}
