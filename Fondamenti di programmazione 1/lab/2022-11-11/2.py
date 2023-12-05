prec = ""
char = input()

noAlnum = False
cifra = False
alpha = False
onlyLower = True
onlyUpper = True
decrescente = True
consecutive = False

while char != ".":
    prec = char
    char = input()

    if not(char.isalnum()):
        noAlnum = True
    if char.isdigit():
        cifra = True
    if char.isalpha():
        alpha = True
    if char.isupper():
        onlyLower = False
    if char.islower():
        onlyUpper = False
    if prec < char:
        decrescente = False
    if prec == char:
        consecutive = True

if noAlnum:
    print("NON ALFANUMERICA")

if cifra:
    print("ALMENO UN NUMERO")

if not cifra and alpha:
    print("ALFABETICA")

if not cifra and onlyLower:
    if decrescente:
        print("MINUSCOLE SI")
    else:
        print("MINUSCOLE NO")

if onlyUpper and not cifra:
    if consecutive:
        print("MAIUSCOLE SI")
    else:
        print("MSIUSCOLE NO")
