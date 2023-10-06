/* Consideriamo una sequenza di numeri reali S = (x1, ..., xn), con xi ∈ R.
 * La loro media è definita come:
 *
 * µ(S) = 1/n * 󰒠^n_{i=1} x_i
 *
 * La loro varianza è definita come:
 *
 * σ(S) = 1/n * 󰒠^n_{i=1} (x_i − µ(S))^2
 *
 * Scrivere una funzione che, preso in input un array A, il numero dei suoi
 * elementi n, calcoli la media e la varianza dei suoi elementi. La funzione
 * dovrà avere la seguente segnatura:
 *
 * void media_varianza(float a[], int n, int& mu, int& sigma);
 *
 * Nota: mu, sigma sono passate per riferimento in modo tale da potervi
 * accedere dalla funzione chiamante media_varianza.
 *
 * Scrivere poi un main di prova che letta da input una sequenza di array,
 * stampi per ciascuno di essi la sua media e la sua varianza. Vedi esempio.
 *
 * Esempio: Supponiamo l’input sia:
 *
 * 3                       // Numero di array da leggere
 * 2                       // Lunghezza del primo array
 * 3.2 -8.4                // Elementi del primo array
 * 6                       // Lunghezza del secondo array
 * 1 1 2 4.2 9.3 -52.1     // Elementi del secondo array
 * 3                       // Lunghezza del terzo array
 * -5 5 2.73               // Elementi del terzo array
 *
 * Il main dovrà stampare:
 *
 * Statistiche per l'array #1:
 * Media: -2.6
 * Varianza: 33.64
 *
 * Statistiche per l'array #2:
 * Media: -5.76667
 * Varianza: 437.502
 *
 * Statistiche per l'array #3:
 * Media: 0.91
 * Varianza: 18.3229
 */

#include <iostream>
using namespace std;

void media_varianza(float[], int, float &, float &);

int main() {
  unsigned numArray;
  cout << "Numero di array: ";
  cin >> numArray;

  float mus[numArray], sigmas[numArray];

  for (int i = 0; i < numArray; i++) {
    cout << "Lunghezza array #" << i + 1 << ": ";
    int n;
    cin >> n;

    cout << "Elementi array #" << i + 1 << ": ";
    float A[n];
    for (int j = 0; j < n; j++)
      cin >> A[j];

    float mu, sigma;
    media_varianza(A, n, mu, sigma);
    mus[i] = mu;
    sigmas[i] = sigma;
  }

  for (int i = 0; i < numArray; i++)
    cout << "\nStatistiche per l'array #" << i + 1 << ":\nMedia: " << mus[i]
         << "\nVarianza: " << sigmas[i] << endl;

  return 0;
}

void media_varianza(float a[], int n, float &mu, float &sigma) {
  mu = 0;
  for (int i = 0; i < n; i++)
    mu += a[i];
  mu /= n;

  sigma = 0;
  for (int i = 0; i < n; i++)
    sigma += (a[i] - mu) * (a[i] - mu);
  sigma /= n;
}
