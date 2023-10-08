#include <iostream>
#include <string>
using namespace std;

int main() {
  string str;
  getline(cin, str);

  /* for (char &c : str)
    c = 'X'; */

  /* for (string::size_type i = 0; i < str.size(); i++)
    str[i] = 'X'; */

  string::size_type i = 0;
  while (i < str.size()) {
    str[i] = 'X';
    i++;
  }

  cout << str << endl;

  return 0;
}
