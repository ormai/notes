sequenza = []

char = input()
while char != "0":
    sequenza.append(char)
    char = input()

cifre = []
misure = []

for i in range(len(sequenza)):
    if i % 2 == 0:
        cifre.append(int(sequenza[i]))
    else:
        misure.append(sequenza[i])

risultato = 0

for i in range(len(cifre)):
    if misure[i] == "s":
        risultato += cifre[i]
    elif misure[i] == "m":
        risultato += cifre[i] * 60
    else:
        risultato += cifre[i] * 3600

print(risultato, end="")
