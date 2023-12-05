x = int(input())
n = int(input())
precedente = 0
conteggio = 0

while n != -1:
    if n == precedente == 0:
        conteggio += 1
    precedente = n
    n = int(input())

if conteggio >= x:
    print("OK", end="")
else:
    print("NO", end="")
