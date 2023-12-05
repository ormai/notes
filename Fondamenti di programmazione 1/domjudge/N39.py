lista = []
n = int(input())
while n != 0:
    lista.append(n)
    n = int(input())

condizione = True

for i in lista:
    quoziente = i
    while quoziente != 2 and quoziente / 2 != 2:
        if quoziente <= 2:
            condizione = False
            break
        quoziente /= 2

if condizione:
    print("SI", end="")
else:
    print("NO", end="")
