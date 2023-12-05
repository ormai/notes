n = int(input("Dammi un numero: "))

somma = 1
contatore = 1

while somma < n:
    contatore += 1 # contatore parte da 1 e incrementa ciclicamente di 1
    somma += contatore # somma ha questo comportamento: 1, 1+2=3, 3+3=6, 4+6=10...

if somma == n:
    print(n, "è triangolare")
else:
    print(n, "non è triangolare")
