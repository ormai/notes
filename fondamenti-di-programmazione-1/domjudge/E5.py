def main():
    seq = []
    car = input()
    while car != "*":
        seq.append(car)
        car = input()

    subSeq = sottosequenzaMax(sottosequenze(seq))

    print(intervalloLettere(subSeq), end="")

def intervalloLettere(L):
    if len(L) == 0: return 0
    inf = ord(L[0])
    sup = ord(L[len(L) - 1])

    return abs(inf - sup) - 1

def sottosequenze(L):
    sottosequenze = []
    curr = []
    for i in range(len(L)):
        if i - 1 >= 0:
            if (L[i - 1] >= L[i]):
                curr.append(L[i - 1])
                #print(curr)
            else:
                sottosequenze.append(curr)
                curr = []

    if L[len(L) - 1] <= L[len(L) - 2]:
        curr.append(L[len(L) - 1])
    sottosequenze.append(curr)
    #print(sottosequenze)
    return sottosequenze

def sottosequenzaMax(L):
    massimo = []
    for i in L:
        if len(i) >= 2 and len(i) > len(massimo):
            massimo = i
    #print(massimo)
    return massimo

main()
