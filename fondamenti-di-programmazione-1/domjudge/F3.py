def main():
    griglia = []
    parole = []
    getInput(griglia, parole)

    invertita = hiddenWord(griglia, parole)
    print(invertita[::-1], end="")

def hiddenWord(griglia, parole):
    # Cancella le parole
    for parola in parole:
        searchAndReplaceInRows(griglia, parola)
        searchAndReplaceInColumns(griglia, parola)
        searchAndReplaceInDiagonal(griglia, parola)

    # Trova la parola nascosta
    # 2 dimensioni --> 1 dimensione
    joined = []
    for i in range(len(griglia)):
        for j in range(len(griglia[0])):
            joined.append(griglia[i][j])

    return setaccio(joined)

def setaccio(lista):
    """Raccoglie i caratteri rimasti nella griglia per formare la
       parola nascosta.
       È una funzione ricorsiva."""

    if len(lista) == 1:
        if len(lista[0]) == 1:
            return lista[0]
        return ""

    first = lista[0]
    if len(first) != 1:
        first = ""

    return setaccio(lista[1:]) + first

def searchAndReplaceInDiagonal(griglia, parola):
    # mat[5][0]
    # mat[4][0] + mat[5][1]
    # mat[3][0] + mat[4][1] + mat[5][2]
    # mat[2][0] + mat[3][1] + mat[4][2] + mat[5][3]
    # mat[1][0] + mat[2][1] + mat[3][2] + mat[4][3] + mat[5][4]
    # mat[0][0] + mat[1][1] + mat[2][2] + mat[3][3] + mat[4][4] + mat[5][5]
    # mat[0][1] + mat[1][2] + mat[2][3] + mat[3][4] + mat[4][5]
    # mat[0][2] + mat[1][3] + mat[2][4] + mat[3][5]
    # mat[0][3] + mat[1][4] + mat[2][5]
    # mat[0][4] + mat[1][5]
    # mat[0][5]
    # i e j incrementano in parallelo
    for j in range(len(griglia[0])): # diagonali dagli indici delle colonne
        diagonale = convertDiagFromCol(griglia, j)
        if parola in diagonale:
            trovato = False
            i = 0
            while not trovato:
                if (parola[0] == griglia[i][j][0]
                      and parola[len(parola) - 1]
                      == griglia[i + len(parola) - 1][j + len(parola) - 1][0]):
                    trovato = True
                    a = i
                    b = j
                    while b != (j + len(parola)):
                        griglia[a][b]+= '*'
                        a += 1
                        b += 1
                else:
                    i += 1
                    j += 1

    # diagonali che partono dagli indici delle righe
    # La prima riga è esclusa perché già trattata dal ciclo precedente.
    for i in range(1, len(griglia)): 
        diagonale = convertDiagFromRow(griglia, i)
        if parola in diagonale:
            trovato = False
            j = 0
            while not trovato:
                if (parola[0] == griglia[i][j][0]
                      and parola[len(parola) - 1]
                      == griglia[i + len(parola) - 1][j + len(parola) - 1][0]):
                    trovato = True
                    a = i
                    b = j
                    while a != (i + len(parola)):
                        griglia[a][b] += '*'
                        a += 1
                        b += 1
                else:
                    i += 1
                    j += 1

def convertDiagFromRow(griglia, i):
    parola = ""
    j = 0
    while i != len(griglia):
        parola += griglia[i][j][0]
        i += 1
        j += 1

    return parola

def convertDiagFromCol(griglia, j):
    parola = ""
    i = 0
    while j != len(griglia[0]):
        parola += griglia[i][j][0]
        i += 1
        j += 1

    return parola

def searchAndReplaceInColumns(griglia, parola):
    for j in range(len(griglia[0])): # Per ogni colonna
        colonna = convertCol(griglia, j)
        if parola in colonna:
            trovato = False
            c = 0
            while not trovato:
                if (parola[0] == griglia[c][j][0]
                        and parola[len(parola) - 1]
                        == griglia[c + len(parola) - 1][j][0]):
                    for d in range(c, len(parola) + c):
                        griglia[d][j] += '*'
                    trovato = True
                else:
                    c += 1

def searchAndReplaceInRows(griglia, parola):
    for i in range(len(griglia)): # Per ogni riga
        riga = convert(griglia[i])
        if parola in riga:
            trovato = False
            c = 0
            while not trovato:
                if (parola[0] == griglia[i][c][0]
                        and parola[len(parola) - 1]
                        == griglia[i][len(parola) - 1 + c][0]):
                    for d in range(c, len(parola) + c): # sostituisci
                        griglia[i][d] += '*'
                    trovato = True
                else:
                    c += 1

def convertCol(griglia, indice):
    somma = ""
    for i in range(len(griglia)):
        somma += griglia[i][indice][0]

    return somma

def convert(lista):
    somma = ""
    for c in lista:
        somma += c[0]

    return somma

def getInput(griglia, parole):
    N = int(input())
    M = int(input())
    for i in range(N):
        griglia.append([])
        for _ in range(M):
            griglia[i].append(input())

    K = int(input())
    for _ in range(K): parole.append(input())

main()
