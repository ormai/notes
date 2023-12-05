# Scrivere un programma che letto da input un numero intero ne stampi la radice
# quadrata arrotondata a due cifre decimali. Si usino a tale scopo, la funzione
# sqrt della libreria math e la funzione round.

# Esempi.
# Se il numero letto fosse 15, il programma stamperebbe: 3.87
# Se il numero letto fosse 16, il programma stamperebbe: 4.0

from math import sqrt

N = int(input())

print(round(sqrt(N), 2), end="")
