#include <iostream>
using std::cin, std::cout, std::endl;

#include <iterator>
using std::size, std::end, std::begin;

int main() {
  int arr1[10];
  cout << "10 ingegers separated by spaces:\n";
  for (int &i : arr1)
    cin >> i;

  int arr2[10];
  cout << "10 ingegers separated by spaces:\n";
  for (int &i : arr2)
    cin >> i;

  if (size(arr1) != size(arr2)) {
    cout << "Arrays have different sizes." << endl;
    return -1;
  }

  for (auto it1 = begin(arr1), it2 = begin(arr2);
       it1 < end(arr1) && it2 < end(arr2); it1++, it2++) {
    if (*it1 != *it2) {
      cout << *it1 << " is not equal to " << *it2 << "\nArrays are not equal."
           << endl;
      return -1;
    }
  }

  cout << "Arrays are equal." << endl;
  return 0;
}
