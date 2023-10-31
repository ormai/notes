#include <iostream>
using std::cout, std::endl;
#include <vector>
using std::vector;

void printVector(vector<int> v, vector<int>::iterator begin, vector<int>::iterator end) {
  cout << *begin++ << ' ';

  if (begin != end)
    printVector(v, begin, end);
  else
    cout << endl;
}

int main() {
  vector<int> myVector{1, 2, 3, 4, 5, 6, 76};

  printVector(myVector, myVector.begin(), myVector.end());
}
