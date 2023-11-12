#include <iostream>
#include <stack>

struct rod {
  char name;
  std::stack<unsigned> rod;
};

void hanoi(int, rod &, rod &, rod &);
void printRods();

unsigned calls = 0;

rod A = {'A'}, B = {'B'}, C = {'C'};

int main() {
  int n; // numero dischi
  std::cout << "Quanti dischi vuoi cha abbia la tua Torre di Hanoi? ";
  std::cin >> n;

  for (unsigned i = n; i > 0; --i)
    A.rod.push(i);

  hanoi(n, A, B, C);
  std::cout << "Chiamate ricorsive: " << calls << std::endl;

  return 0;
}

void hanoi(int n, rod &from, rod &aux, rod &to) {
  ++calls;
  if (n == 1) {
    std::cout << "Sposto il disco " << from.rod.top() << " da " << from.name
              << " a " << to.name << std::endl;
    to.rod.push(from.rod.top());
    from.rod.pop();

    printRods();
    return;
  }

  hanoi(n - 1, from, to, aux);

  std::cout << "Sposto il disco " << n << " da " << from.name << " a "
            << to.name << std::endl;
  to.rod.push(from.rod.top());
  from.rod.pop();

  hanoi(n - 1, aux, from, to);
}

void printStack(std::stack<unsigned> s) {
  // si fa una copia dello stack ad ogni chiamata
  if (s.empty())
    return;

  int top = s.top();
  s.pop();

  printStack(s);

  std::cout << top << ' ';
  s.push(top);
}

void printRods() {
  std::cout << "A: ";
  printStack(A.rod);
  std::cout << "\nB: ";
  printStack(B.rod);
  std::cout << "\nC: ";
  printStack(C.rod);
  std::cout << std::endl;
}
