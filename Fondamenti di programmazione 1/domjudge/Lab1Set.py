def main():
    N = input()
    print(abracadabra(N), end="")

def abracadabra(numero):
    n = convert(numero)

    for i in range(len(n) - 1, 0, -1):
        if n[i] < 5:
            n[i] = 0
        else:
            n[i] = 0
            n[i - 1] += 1

    return unisci(n)

def unisci(listaDiInteri):
    risultato = 0
    for i in listaDiInteri:
        risultato = risultato * 10 + i
    return risultato

def convert(stringaDiNumeri):
    risultato = []
    for i in stringaDiNumeri:
        risultato.append(int(i))
    return risultato

main()
