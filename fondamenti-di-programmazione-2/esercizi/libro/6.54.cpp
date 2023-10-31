#include <vector>

int main() {
  std::vector<int(*)(int, int)> functionPointers;

  int myFunc(int, int);
  int (*f)(int, int) = &myFunc;

  functionPointers.push_back(f);

  return 0;
}
