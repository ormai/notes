# Per controllare se n è una potenza di due o no lo divido per 2
# ripetutamente. Se n è una potenza di due il cilco termina quando n è
# esattamente 2, atlrimenti si continua a dividere finché n diventa
# minore di due.

sonoTuttiPotenzeDiDue = True # condizione vera in partenza

n = int(input()) # leggi intero da input

while n != 0: # tappo
    while n > 2:
        n /= 2

    if n < 2:
        sonoTuttiPotenzeDiDue = False

    n = int(input()) # leggi nuovo intero

if sonoTuttiPotenzeDiDue:
    print("SI", end="")
else:
    print("NO", end="")
