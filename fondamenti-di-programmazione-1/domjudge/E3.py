def main():
    seq = []
    n = input()
    while n != "*":
        seq.append(int(n))
        n = input()


    print(func(seq), end="")

def func(lista):
    l = len(lista)
    # sim : sottosequenze incrementali massimali
    sim = []
    tmp = []

    for i in range(l):
        if i != l - 1:
            if i - 1 >= 0:
                if lista[i - 1] + 1 == lista[i]:
                    tmp.append(lista[i])
                elif len(tmp) > 0 and lista[i] > lista[i - 1] + 1:
                    sim.append(tmp)
                    tmp = []

            if i + 1 < l:
                if lista[i + 1] - 1 == lista[i]:
                    tmp .append(lista[i])
                elif len(tmp) > 0 and lista[i + 1] > lista[i] + 1:
                    sim.append(tmp)
                    tmp = []
        else:
            if lista[l - 1] == lista[l - 2] + 1:
                tmp.append(lista[l - 1])

            if len(tmp) > 0:
                sim.append(tmp)

    #print(sim)
    return len(sim)

main()
