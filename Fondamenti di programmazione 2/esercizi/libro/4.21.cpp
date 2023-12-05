/* Exercise 4.21: Write a program to use a conditional operator to find the
 * elements in a vector<int> that have odd value and double the value of each
 * such element. */

#include <vector>
#include <iostream>

int main() {
  std::vector<int> ints{1, 2, 3, 4, 5, 6, 7};

  for (auto i = 0; i < ints.size(); ++i)
    (ints[i] & 1) ? ints[i] *= 2 : i;

  for (auto e : ints)
  std::cout << e << std::endl;

  return 0;
}
