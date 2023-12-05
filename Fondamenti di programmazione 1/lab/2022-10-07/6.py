# Esercizio 6. Scrivere un programma che stampi il saldo di un conto bancario
# per il primo mese, il secondo e il terzo. A tal proposito, si tenga in
# considerazione che:
# - il conto appena creato ha un saldo di 500 €;
# - ogni mese, tranne il primo, viene addebitato il canone mensile pari a 5 €;
# - ogni mese, tranne il primo, vengono accreditati interessi pari al 2%;
# - gli interessi vanno attribuiti dopoaver detratto il canone mensile.
# Supponendo che il primo mese il saldo è un numero X, il secondo mese un
# numero Y e il terzo mese un numero Z, il programma dovrebbe stampare seguendo
# il seguente formato:
# PRIMO MESE: X
# SECONDO MESE: Y
# TERZO MESE: Z

saldo = 500
secondoMese = saldo-5 + (saldo-5)*(2/100)
terzoMese = secondoMese-5 + (secondoMese-5)*(2/100)

print("PRIMO MESE:", saldo)
print("SECONDO MESE:", secondoMese)
print("TERZO MESE:", terzoMese)
