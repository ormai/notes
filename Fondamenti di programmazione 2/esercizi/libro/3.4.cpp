#include <iostream>
#include <string>
using namespace std;

int main() {
  cout << "Type two strings:" << endl;
  string s1, s2;
  getline(cin, s1);
  getline(cin, s2);

  if (s1 == s2)
    cout << "The two strings are equal." << endl;
  else if (s1 > s2)
    cout << "The first string is larger." << endl;
  else
    cout << "The second string is larger." << endl;

  string::size_type len_s1 = s1.size(), len_s2 = s2.size();

  if (len_s1 == len_s2)
    cout << "The two strings have the same length." << endl;
  else if (len_s1 > len_s2)
    cout << "The first string is longer." << endl;
  else
    cout << "The second string is longer." << endl;

  return 0;
}
