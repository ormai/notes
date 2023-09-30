#include "stdio.h"

int main(void) {
  char *prompt = "Type an integer:";
  int a, b;
  printf("%s", prompt);
  scanf("%d", &a);
  printf("%s", prompt);
  scanf("%d", &b);

  // the result of the bitwise and (&) will be != 0 if the two operand have at
  // at least one bit in common
  if ( a & 1 ) { // TEST IF a IS ODD
    a = -a; // this is executed if the condition is != 0
  } else {  // if the operands don't even have one bit in common: eg (4 & 3)
    b += 7;
  }
  printf("a: %d, b: %d\n", a, b);
}

