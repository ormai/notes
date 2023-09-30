stringa = input()

contieneAlmenoUnaVocale = False

while stringa != "*":
    if stringa in "aeiou" and stringa != "":
        contieneAlmenoUnaVocale = True
    stringa = input()

if contieneAlmenoUnaVocale:
    print("ALMENO 1 VOCALE", end="")
else:
    print("NESSUNA VOCALE", end="")
