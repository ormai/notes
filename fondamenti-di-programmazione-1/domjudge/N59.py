n = int(input())
A = []

for i in range(n):
    A.append([])
    for j in range(n):
        A[i].append(int(input()))

centrale = n // 2 # Sempre se è dispari
sommaCroce = 0
sommaRestanti = 0

for i in range(n):
    for j in range(n):
        if i == centrale or j == centrale:
            sommaCroce += A[i][j]
        else:
            sommaRestanti += A[i][j]

if sommaCroce > sommaRestanti:
    print("OK", end="")
else:
    print("NO", end="")
