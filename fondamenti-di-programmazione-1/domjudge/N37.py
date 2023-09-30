caratteri = []
vocaliContenute = []

for i in range(100):
    caratteri.append(input())

for i in caratteri:
    if i in "aeiou" and i != "" and i not in vocaliContenute:
        vocaliContenute.append(i)

if len(vocaliContenute) > 1:
    print("ERRORE", end="")
else:
    print("OK", end="")
