# Scrivere un programma che presi da input N numeri interi stampa la somma di
# tutti i numeri positivi e la somma di quelli negativi.

N = int(input("Scrivi quanti numeri vuoi sommare: "))

somma_positivi = 0
somma_negativi = 0
cont = 0

while cont < N:
  A = int(input("Scrivi un numero da sommare: "))
  cont += 1
  if A < 0:
    somma_negativi += A
  else:
    somma_positivi += A

print("La somma dei soli numeri negativi è", somma_negativi)
print("La somma dei soli numeri positivi è", somma_positivi)
