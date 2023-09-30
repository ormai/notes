# Somma delle cornici concentriche di una matrice. Farlo in più modi.

# Costruire la matrice n x m
n = int(input("Numero righe matrice: "))
m = int(input("Numero colonne matrice: "))

matrice = []
for i in range(n):
    matrice.append([])
    for j in range(m):
        matrice[i].append(int(input("Elemento da inserire nella matrice: ")))

copia = list(matrice)

def corniciConcentriche(b, h):
    '''
    Date le due dimensioni di una matrice restituisce il numero di cornici
    concentriche che la matrice contiene. L'ordine degli argomenti non è
    importante
    '''
    # Il numero di cornici concentriche è dato dalla divisione della dimensione
    # minore della matrice per 2. Se questa dimensione è pari il risultato della
    # divisione sarà il numero di cornici concentriche. Se la dimensione è
    # dispari bisognerà sommare 1 alla divisione.
    quoziente = min(b, h) // 2
    return quoziente if quoziente % 2 == 0 else quoziente + 1


somme = []

for cornice in range(corniciConcentriche(n, m)):
    somme.append(0)
    for i in range(n):
        for j in range(m):
            if (i == cornice or i == n - cornice - 1) \
                    or (j == cornice or j == m - cornice - 1):
                somme[cornice] += copia[i][j]
                copia[i][j] = 0

for i in range(len(somme)):
    print("Somma della", i + 1, "cornice esterna è", somme[i])
