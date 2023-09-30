from random import randint

def main():
    mat = [
        [5, 9, 4],
        [9, 1, 7],
        [4, 6, 8],
    ]
    x = []
    crea(mat, x)
    print(x)

def crea(matrice, lista):
    while len(lista) < len(matrice[0]):
        i = randint(1, len(matrice) - 1)
        j = randint(1, len(matrice[0]) - 1)
        elementoCasuale = matrice[i][j]
        if elementoCasuale not in lista:
            lista.append(elementoCasuale)

main()

# La funzione crea() modifica 'lista' che è definita localmente nella funzione
# main(). crea() non restituisce valore e comunque lista viene modificata.
