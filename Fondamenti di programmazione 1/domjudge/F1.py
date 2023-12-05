def main():
    A = int(input()) # A < B
    B = int(input())

    intervallo = []
    for i in range(A, B + 1):
        intervallo.append(i)

    for i in range(len(intervallo)):
        divisoriFisso = sommaDivisoriPropri(intervallo[i])
        for j in range(i + 1, len(intervallo)):
            if divisoriFisso == intervallo[j] and \
                sommaDivisoriPropri(intervallo[j]) == intervallo[i]:
                    print("SI", end="")
                    return
    print("NO", end="")

# def fidanzati(n, m):
#     if sommaDivisoriPropri(n) == m and sommaDivisoriPropri(m) == n:
#         return True
#
#     return False

def sommaDivisoriPropri(n):
    somma = 0
    for i in range(1, n):
        if n % i == 0:
            if i != 1:
                somma += i
    return somma

main()
