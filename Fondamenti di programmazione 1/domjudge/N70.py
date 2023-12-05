stringa = list(input())

for car in range(len(stringa)):
    for vocale in 'aeiou':
        if stringa[car] == vocale:
            stringa.pop(car)
            stringa.insert(car, vocale + "f" + vocale)

stringa = ''.join(stringa)
stringa = list(stringa)

secondaParte = []

for i in range(len(stringa) // 2, len(stringa)):
    secondaParte.insert(0, stringa.pop(len(stringa) - 1))


print(''.join(secondaParte + stringa), end="")
