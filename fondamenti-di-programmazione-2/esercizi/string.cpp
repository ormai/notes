#include <cctype>
#include <iostream>
#include <string>

using namespace std;

int main() {
  string phrase = "Parole in fila.";
  string phrase2("Parole in fila.");
  string phrase3{"Parole in fila."};

  string longString = phrase + phrase2;

  phrase2 += phrase3;

  if (phrase == phrase2) {
    ;
  }

  string a(10, 'a'); // aaaaaaaaaa

  string::size_type len = a.size();

  // for (char c : phrase)
  //   cout << c;
  // cout << endl;

  /* string word;
  while (cin >> word)
    cout << word << endl; */

  /* string line;
  while (getline(cin, line))
    if (!line.empty())
      cout << line << endl; */

  cout << phrase << endl;

  for (char &c : phrase)
    c = toupper(c);

  cout << phrase << endl;

  return 0;
}
