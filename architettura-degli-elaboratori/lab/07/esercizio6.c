#include <stdio.h>

int main(void) {
    int a, b, c;
    printf("Inserici un numero: ");
    scanf("%d", &a);
    printf("Inserici un numero: ");
    scanf("%d", &b);
    printf("Inserici un numero: ");
    scanf("%d", &c);

    if (( a == b ) || ( a == c )) {
        printf("%d\n", a);
    } else if (b == c) {
        printf("%d\n", b);
    } else {
        printf("OK\n");
    }

    return 0;
}
