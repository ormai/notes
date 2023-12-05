risposteEsatte = input()
matricole = []
risposte = []

STUDENTI = 90
DOMANDA = 20

for i in range(STUDENTI):
    matricole.append(input())
    risposte.append(input())

punti = 0
for i in range(STUDENTI):
    for j in range(len(risposteEsatte)):
        if risposte[i][j] == risposteEsatte[j]:
            punti += 2
        elif risposte[i][j] == "X":
            punti += 0
        else:
            punti -= 1
    print(matricole[i], punti) 
    punti = 0
