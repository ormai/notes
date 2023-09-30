def main():
    global alfabeto
    alfabeto = (
        "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N",
        "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"
    )

    n1 = int(input())
    n2 = int(input())
    parola = []
    tmp = input()
    while tmp != ".":
        parola.append(tmp)
        tmp = input()

    if len(parola) > 0:
        print(parolaCifrata(parola, n1, n2), end="")

def parolaCifrata(s, n1, n2):
    result = s

    for i in range(len(s)):
        pos = i + 1
        if pos % 2 != 0:
            result[i] = letteraI(result[i], n1)
        else:
            result[i] = letteraJ(result[i], n2)

    return "".join(result)

def letteraI(car, pos):
    curr = alfabeto.index(car)

    if (curr + pos) >= len(alfabeto):
        return alfabeto[(curr + pos) - len(alfabeto)]

    return alfabeto[curr + pos]

def letteraJ(car, pos):
    curr = alfabeto.index(car)
    if curr - pos < 0:
        return alfabeto[(curr - pos) + len(alfabeto)]

    return alfabeto[curr - pos]

main()
