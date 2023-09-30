def main():
    A = int(input())
    B = int(input())
    # A > B
    print(MCDricorsivo(A, B, A % B), end="")

c = 0

def MCDricorsivo(dividendo, divisore, resto):
    global c
    c += 1
    if dividendo == 0 or divisore == 0:
        return 0

    if resto == 0:
        return divisore

    return MCDricorsivo(divisore, resto, divisore % resto)


main()
