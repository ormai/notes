def main():
    N = int(input())
    print(successione(N), end="")

def successione(n):
    if n == 0: return 2

    return 3 * (n + 1) * successione(n - 1)

main()
