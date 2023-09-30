def main():
    N = int(input()) # N >= 2 and N <= 10
    matrice = []
    for i in range(N):
        matrice.append([])
        for _ in range(N):
            matrice[i].append(int(input()))

    if L(matrice, 0):
        print("SI", end="")
    else:
        print("NO", end="")

def L(mat, i):
    # For all the Ls in mat:
    # - sum the elements in the L
    # - Check if the element of the L that is also 
    #in the secondary diagonal is multiple of the sum

    if len(mat) == 0: # non c'è nei test
        return False

    length = len(mat) - 1
    #print("(%d) ENTERNIG, length: %d" % (c, length))
    # Deve essere ripetuta len(mat) - 2 volte

    if i == length: # FINE
        return True # semplicemente fermati

    if L(mat, i + 1):
        if mat[length - i][i] != 0:
            if sumL(mat, i, 0) % mat[length - i][i] != 0:
                return False
            else:
                return True


def sumL(mat, i, j):
    # i è il numero della L
    # j si muove per fare la somma. Nella chiamata originale è sempre 0

    # i = 0
    # mat[0][0] + mat[4][4]
    # mat[1][0] + mat[4][3]
    # mat[2][0] + mat[4][2]
    # mat[3][0] + mat[4][1]
    # mat[4][0] + mat[4][0]

    # i = 1
    # mat[0][1] + mat[3][4]
    # mat[1][1] + mat[3][3]
    # mat[2][1] + mat[3][2]
    # mat[3][1] + mat[3][1]

    # i = 2
    # mat[0][2] + mat[2][4]
    # mat[1][2] + mat[2][3]
    # mat[2][2] + mat[2][2]

    # i = 3
    # mat[0][3] + mat[1][4]
    # mat[1][3] + mat[1][3]

    # i = 4
    # mat[0][4] + mat[0][4]


    length = len(mat) - 1
    vert = mat[j][i]
    oriz = mat[length - i][length - j]

    if j == length - i and i == length - j:
        return vert

    return sumL(mat, i, j + 1) + vert + oriz

main()
