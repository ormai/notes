#include <iostream>
#include <string>

int main() {
  std::string phrase = "Parole in fila.";
  std::string phrase2("Parole in fila.");
  std::string phrase3{"Parole in fila."};

  std::cout << phrase << std::endl;

  return 0;
}
