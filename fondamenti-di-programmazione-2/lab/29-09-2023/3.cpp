/* Scrivere una funzione che ricevuti in input due interi x, y ∈ N calcoli il
 * risultato dell’operazione 2x + y2.
 */

#include <iostream>
using namespace std;

int arithmetic(int, int);

int main() {
  int x, y;
  cin >> x >> y;

  cout << arithmetic(x, y) << endl;

  return 0;
}

int arithmetic(int x, int y) {
  return 2 * x + y * y;
}
