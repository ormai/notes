state = 0

def main():
    X = int(input()) # X > 0
    DIMENSIONE_MATRICE = 10
    matrice = []
    riempiMatrice(matrice, DIMENSIONE_MATRICE, X)

    print(sommaDiagonalePrincipale(matrice), end='')

def riempiMatrice(matrice,dim, X):
    for i in range(dim):
        matrice.append([])
        for _ in range(dim):
            matrice[i].append(ottieniValore(X))

def ottieniValore(sup):
    global state
    if state == sup:
        state = 0

    state += 1

    return state

def sommaDiagonalePrincipale(matrice):
    somma = 0
    for i in range(len(matrice)):
        for j in range(len(matrice[0])):
            if i + j == len(matrice) - 1:
                somma += matrice[i][j]
    return somma

main()
