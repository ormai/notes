A = []
for i in range(26):
    A.append(input())

N = int(input())
B = []
for i in range(N):
    B.append(int(input()))

parolaNascosta = ""
for X in range(len(B)):
    if B[X] < 26:
        parolaNascosta += str(A[B[X]])

print(parolaNascosta, end="")
