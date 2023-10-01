#include <iostream>
using namespace std;

int main() {
  for (int riga = 0; riga <= 10; riga++) {
    for (int colonna = 0; colonna <= 10; colonna++) {
      if (riga == 0 && colonna == 0)
        cout << '\t';
      else if (riga == 0)
        cout << colonna << '\t';
      else if (colonna == 0)
        cout << riga << '\t';
      else
        cout << colonna * riga << '\t';
    }
    cout << '\n';
  }
  return 0;
}
