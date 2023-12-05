#include <istream>
#include <iostream>
#include <string>

std::istream &read(std::istream &is) {
  std::string input;
  while (is >> input)
    std::cout << input;

  is.clear();
  return is;
}

int main() {
  read(std::cin);
  return 0;
}
