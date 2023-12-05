#include <cctype>
#include <iostream>
#include <string>

int main() {
  std::string phrase = "Parole in fila.", phrase2("Parole in fila."),
              phrase3{"Parole in fila."}, longString = phrase + phrase2;

  phrase2 += phrase3;

  if (phrase == phrase2) {
    ;
  }

  std::string a(10, 'a'); // aaaaaaaaaa

  std::string::size_type len = a.size();

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

  std::cout << phrase << std::endl;

  for (char &c : phrase)
    c = toupper(c);

  std::cout << phrase << std::endl;

  return 0;
}
