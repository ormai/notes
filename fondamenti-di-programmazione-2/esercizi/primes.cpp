#include <cmath>
#include <iostream>

bool isPrime(int);

int main() {
  int n;

  std::cout << "Scrivi un numero: ";
  if (std::cin >> n)
    if (isPrime(n))
      std::cout << n << " è primo." << std::endl;
    else
      std::cout << n << " non è primo." << std::endl;
  else {
    std::cerr << "Il numero che hai inserito non è valido." << std::endl;
    return -1;
  }

  return 0;
}

bool isPrime(int n) {
  if (n <= 1)
    return false;
  else if (n < 4) // 2 e 3 sono primi
    return true;
  else if (n % 2 == 0) // i numeri pari non sono primi
    return false;
  else if (n < 9)
    return true;
  else if (n % 3 == 0) // i multipli di 3 non sono primi
    return false;
  else { // ciò che resta
    int limite = floor(sqrt(n));
    int divisore = 5;

    while (divisore <= limite) {
      if (n % divisore == 0 || n % (divisore + 2) == 0)
        return false;

      divisore += 6;
    }
  }

  return true;
}
