lista = []
for i in range(100):
    lista.append(int(input()))

elementi = []
cont = 0
somma = 0

for i in lista:
    if i < -50 or i > 50:
        elementi.append(i)
    else:
        cont += 1
        somma += i

if len(elementi) == 0:
    print("VUOTO1")
else:
    print("".join(str(c) for c in elementi))

if cont == 0:
    print("VUOTO2", end="")
else:
    print(round(somma / cont, 6), end="")
