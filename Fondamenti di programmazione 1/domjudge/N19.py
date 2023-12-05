stringa = input()

contieneCifre = False

while stringa != "*":
    if stringa.isdigit():
        contieneCifre = True
    stringa = input()


if contieneCifre:
    print("ALMENO UNA", end="")
else:
    print("NESSUNA", end="")
