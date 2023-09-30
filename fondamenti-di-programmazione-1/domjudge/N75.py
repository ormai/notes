def main():
    frase = input()
    alfabeto = [
        "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n",
        "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"
    ]

    for car in frase:
        for i in range(len(alfabeto)):
            if i >= 0 and i < len(alfabeto):
                if alfabeto[i] == car or alfabeto[i].upper() == car:
                    alfabeto.pop(i)

    if len(alfabeto) == 0:
        print("SI", end="")
    else:
        print("NO", end="")

main()
