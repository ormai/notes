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

const int n = 4;
bool puntoDiSella(int[][n]);
int getMaxCol(int[][n], int);
int getMinRow(int[][n], int);

int main() {
  /* int M[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; i < n; i++)
      cin >> M[i][j];
  } */

  int M1[n][n] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 16}
  };

  int M2[n][n] = {
    {1, 2, 1, 2},
    {4, 3, 4, 3},
    {1, 2, 1, 2},
    {4, 3, 4, 3},
  };

  if (puntoDiSella(M2))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}

bool puntoDiSella(int mat[n][n]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (getMaxCol(mat, j) == mat[i][j] && getMinRow(mat, i) == mat[i][j])
        return true;
    }
  }
  return false;
}

int getMaxCol(int mat[][n], int j) {
  int max = mat[0][j];
  for (int e = 1; e < n; e++) {
    if (mat[e][j] > max)
      max = mat[e][j];
  }
  return max;
}

int getMinRow(int mat[][n], int i) {
  int min = mat[i][0];
  for (int e = 1; e < n; e++) {
    if (mat[i][e] < min)
      min = mat[i][e];
  }
  return min;
}
