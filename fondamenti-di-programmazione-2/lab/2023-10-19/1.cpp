#include <vector>
using std::vector;

#include <iostream>
using std::cin, std::cout, std::endl;

void printSequenza(vector<unsigned> s, const unsigned inizio,
                   vector<unsigned>::size_type fine) {
  cout << '[';
  for (decltype(fine) i = 0; i < fine; i++) {
    cout << s[i];
    if (i != fine - 1)
      cout << ", ";
  }
  cout << ']' << endl;
}

int main() {
  vector<unsigned> sequenza;
  int input;
  while (cin >> input && input != -1)
    sequenza.push_back(input);

  vector<unsigned>::size_type sizeSequenza = sequenza.size();
  printSequenza(sequenza, 0, sequenza.size());

  vector<unsigned> sequenza2;

  while (cin >> input && input != -1) {
    sequenza2.push_back(input);
    if ((int)sizeSequenza > input) {
      printSequenza(sequenza2, 0, input);
    } else
      cout << "ERRORE!!!!!!!" << endl;
  }

  decltype(sizeSequenza) sizeSequenza2 = sequenza2.size();
  for (decltype(sizeSequenza) i = 0; i < sizeSequenza2; i++) {
    int e = sequenza2[i], j = i - 1;

    while (j >= 0 && (int)sequenza2[j] > e) {
      sequenza2[j + 1] = sequenza2[j];
      j--;
    }
    sequenza2[j + 1] = e;
  }

  printSequenza(sequenza2, 0, sequenza2.size());

  return 0;
}
