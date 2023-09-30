# Letta da input una sequenza di interi positivi che termina con il valore
# sentinella 0, contare gli elementi dispari divisbili per 3 e stampare il
# conteggio.

N = int(input())
cont = 0

while N != 0:
  if N % 2 != 0 and N %3 == 0:
    cont += 1
  N = int(input())

print(cont, end="")
