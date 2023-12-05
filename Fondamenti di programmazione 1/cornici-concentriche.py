# Data una matrice n per m, stampa la somma delle cornici concentriche della
# matrice.

def main():
    mat = []
    n = int(input())
    m = int(input())

    riempiMatrice(mat, n, m)
    stampaMatrice(mat)

    # Stampa la somma degli elementi di ciascuna cornice
    for i in range(len(mat) // 2):
        print(sommaCornice(mat, i))

    # Elemento centrale
    if len(mat) % 2 != 0:
        print(mat[len(mat) // 2][len(mat) // 2])

def riempiMatrice(matriceVuota, righe, colonne):
    for i in range(righe):
        matriceVuota.append([])
        for _ in range(colonne):
            matriceVuota[i].append(int(input()))

def stampaMatrice(matrice):
    for i in range(len(matrice)):
        for j in range(len(matrice[i])):
            print(matrice[i][j], end="")
        print()

def sommaCornice(matrice, cornice):
    somma = 0
    for i in range(len(matrice) - cornice):
        somma += matrice[cornice][i] + matrice[len(matrice) - cornice -i][i]
    for i in range(cornice + 1, len(matrice) - cornice - 1):
        somma += matrice[i][cornice] + matrice[i][len(matrice) - cornice - i]

    return somma

main()
