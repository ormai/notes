# Calcolare il MCD tra due interi.

N = 126
M = 89

while M != 0:
    resto = N % M
    N = M
    M = resto

print(M)
