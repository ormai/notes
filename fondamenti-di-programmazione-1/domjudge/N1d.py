# Scrivere un programma che stampi il SALDO di un conto bancario per il primo
# mese, il secondo e il terzo. A tal proposito, si tenga in considerazione che:
# - il conto appena creato ha un SALDO di 500 €
# - ogni mese, tranne il primo, viene addebitato il canone mensile pari a 5 €
# - ogni mese, tranne il primo, vengono accreditati interessi pari al 2%
# - gli interessi vanno attribuiti dopo aver detratto il canone mensile.

# Supponendo che il primo mese il SALDO è un numero X, il secondo mese un numero
# Y e il terzo mese un numero Z, il programma dovrebbe stampare seguendo il
# seguente formato:

# PRIMO MESE: X
# SECONDO MESE: Y
# TERZO MESE: Z

# N.B.: Nel caso in cui un SALDO sia un numero decimale, va stampato DOPO averlo
# arrotondato ad intero. L’arrotondamento può essere effettuato usando la
# funzione round che riceve come argomenti un numero e il numero di cifre a cui
# arrotondarlo ed effettua l’arrotondamento. Il secondo argomento è opzionale,
# e se omesso viene effettuato l'arrotondamento ad intero.
# Ad esempio, se eseguiamo il seguente programma:
#     n = 15.34501
#     nr = round(n)
#     print(nr)
# otteniamo in output:
#     15

SALDO = 500
TASSO = 2 / 100
CANONE = 5
secondoMese = SALDO - CANONE + (SALDO - 5) * (TASSO)
terzoMese = secondoMese - CANONE + (secondoMese - CANONE) * (TASSO)

print("PRIMO MESE:", round(SALDO))
print("SECONDO MESE:", round(secondoMese))
print("TERZO MESE:", round(terzoMese), end="")
