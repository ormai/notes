def main():
    N = int(input())
    mat = []
    for i in range(N):
        mat.append([])
        for _ in range(N):
            mat[i].append(int(input()))

    if ripetizioni(mat): 
        print("SI", end="")
    else:
        print("NO", end="")

def ripetizioni(m):

    # Controlla le righe
    for i in range(len(m)):
        for j in range(len(m[i])):
            for k in range(j + 1, len(m[i])):
                if m[i][j] == m[i][k]:
                    return False

    # Controlla le colonne
    for j in range(len(m[0])):
        for i in range(len(m)):
            for l in range(i + 1, len(m)):
                if m[i][j] == m[l][j]:
                    return False

    return True

main()
