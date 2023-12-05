# Scrivere un programma che, letta da input una sequenza di numeri interi
# terminata dal tappo (o valore sentinella) 5 stampi la stringa “NESSUNO”
# se nella sequenza non è presente alcun numero che sia un multiplo di 5 e la
# stringa "ALMENO 1" altrimenti.

multipliDiCinque = False # controllo

N = 0

while N != 5: # 5 è il tappo, il ciclo si ferma quando lo incontra.
  N = int(input()) # 5 è il valore sentinella 

  if N % 5 == 0 and N != 5:
    multipliDiCinque = True

if multipliDiCinque:
  print("ALMENO 1", end="")
else:
  print("NESSUNO", end="")
