def main():
    # chiama collatz(n) e stampane il risultato
    print(collatz(int(input("Scrivi un numero positivo: "))))
    # bello python

def collatz(n):
    if n == 1:
        return 1
    elif n % 2 == 0:
        return collatz(n / 2) + 1
    else:
        return collatz(n * 3 + 1) + 1

main()
