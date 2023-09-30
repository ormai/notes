def main():
    M = int(input()) # giudici, righe, i
    N = int(input()) # cantanti, colonne, j
    tabella = []
    for i in range(M):
        tabella.append([])
        for _ in range(N):
            tabella[i].append(int(input()))

    print(giudicePiuBuono(tabella), cantantePiuScarso(tabella), end="")

def cantantePiuScarso(mat):
    cantanti = [0] * len(mat[0])
    for i in range(len(mat)):
        for j in range(len(mat[i])):
            cantanti[j] += mat[i][j]

    min = cantanti[0]
    index = 0
    for i in range(len(cantanti)):
        if cantanti[i] <= min:
            index = i
            min = cantanti[i]

    return index

def giudicePiuBuono(mat):
    voti = [0] * len(mat) # numero di voti > 5
    for i in range(len(mat)):
        for j in range(len(mat[i])):
            if mat[i][j] > 5:
                voti[i] += 1

    max = voti[0]
    index = 0
    for i in range(len(voti)):
        if voti[i] >= max:
            index = i
            max = voti[i]

    return index

main()
