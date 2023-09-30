n = int(input())
penultimo = 0
terzultimo = 0
conteggio = 0

while not(terzultimo == penultimo == n == 9):
    if n == penultimo == terzultimo:
        conteggio +=1

    terzultimo = penultimo
    penultimo = n
    n = int(input())

print(conteggio, end="")
