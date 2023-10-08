#include <cctype>
#include <iostream>
using namespace std;

int main() {
  char c;
  cin >> c;

  if (isalnum(c))
    cout << c << " is a letter or a digit." << endl;

  if (isalpha(c))
    cout << c << " is a letter." << endl;

  if (iscntrl(c))
    cout << c << " is a control character." << endl;

  if (isdigit(c))
    cout << c << " is a digit." << endl;

  if (isgraph(c))
    cout << c << " is not a space but is printable." << endl;

  if (islower(c))
    cout << c << " is a lowercase letter." << endl;

  if (isprint(c))
    cout << c << " is a printable character." << endl;

  if (ispunct(c))
    cout << c << " is a punctuation character." << endl;

  if (isspace(c))
    cout << c << " is a whitespace." << endl;

  if (isupper(c))
    cout << c << " is an uppercase letter." << endl;

  if (isxdigit(c))
    cout << c << " is a hexadecimal digit." << endl;

  cout << tolower(c) << endl;
  cout << toupper(c) << endl;

  return 0;
}
