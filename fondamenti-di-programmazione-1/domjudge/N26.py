prec = ""
char = input()

proprietàSoddisfatta = False

while char != "*":
    if ((prec.isupper() and char.isupper())
            or (prec.islower() and char.islower() and prec == char)):
        proprietàSoddisfatta = True

    prec = char
    char = input()

if proprietàSoddisfatta:
    print("SI", end="")
else: 
    print("NO", end="")
