def main():
    X = int(input())
    N = int(input())
    lista = []
    for _ in range(N): lista.append(int(input()))
    print(func(X, lista), end="")

def func(X, L):
    if X == 0:
        return 0
    else:
        X = findAndReplaceOccurrences(X, L, 0)
        return func(X, L) + X

def findAndReplaceOccurrences(X, L, pos):

    if pos == len(L):
        return 0

    bit = findAndReplaceOccurrences(X, L, pos + 1)
    if L[pos] == X:
        L[pos] = 0
        return bit + 1
    else:
        return bit

main()
