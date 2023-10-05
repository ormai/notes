/* Consideriamo una sequenza di numeri reali S = (x1, . . . , xn), con xi ∈ R.
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
