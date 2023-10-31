#include <iostream>
using std::cin, std::cout, std::endl;

int main() {
  char ch;
  int aCount = 0, eCount = 0, iCount = 0, oCount = 0, uCount = 0;
  while (cin >> ch) {
    if (ch == 'a' || ch == 'A')
      ++aCount;
    else if (ch == 'e' || ch == 'E')
      ++eCount;
    else if (ch == 'i' || ch == 'I')
      ++iCount;
    else if (ch == 'o' || ch == 'O')
      ++oCount;
    else if (ch == 'u' || ch == 'U')
      ++uCount;
  }

  cout << "Number of a: " << aCount
       << "\nNumber of e: " << eCount
       << "\nNumber of i: " << iCount
       << "\nNumber of o: " << oCount
       << "\nNumber of u: " << uCount << endl;

  return 0;
}
