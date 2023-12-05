somme = []
prec = -1
corr = int(input())
sommaCorrente = 0

while not(prec == corr == 0):
    sommaCorrente += corr
    if corr == 0:
        somme.append(sommaCorrente)
        sommaCorrente = 0

    prec = corr
    corr = int(input())

if len(somme) == 0:
    print(0)
else:
    for i in somme:
        print(i)
