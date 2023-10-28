/* Scrivere una funzione che preso in input un array A di interi, restituisca
 * true se e solo se A è palindromo. Un array si dice, informalmente,
 * palindromo quando, leggendolo da destra verso sinistra o da sinistra verso
 * destra risulta avere gli elementi nello stesso ordine. La funzione dovrà
 * essere implementata utilizzando la ricorsione.
 */

#include <iostream>
using namespace std;

bool isPalindrome(int[], int, int);

int main() {
  cout << "Numero di elementi dell'array: ";
  int n;
  cin >> n;

  int A[n];
  for (int i = 0; i < n; i++)
    cin >> A[i];

  cout << (isPalindrome(A, 0, n - 1) ? "YES" : "NO") << endl;

  return 0;
}

bool isPalindrome(int arr[], int first, int last) {
  if (last == first)
    return true;

  if (arr[first] == arr[last])
    return isPalindrome(arr, ++first, --last);

  return false;
}
