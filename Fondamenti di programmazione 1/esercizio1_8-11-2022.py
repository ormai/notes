x = int(input("Dammi il numero con cii fare il confronto: "))
n = int(input("Quanti numeri vuoi inserire: "))

conteggio = 0
i = 0

corrente = int(input("Dammi un numero: "))
precedente = 0

while i < n:
    i += 1
    if i > 1 and corrente + precedente == x:
        conteggio += 1
    precedente = corrente
    corrente = int(input("Dammi un numero: "))

print(conteggio)
