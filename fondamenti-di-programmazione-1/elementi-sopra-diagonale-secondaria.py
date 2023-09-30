# somma degli elementi che si trovano sopra la diagonale secondaria

n = int(input())
somma = 0

mat=[]
for i in range(n):
    mat.append([])
    for j in range(n):
        mat[i].append(int(input()))

for i in range(1, n):
    for j in range(n - 1 - i, n):
        somma += mat[i][j]

print(somma)
