#include <cstring>
using std::strcmp;

#include <iostream>
using std::cin, std::cout, std::endl;

int main() {
  unsigned len1, len2;

  cout << "Lenght of the first string: ";
  cin >> len1;

  char str1[len1 + 1];
  cout << "Type first string:\n";
  for (int i = 0; i < len1; i++)
    cin >> str1[i];
  str1[len1] = '\0';

  cout << "Lenght of the second string: ";
  cin >> len2;

  char str2[len2 + 1];
  cout << "Type second string:\n";
  for (int i = 0; i < len2; i++)
    cin >> str2[i];
  str2[len2] = '\0';

  for (char c : str1)
    cout << c;
  cout << endl;

  for (char c : str1)
    cout << c;
  cout << endl;

  if (strcmp(str1, str2))
    cout << "Strings are equal." << endl;
  else
    cout << "strings are not equal." << endl;

  return 0;
}
