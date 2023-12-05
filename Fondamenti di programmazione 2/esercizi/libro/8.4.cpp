#include <vector>
#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cerr << "I need a file name as argument.\n";
    return -1;
  }

  std::ifstream input(argv[1]);
  std::vector<std::string> fileContent;

  if (input) {
    std::string tmp;
    while (std::getline(input, tmp))
      fileContent.push_back(tmp);
  }

  for (std::string line : fileContent)
    std::cout << line << '\n';

  return 0;
}
