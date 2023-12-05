#include <iostream>

void towerOfHanoi(int n, char fromRod, char auxRod, char toRod) {
  if (n == 1) {
    std::cout << "Move disk 1 from " << fromRod << " to " << toRod << std::endl;
    return;
  }

  towerOfHanoi(n - 1, fromRod, toRod, auxRod);
  // A conterrà solo il disco più grande, C sarà libero

  std::cout << "Move disk " << n << " from " << fromRod << " to " << toRod
            << std::endl;

  towerOfHanoi(n - 1, auxRod, fromRod, toRod);
}

int main() {
  int disks;
  std::cout << "Numero dischi: ";
  std::cin >> disks;

  towerOfHanoi(disks, 'A', 'C', 'B');
  return 0;
}
