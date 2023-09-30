stringa = input()

contieneAlmenoUnAlpha = False

while stringa != ".":
    if stringa.isalpha():
        contieneAlmenoUnAlpha = True
    stringa = input()

if contieneAlmenoUnAlpha:
    print("SI", end="")
else:
    print("NO", end="")
