from math import sqrt

n = int(input())
radice = round(sqrt(n))

primo = True

for i in range(2, radice+1):
    if n % i == 0:
        primo = False
        break

if n != 1 and primo:
    print("SI", end="")
else:
    print("NO", end="")
