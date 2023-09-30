#include <iostream>
using namespace std;

// ci ha messo 3:47 minuti per terminare

long long int f(long long int n);

int main() {
    for (int i = 0; i < 50; i++) {
        cout << f(i) << endl;
    }
}

long long int f(long long int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    return (2*f(n-1)) - (f(n-2)/2);
}
