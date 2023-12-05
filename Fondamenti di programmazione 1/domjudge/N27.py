N = int(input())
sequenza = []
proprietàSoddisfatta = False
contatore = 0

n = int(input())
while n != -1:
    sequenza.append(n)
    n = int(input())

for i in sequenza:
    if i <= N:
        contatore += 1
        if contatore == N:
            break
    else:
        contatore = 0

if contatore >= N:
    print("OK", end="")
else:
    print("NO", end="")
