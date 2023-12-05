#include <iostream>
#include <string>
using std::cout, std::cin, std::endl, std::string;

int main() {
  string s1, s2, ans;
  do {
    cin >> s1 >> s2;

    if (s1 < s2)
      cout << s1 << " is less than " << s2 << endl;
    else
      cout << s2 << " is less than " << s1 << endl;


    cout << "Want to continue [yes/no]: ";
    cin >> ans;

  } while (ans[0] != 'n');

  return 0;
}
