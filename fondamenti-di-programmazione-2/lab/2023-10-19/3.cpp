#include <vector>
using std::vector;

#include <iostream>
using std::cout, std::endl;

class Vettori {
public:
  Vettori() {}
  Vettori(vector<int> _v1, vector<char> _v2) : v1(_v1), v2(_v2) {}

  void aggiungi(const int n) { v1.push_back(n); }
  void aggiungi(const char c) { v2.push_back(c); }
  void rimuoviMinori(const int n);
  void rimuoviCarattere(const char c);
  void stampa() const;

private:
  vector<int> v1;
  vector<char> v2;
};

void Vettori::rimuoviMinori(const int n) {
  auto it = v1.begin();
  while (it < v1.end()) {
    if (*it < n)
      v1.erase(it);
    else
      ++it;
  }
}

void Vettori::rimuoviCarattere(const char c) {
  auto it = v2.begin();
  while (it < v2.end()) {
    if (*it == c)
      v2.erase(it);
    else
      ++it;
  }
}

void Vettori::stampa() const {
  cout << "v1: [";
  auto length_v1 = v1.size();
  for (int i = 0; i < length_v1; ++i) {
    cout << v1[i];
    if (i < length_v1 - 1)
      cout << ", ";
  }
  cout << "]" << endl;

  cout << "v2: [";
  auto length_v2 = v2.size();
  for (int i = 0; i < length_v2; ++i) {
    cout << v2[i];
    if (i < length_v2 - 1)
      cout << ", ";
  }
  cout << "]" << endl;
}

int main() {
  // TESTING

  Vettori a({1, 2, 3, 4, 5}, {'a', 'b', 'c'});
  a.stampa();

  a.rimuoviMinori(3);
  a.rimuoviCarattere('b');
  a.aggiungi('z');
  a.stampa();

  return 0;
}
