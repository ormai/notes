K = int(input()) # Numero di elementi di A
A = [] # Lista elementi da utilizzare per riempire B
for i in range(K):
    A.append(int(input()))
N = int(input()) # Numero righe B
M = int(input()) # Numero colonne B
B = [] # Lista da riempire

for i in range(N): # Inizializza la matrice a -1
    B.append([])
    for j in range(M):
        B[i].append(-1)

posizione = [0, 0] # Punto (i, j) nella matrice
posizioneA = 0 # Posizione in A

def getElement():
    global posizioneA
    element = A[posizioneA]

    if posizioneA + 1 > len(A) - 1:
        posizioneA = 0
    else:
        posizioneA += 1

    return element

numeroVuoti = 0
def vuoti():
    global numeroVuoti
    for i in range(N):
        for j in range(M):
            if B[i][j] == -1:
                numeroVuoti += 1
    return numeroVuoti

rientroNordSud = 0
rientroEstOvest = 0

def moveRight(): 
    for i in range(posizione[1], M - 1 - rientroEstOvest):
        if posizione[1] + 1 < M and B[posizione[0]][i] == -1:
            posizione[1] += 1
            B[posizione[0]][i] = getElement()

def moveDown(): 
    for i in range(posizione[0], N - 1 - rientroNordSud):
        if posizione[0] + 1 < N and B[i][posizione[1]] == -1:
            posizione[0] += 1
            B[i][posizione[1]] = getElement()

def moveLeft(): 
    global rientroEstOvest
    for i in range(posizione[1], 0 + rientroEstOvest, -1):
        if posizione[1] - 1 >= 0 and B[posizione[0]][i] == -1:
            posizione[1] -= 1
            B[posizione[0]][i] = getElement()
    rientroEstOvest += 1

def moveUp(): 
    global rientroNordSud
    for i in range(posizione[0], 0 + rientroNordSud + 1, -1):
        if posizione[0] - 1 >= 0 and B[i][posizione[1]] == -1:
            posizione[0] -= 1
            B[i][posizione[1]] = getElement()
    rientroNordSud += 1

while vuoti() > 1:
    moveRight()
    moveDown()
    moveLeft()
    moveUp()
    numeroVuoti = 0

B[posizione[0]][posizione[1]] = getElement() # Posiziona l'ultimo elemento

for i in range(len(B)):
    for j in range(len(B[i])):
        print(B[i][j], end="")
    print()
