#include <cctype>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  vector<string> sequence;
  string tmp;

  while (cin >> tmp)
    sequence.push_back(tmp);

  for (auto &word : sequence)
    for (auto &c : word)
      c = toupper(c);

  vector<string>::size_type seqSize = sequence.size();
  for (decltype(seqSize) i = 0; i < seqSize; i += 8) {
    for (decltype(seqSize) j = 0; j < 8; j++)
      if (i + j < seqSize)
        cout << sequence[i + j] << ' ';
    cout << endl;
  }
}
