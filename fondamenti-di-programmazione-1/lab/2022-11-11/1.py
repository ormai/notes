from random import randint

dado1 = randint(1, 6)
dado2 = randint(1, 6)

sommaDadi = dado1 + dado2

if sommaDadi == 7 or sommaDadi == 11:
    print("HAI VINTO")
elif sommaDadi == 2 or sommaDadi == 3 or sommaDadi == 12:
    print("HAI PERSO")
else:
    P = sommaDadi
    dado1 = randint(1, 6)
    dado2 = randint(1, 6)
    sommaDadi = dado1 + dado2

    while sommaDadi != 7 and sommaDadi != P:
        dado1 = randint(1, 6)
        dado2 = randint(1, 6)
        sommaDadi = dado1 + dado2

        if sommaDadi == 7:
            print("HAI VINTO")
        elif sommaDadi == P:
            print("HAI PERSO")
