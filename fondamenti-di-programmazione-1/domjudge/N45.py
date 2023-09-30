N = int(input())

# Contare il numero di cifre senza convertire l'intero in stringa
quoziente = N
numCifre = 1
while quoziente >= 10:
    numCifre += 1
    quoziente //= 10

# Convertire l'intero in lista
cifre = [] # inverte
quozienteParziale = N
for i in range(numCifre):
    cifre.insert(0, quozienteParziale % 10)
    quozienteParziale //= 10

# Componi i due numeri
ascending = cifre[:]
ascending.sort()
descending = ascending[::-1]

Nmin = 0
Nmax = 0

for i in range(len(cifre)):
    Nmin = Nmin * 10 + ascending[i]
    Nmax = Nmax * 10 + descending[i]

print(Nmax - Nmin, end="")

