# Letto da input iu intero stampa "Si" se tutte le cifre sono diverse da 0,
# altrimenti stampa "NO".

N = input()

cifreDiverseDaZero = True

for char in N:
    if char == "0":
        cifreDiverseDaZero = False

if cifreDiverseDaZero:
    print("SI", end="")
else:
    print("NO", end="")
