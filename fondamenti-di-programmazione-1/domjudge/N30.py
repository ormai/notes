condizione = False

prec = ""
char = input()
while char != "*":
    if (prec == char
        and prec.isalpha()
        and char.isalpha()
        and (char.islower()
        and prec.islower())
        or (
            char.isupper()
            and prec.isupper())):

        condizione = True
    prec = char
    char = input()

if condizione:
    print("SI", end="")
else:
    print("NO", end="")
