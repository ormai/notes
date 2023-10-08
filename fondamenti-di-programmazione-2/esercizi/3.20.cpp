#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> integers;
  int tmp;

  while (cin >> tmp)
    integers.push_back(tmp);

  for (vector<int>::size_type i = 0; i < integers.size(); i += 2)
    cout << integers[i] + integers[i + 1] << endl;

  for (vector<int>::size_type i = 0; i < integers.size(); i += 2)
    cout << integers[i] + integers[integers.size() - 1 - i] << endl;

  return 0;
}
