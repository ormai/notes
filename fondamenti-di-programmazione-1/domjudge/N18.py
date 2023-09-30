precedente = input()
corrente = input()
conteggio = 0

while not (precedente == "o" and corrente == "k"):
    conteggio += 1
    precedente = corrente
    corrente = input()

print(conteggio, end="")
