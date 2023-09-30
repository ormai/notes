from math import floor, sqrt
n = int(input("Scrivi un numero: "))

def isPrime(n):
    if n == 1 or n == 0:
        return False
    elif n < 4:
        return True # 2 e 3 sono primi
    elif n % 2 == 0:
        return False # i pari non sono primi (eccetto 2)
    elif n < 9:
        return True
    elif n % 3 == 0: # i multipli di 3 non sono primi
        return False
    else: # ciò che resta
        limite = floor(sqrt(n))
        divisore = 5

        while divisore <= limite:
            if n % divisore == 0 or n % (divisore + 2) == 0:
                return False

            divisore += 6

    return True

if isPrime(n):
    print(n, "è primo.")
else:
    print(n, "non è primo.")
