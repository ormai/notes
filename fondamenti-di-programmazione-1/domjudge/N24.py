prec = ""
corr = ""
conteggio = 0
vocali = "aeiou"

while corr != ".":
    prec = corr
    corr = input()

    if corr != ".":
        if ((prec in vocali and corr in vocali)
                or (prec not in vocali and corr not in vocali)):
            print(prec, corr)
            conteggio += 1

print(conteggio, end="")
