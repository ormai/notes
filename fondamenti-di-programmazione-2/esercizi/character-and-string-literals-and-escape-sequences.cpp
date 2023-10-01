#include <iostream>
using namespace std;

int main() {
  cout << 'a' << '\n' // char
       << "a" << endl; // array of chars: ['a', '\0']

  // generalized escape sequence
  cout << "\103\151\141\157!" << endl;
  cout << "\x43\x69\x61\x6f!" << endl;

  return 0;
}
