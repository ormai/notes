# Scrivere un programma che stampa la media di N numeri presi da input.

N = int(input("Scrivi di quanti numeri vuoi fare la media: "))

somma = 0
cont = 0

while cont < N:
    A = int(input("Scrivi un numero di per farne la media: "))
    somma += A
    cont += 1

print("La media è", somma / N)
