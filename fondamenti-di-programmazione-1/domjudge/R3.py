def main():
    N = int(input()) # N => 1 and N <= 10

    matrice = []
    for i in range(N):
        matrice.append([])
        for _ in range(N):
            matrice[i].append(int(input()))

    print("%d;%d" % (sommaDiagonaleSecondariaIterativa(matrice),
                     sommaDiagonaleSecondariaRicorsiva(matrice, N)), end='')

def sommaDiagonaleSecondariaIterativa(M):
    somma = 0
    for i in range(len(M)):
        for j in range(len(M[i])):
            if i + j == len(M) - 1:
                somma += M[i][j]

    return somma

def sommaDiagonaleSecondariaRicorsiva(matrice, righeColonne):
    indiceRiga = len(matrice) - righeColonne
    indiceColonna = righeColonne - 1
    addendo = matrice[indiceRiga][indiceColonna]

    if indiceRiga == len(matrice) - 1 and indiceColonna == 0:
        return addendo

    return (sommaDiagonaleSecondariaRicorsiva(matrice, righeColonne - 1)
        + addendo)

main()
