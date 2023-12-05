#include <stdio.h>

int collatz(int n); // prototype

int main(void) {
    int n;

    // leggi n da input
    printf("Scrivi un numero positivo: ");
    scanf("%d", &n);

    // chiama collatz(n) e stampane il risultato
    printf("Lunghezza = %d\n", collatz(n));

    return 0;
}

int collatz(int n) {
    if (n == 1) {
        return 1;
    } else if (n % 2 == 0) {
        return collatz(n / 2) + 1;
    } else {
        return collatz(n * 3 + 1) + 1;
    }
}
