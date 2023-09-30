# Scrivere un programma che, letti da input in quest’ordine un intero X, un
# intero N e una sequenza di N interi, stampi tutti i numeri pari
# strettamente minori di X presenti all'interno della sequenza.

X = int(input()) 
N = int(input())

i = 0

output = ""

while i < N:
  i += 1
  M = int(input())

  if M < X and M % 2 == 0:
    output += str(M)

if output != "":
  print(int(output), end="")
