from math import sqrt

n = int(input())
m = int(input())

def isPrime(x):
    radice = round(sqrt(x))
    primo = True

    for i in range(2, radice+1):
        if x % i == 0:
            primo = False
            break

    if x != 1 and primo:
        return True
    else:
        return False

if isPrime(n) and isPrime(m):
    if abs(m - n) == 2:
        print("gemelli", end="")
    else:
        print("non gemelli", end="")
else:
    print("non entrambi primi", end="")
