sequenza = []

n = int(input())
for i in range(n):
    sequenza.append(int(input()))

condizioneSoddisfatta = True

for i in range(len(sequenza)):
    if i % 2 == 0:
        if i + 2 < len(sequenza) and not (sequenza[i] < sequenza[i + 2]):
            condizioneSoddisfatta = False
    else:
        if sequenza[i] % 2 == 0:
            condizioneSoddisfatta = False

if condizioneSoddisfatta:
    print("SI", end="")
else:
    print("NO", end="")
