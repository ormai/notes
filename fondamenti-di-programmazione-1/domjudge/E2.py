def main():
    global N # read-only
    N = int(input())
    nonogram = []
    numeriLatoColonne = []
    numeriLatoRighe = []

    # N = len(numeriLatoRighe) =
    # = len(numeriLatoColonne) = len(nonogram) = len(nonogram[0])

    getInput(nonogram, numeriLatoColonne, numeriLatoRighe) # Riempi tutto

    if isCorrect(nonogram, numeriLatoColonne, numeriLatoRighe):
        print("SI", end="")
    else:
        print("NO", end="")

def isCorrect(mat, nCol, nRiga):
    '''Controlla se ogni riga e ogni colonna di mat ha un numero consecutivo di
    1 uguale a quello indicato nell'elemento corrispettivo di nCol o nRiga.'''

    for i in range(N): 
        nel = nCol[i] # 1 che devono essere in riga affinché sia corretto
        col = i
        if (nel == 0 and unaOccorrenzaInColonna(mat, col)) or \
            (nel == 1 and not unaOccorrenzaInColonna(mat, col)) or \
            (nel > 1 and occorrenzeConsecutiveInUnaColonna(mat, col) != nel):
            return False

        ner = nRiga[i] # 1 che devono essere in riga affinché sia corretto
        riga = mat[i]
        if (ner == 0 and 1 in riga) or \
            (ner == 1 and 1 not in riga) or \
            (ner > 1 and occorrenzeConsecutiveInUnaRiga(riga) != ner): 
            return False

    return True

def occorrenzeConsecutiveInUnaColonna(mat, col):
    '''Conta le occorrenze consecutive di 1 in ogni colonna.
        Se non vi sono occorrenze restituisce 0.
    '''

    cons = 0
    for i in range(N):
        if mat[i][col] == 1 and \
            ((i - 1 >= 0 and mat[i - 1][col] == 1) or 
                (i + 1 < N and mat[i + 1][col] == 1)):
            cons += 1

    return cons

def unaOccorrenzaInColonna(mat, indiceColonna):
    '''Controlla se una certa colonna di una matrice contiene 1.'''

    for i in range(N):
        if mat[i][indiceColonna] == 1 : return True

    return False

def occorrenzeConsecutiveInUnaRiga(riga):
    '''Conta le occorrenze consecutive di 1 in ogni riga.
        Se non vi sono occorrenze restituisce 0.
    '''

    cons = 0
    for j in range(N):
        if riga[j] == 1 and\
            ((j - 1 >= 0 and riga[j - 1] == 1)
             or (j + 1 < N and riga[j + 1] == 1)):
            cons += 1

    return cons

def getInput(nonogram, listaColonne, listaRighe):
    '''Riempi il nonogram e le due liste di numeri al lato con itneri presi da
    input.'''

    for i in range(N):
        nonogram.append([])
        for _ in range(N):
            nonogram[i].append(int(input())) # 0 or 1

    for i in range(N) : listaColonne.append(int(input()))
    for i in range(N) : listaRighe.append(int(input()))

main()
