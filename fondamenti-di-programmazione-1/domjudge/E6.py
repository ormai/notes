def main():
    N = int(input())
    X = int(input())
    tabella = []
    for i in range(N):
        tabella.append([])
        for _ in range(2):
            tabella[i].append(int(input()))

    print(annoDominante(tabella), end=" ")
    print("SI", end="") if noRiproduzioni(tabella, X) else print("NO", end="")

def noRiproduzioni(M, anno):
    for i in range(len(M)):
        if M[i][1] == anno and M[i][0] != 0:
            return False
    return True

def annoDominante(M):
    elementi = []
    for i in range(len(M)):
        elementi.append(M[i][1])

    anni = []
    for i in elementi:
        if i not in anni:
            anni.append(i)
    anni = sorted(anni)

    cont = []
    for i in range(len(anni)):
        cont.append(0)
        for j in elementi:
            if anni[i] == j:
                cont[i] += 1

    max = 0
    index = cont[0]
    for i in range(len(cont)):
        if cont[i] >= max:
            max = cont[i]
            index = i

    return anni[index]

main()
