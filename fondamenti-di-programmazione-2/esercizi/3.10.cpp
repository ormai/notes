#include <cctype>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string str, result;
  getline(cin, str);

  for (char c : str) {
    if (!ispunct(c))
      result += c;
  }

  cout << result << endl;

  return 0;
}
