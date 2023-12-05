# Scrivere un programma che stampa la somma di N numeri presi da input.

N = int(input("Scrivi quanti numeri vuoi sommare: "))

somma = 0
cont = 0

while cont < N:
    A = int(input("Scrivi un numero da sommare: "))
    somma += A
    cont += 1

print("La somma è", somma)
