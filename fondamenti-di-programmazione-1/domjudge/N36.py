lista = []
nessunDivisibile = True

for i in range(10):
    lista.append(int(input()))

X = int(input())

for i in lista:
    if i % X == 0:
        nessunDivisibile = False

if nessunDivisibile:
    print("OK", end="")
else:
    print("NO", end="")
