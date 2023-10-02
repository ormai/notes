#include <iostream>
using namespace std;

void towerOfHanoi(int, char, char, char);

int main() {
    int n; // numero dischi
    cin >> n;

    towerOfHanoi(n, 'A', 'C', 'B');

    return 0;
}

void towerOfHanoi(int n, char fromRod, char toRod, char auxRod) {
    if (n == 1) {
        cout << "Move disk 1 from " << fromRod << " to " << toRod << endl;
        return;
    }

    towerOfHanoi(n - 1, fromRod, auxRod, toRod);
    // A conterrà solo il disco più grande, C sarà libero

    cout << "Move disk " << n << " from " << fromRod << " to " << toRod << endl;

    towerOfHanoi(n - 1, auxRod, toRod, fromRod);
}
