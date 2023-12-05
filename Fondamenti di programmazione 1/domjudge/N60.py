S = input()
N = int(input())
stringhe = []
soddisfatta = False


for i in range(N):
    stringhe.append(input())

# Si ipotizza che siano fornite almeno due stringhe
massimo = stringhe[0]
minimo = stringhe[0]

for i in range(len(stringhe)):
    if stringhe[i] > massimo:
        massimo = stringhe[i]
    if stringhe[i] < minimo:
        minimo = stringhe[i]
    for j in range(len(stringhe)):
        if stringhe[i] + stringhe[j] == S:
            soddisfatta = True

if soddisfatta:
    print("OK", end="")
else:
    print(massimo + minimo, end="")
