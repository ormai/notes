#include <stdio.h>

static long long int count = 0;

long long int f(long long int n);

int main(void) {
    printf("%lld\n", f(49));
    printf("%lld\n", count);
}

long long int f(long long int n) {
    count++; // conta quante volte f() viene chiamata

    if (n == 0) return 0;
    if (n == 1) return 1;

    return (2 * f(n - 1)) - (f(n - 2) / 2);
}

