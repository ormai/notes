# Su una linea ferroviaria, rispetto alla tariffa piena, gli utenti pensionati
# usufruiscono di uno sconto del 10%, gli studenti del 15% e i disoccupati del
# 25%. Scrivere un programma che, letti da input due numeri rappresentanti
# rispettivamente il costo di un biglietto (un valore reale) e la condizione di
# sconto dell'utente (0 per nessuno sconto, 1 per sconto pensionati, 2 per
# sconto studenti e 3 per sconto disoccupati) visualizzi l'Importo da pagare
# arrotondato a 3 cifre decimali (si usi a tal proposito la funzione round).

Importo = float(input())
TipoDiSconto = int(input())

if TipoDiSconto == 0:
    print(round(Importo, 3), end="")
elif TipoDiSconto == 1:
    print(round(Importo - (Importo * 1 / 10), 3), end="")
elif TipoDiSconto == 2:
    print(round(Importo - (Importo * 15 / 100), 3), end="")
elif TipoDiSconto == 3:
    print(round(Importo - (Importo * 25 / 100), 3), end="")
