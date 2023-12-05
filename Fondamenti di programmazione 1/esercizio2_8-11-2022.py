i = 1

n = int(input("Quanti numeri vuoi inserire? "))
precedente = 0
corrente = 0
crescente = True

while i < n:
    precedente = corrente
    corrente = int(input("Dammi un numero: "))
    i += 1

    if precedente > corrente:
        crescente = False

if n >= 2:
    if crescente:
        print("La sequenza è crescente.")
    else:
        print("La sequenza non è crescente.")
