#include <iostream>
#include <string>
#include <cctype>
using std::cout, std::cin, std::endl, std::string;

int main() {
  string prec = "", curr;

  cout << "Type a sequence of words terminated by 0: " << endl;
  while (cin >> curr && curr != "0") {
    if (!isupper(curr[0]))
      continue;

    if (prec == curr) {
      cout << "Repetition of: " << curr << endl;
      break;
    }
    prec = curr;
  }

  if (prec != curr)
    cout << "There were no repetitions." << endl;

  return 0;
}
