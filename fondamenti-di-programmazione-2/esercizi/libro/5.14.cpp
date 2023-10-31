#include <iostream>
#include <string>
using std::string, std::cout, std::endl, std::cin;

int main() {
  string s, duplicate = "", mostRepeated = "";
  unsigned max = 0, count = 0;

  while (cin >> s && s != "0") {
    if (s == duplicate)
      ++count;
    else {
      count = 1;
      duplicate = s;
    }
    if (count > max) {
      max = count;
      mostRepeated = duplicate;
    }
  }

  if (false)
    cout << "There were no repetition." << endl;
  else
    cout << mostRepeated << " was repeated " << max << " times." << endl;

  return 0;
}
