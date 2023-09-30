pesoQuesiti = []
matricole = []
votiQuesiti = []

NUMERO_QUESITI = 8
NUMERO_STUDENTI = 70

for i in range(NUMERO_QUESITI):
    pesoQuesiti.append(int(input()))

for i in range(NUMERO_STUDENTI):
    matricole.append(input())
    votiQuesiti.append([])
    for j in range(NUMERO_QUESITI):
        votiQuesiti[i].append(int(input()))

soglia = int(input())

votiEsame = []

# Calcola i voti di ciascuno studente
voto = 0
for studente in range(len(matricole)): # 70 volte
    for questito in range(len(pesoQuesiti)): # 8 volte
        voto += votiQuesiti[studente][questito] * pesoQuesiti[questito]
    votiEsame.append(voto)
    voto = 0

massimo = votiEsame[0]
indexMax = 0

minimo = votiEsame[69]
indexMin = 0

numeroAmmessi = 0

# Stampa i risultati
for i in range(len(votiEsame)):
    if votiEsame[i] >= soglia:
        print(matricole[i] + " " + str(votiEsame[i]))
        numeroAmmessi += 1

    # Individua la matricola dello studente con il voto più alto
    if votiEsame[i] > massimo:
        massimo = votiEsame[i]
        indexMax = i

    # Individua la matricola dello studente con il voto più basso
    if votiEsame[i] >= soglia and votiEsame[i] < minimo:
        minimo = votiEsame[i]
        indexMin = i

print(numeroAmmessi, matricole[indexMax], matricole[indexMin], end="")
