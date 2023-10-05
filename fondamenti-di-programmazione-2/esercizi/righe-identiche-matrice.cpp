/* Scrivere una funzione che, data una matrice, determini se esistono due
 * righe esattamente identiche.
 */

#include <iostream>
using namespace std;

const int r = 3, c = 5;

bool identicalRows(const int[][c]);

int main() {
  const int mat[r][c] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {1, 2, 3, 4, 5}};

  if (identicalRows(mat))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}

bool identicalRows(const int m[][c]) {
  bool cond;
  for (int i = 0; i < r - 1; i++) {   // per ogni riga
    for (int j = i + 1; j < r; j++) { // per ogni altra riga
      cond = true;

      for (int k = 0; k < c; k++) { // per ogni colonna
        if (m[i][k] != m[j][k]) {
          cond = false;
          break; // prossima riga
        }
      }

      if (cond)
        return cond;
    }
  }
  return cond;
}
