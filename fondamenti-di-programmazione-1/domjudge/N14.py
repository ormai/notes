sequenza = []
risultato = 0
soloDecimali = True

n = int(input()) # Costruisci la sequenza di interi
while n != -1:
    sequenza.append(n)
    n = int(input())

for i in sequenza:
    if not(len(str(i)) == 1 and str(i).isdigit()): # una cifra decimale
        soloDecimali = False
    else:
        risultato = risultato * 10 + i # giustapponi i numeri della sequenza

if len(sequenza) == 0:
    print("VUOTO", end="")
elif soloDecimali: 
    print(risultato)
    if risultato % 3 == 0:
        print("SI", end="")
    else:
        print("NO", end="")
else:
    print("ERRORE", end="")
