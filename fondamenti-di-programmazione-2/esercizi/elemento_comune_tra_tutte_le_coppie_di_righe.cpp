/* Determinare se tutte le coppie di righe hanno almeno un elemento in comune
 * (anche in colonne diverse)
 */

#include <iostream>
using namespace std;

const int r = 4, c = 6;

bool commonEl(const int[][c]);

int main() {
  const int mat1[r][c] = {
    {1, 2, 3, 4, 5, 34},
    {6, 7, 8, 9, 10, 12},
    {1, 2, 3, 4, 5, 6},
    {16, 2, 1, 9, 11, 2},
  };

  const int mat2[r][c] = {
    {1, 2, 3, 4, 5, 6},
    {7, 8, 9, 10, 11, 12},
    {13, 14, 15, 16, 17, 18},
    {19, 20, 21, 22, 23, 24},
  };

  if (commonEl(mat2))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

}

bool commonEl(const int m[][c]) {
  for (int i = 0; i < r - 1; i++) { // per ogni riga
    for (int j = i + 1; j < r; j++) { // per ogni altra riga
      for (int k = 0; k < c; k++) { // per ogni colonna
        if (m[i][k] == m[j][k])
          return true;
      }
    }
  }
  return false;
}

