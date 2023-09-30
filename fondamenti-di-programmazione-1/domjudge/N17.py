precedente = 1
n = int(input())

verificata = False

while n != 0:
    precedente = n
    n = int(input())
    if n != 0:
        if (n % 2 == 0 and precedente % 2 == 0) or \
            ((precedente + n) % n == 0) or ((n + precedente) % precedente == 0):
            verificata = True
            # break

if verificata:
    print("SI", end="")
else:
    print("NO", end="")
