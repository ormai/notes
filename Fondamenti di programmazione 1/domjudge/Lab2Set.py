def main():
    n = int(input())
    debolezze = []
    for i in range(1, n + 1):
        debolezze.append(debolezza(i))

    if len(debolezze) > 0:
        print(max(debolezze), end="")
    else:
        print(0, end="")


def debolezza(numero):
    deb = 0
    divisoriN = numeroDivisori(numero)
    for i in range(1, numero): # Per tutti gli interi positivi minori di numero
        if numeroDivisori(i) > divisoriN:
            deb += 1

    return deb

def numeroDivisori(numero):
    cont = 0
    for i in range(1, numero + 1):
        if numero % i == 0:
            cont += 1

    return cont

main()
