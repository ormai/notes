stringa = input()

contieneAlpha = False

while stringa != ".":
    if stringa.isalpha():
        contieneAlpha = True
    stringa = input()

if contieneAlpha:
    print("NO", end="")
else:
    print("SI", end="")
