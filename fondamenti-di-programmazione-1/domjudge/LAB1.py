def main():
    N = int(input())
    seq = []
    for _ in    range(N):
        seq.append(int(input()))

    print(sommaMassima(seq), end="")


def sommaMassima(mat):
    massimo = 0
    for i in range(len(mat)):
        for j in range(i, len(mat)):
            somma = mat[i] + mat[j]
            if (somma % 2 != 0) and not isPrime(somma):
                if somma > massimo:
                    massimo = somma
    return massimo

def isPrime(n):
    if n in (1, 2): return True
    for i in range(3, n // 2, 2):
        if n % i == 0:
            return False
    return True

main()
