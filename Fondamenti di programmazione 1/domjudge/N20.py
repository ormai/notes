stringa = input()

alpha = True

while stringa != ".":
    if not(stringa.isalpha()):
        alpha = False
    stringa = input()

if alpha:
    print("SI", end="")
else:
    print("NO", end="")
