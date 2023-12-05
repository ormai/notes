# Scrivere un programma che letti da input:
# - il saldo iniziale (del primo mese) di un conto corrente,
# - il canone mensile,
# - la percentuale di interesse
# stampi il saldo del conto per il primo mese, il secondo e il terzo. A tal
# proposito, si tenga in considerazione che:
# - ogni mese, tranne il primo, viene addebitato il canone mensile,
# - ogni mese, tranne il primo, vengono accreditati interessi,
# - gli interessi vanno attribuiti dopo aver detratto il canone mensile.

# Esempio. Supponendo che il primo mese il saldo è 1000 €, il canone mensile è
# 2 € e la percentuale di interesse è 1%, il programma dovrebbe stampare
# seguendo il seguente formato:

# PRIMO MESE: 1000
# SECONDO MESE: 1008
# TERZO MESE: 1016

# N.B.: Nel caso in cui un saldo sia un numero decimale, va stampato DOPO averlo
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

Saldo = int(input())
Canone = int(input())
Tasso = int(input()) / 100

secondoMese = (Saldo - Canone) + ((Saldo-Canone) * Tasso)
terzoMese = (secondoMese - Canone) + ((secondoMese - Canone) * Tasso)

print("PRIMO MESE:", round(Saldo))
print("SECONDO MESE:", round(secondoMese))
print("TERZO MESE:", round(terzoMese), end="")
