#include <vector>
#include <iostream>

using std::vector, std::cout, std::endl;

int main() {
  vector<int> n = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  for (auto in = n.begin(); in != n.end(); in++) {
    *in = *in * *in;

    cout << *in << endl;
  }

  return 0;
}
