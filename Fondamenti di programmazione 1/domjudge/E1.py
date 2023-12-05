def main():
    data = []
    getInput(data)

    if correct(data):
        print("SI", end="")
    else:
        print("NO", end="")

def correct(l):
    # Controlla se l contiene le stringhe necessarie per formare la definizione
    # di una funzione.
    if (l[0] != "def") or (not correctName(l[1])) \
        or (l[2] != "(") or (")" not in l[3 : ]):
        return False 

    # variable number of arguments separated by a comma
    i = 3
    while l[i] != ")":
        if isEven(i) and l[i] != ",":
            return False
        if not correctName(l[i]) and not isEven(i):
            return False

        i += 1

    return True

def getInput(l):
    # Riempi l con l'input dell'utente fermati a ':'
    item = input()
    while item != ":":
        l.append(item)
        item = input()

def correctName(word):
    # Controlla che word rispetti le regole di Python per i nomi di variabili

    if word[0].isdigit():
        return False # Il nome non può iniziare con un numero

    for char in word:
        if not(char.isalnum()) and char != "_":
            return False

    return True

def isEven(n):
    if n % 2 == 0 : return True
    return False

main()
