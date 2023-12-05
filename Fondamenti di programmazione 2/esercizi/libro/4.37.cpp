#include <string>
using std::string;

int main() {
  int i;
  double d;
  const string *ps;
  char *pc;
  void *pv;

  pv = const_cast<void *>(ps);
  i = static_cast<int>(*pc);
  pv = static_cast<void *>(d);
  pc = static_canst<int>(pv);
}
