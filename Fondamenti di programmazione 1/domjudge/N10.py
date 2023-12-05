# Letto da input un numero intero positivo ottenere il numero con le cifre
# invertite e stmpare la differenza tra i due.

N = input()
inv = ""

for i in range(len(N)):
    inv += N[len(N)-1-i]

print(int(N) - int(inv), end="")
