# Letti da input due interi stampa la somma di tutti i numeri dispari compresi
# tra questi, gli estermi sono inclusi se dispari.
# il secondo è sempre maggiore del primo.

Inizio = int(input())
Fine = int(input())

somma = 0

for numero in range(Inizio, Fine + 1):
  if numero % 2 != 0:
    somma += numero

print(somma, end="")
