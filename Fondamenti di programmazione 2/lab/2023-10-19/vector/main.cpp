#include <iostream>
using namespace std;
#include "Vector.h"

int main() {
  Vector<int> v;
  for (int i = 0; i < 10; i++)
    v.push_back(i);

  cout << "elemento:";
  for (int i = 0; i < v.size(); i++)
    cout << ' ' << v[i];
  cout << endl;

  cout << "svuoto l'array v:";
  while (v.size() > 0) {
    cout << v.back() << ' ';
    v.pop_back();
  }
  cout << endl;
  Vector<char> v2;
  for (int i = 0; i < 10; i++)
    v2.push_back('a');
  cout << "elemento:";
  for (int i = 0; i < v2.size(); i++)
    cout << ' ' << v2[i];
  cout << endl;
}
