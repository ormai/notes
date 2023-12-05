parolaIniziale = input()
parolaFinale = input()
def main():
    matrice = []
    riempi(matrice)
    print(parolaIniziale, parolaFinale)
    for i in matrice: print(i)

def puntoUno(matrice):
    prec = matrice[0]
    if len(prec) != len(parolaIniziale) or len(prec) != len(parolaFinale):
        return False

    for i in range(1, len(matrice)):
        if (len(matrice[i]) != len(parolaIniziale)
                or len(matrice[i]) != len(parolaFinale)):
            return False
        else:
            cont = 0
            for j in range(len(matrice[i])):
                if matrice[i][j] != prec[i]:
                    cont += 1

                if cont > 1:
                    return False
                else:
                    prec = matrice[i]

    return True

def riempi(matrice):
    N = int(input())
    M = int(input())

    for i in range(N):
        matrice.append([])
        for _ in range(M):
            matrice[i].append(input())
