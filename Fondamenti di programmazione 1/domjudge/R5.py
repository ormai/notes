def main():
    N = int(input()) # N <= 10

    lista = []
    for _ in range(N): lista.append(int(input()))

    print(reverseL(lista, 0), end='')

def reverseL(L, pos):

    if pos == len(L) - 1:
        return str(L[pos])

    return reverseL(L, pos + 1) + str(L[pos])

main()
