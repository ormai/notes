from random import randint#, seed
#seed(0)

punteggioPc = 0
punteggioGiocatore = 0

while punteggioPc < 3 and punteggioGiocatore < 3:
    giocata = 0
    while giocata != 1 and giocata != 2 and giocata != 3:
        giocata = int(input("Inserisci la giocata del primo giocatore \
(1: sasso, 2: carta, 3: forbice):"))

    if giocata == 1:
        print("hai giocato sasso")
    elif giocata == 2:
        print("hai giocato carta")
    else:
        print("hai giocato forbice")

    pc = randint(1, 3)

    if pc == 1:
        print("il PC ha giocato sasso")
    elif pc == 2:
        print("il PC ha giocato carta")
    else:
        print("il PC ha giocato forbice")

    if ((giocata == 1 and pc == 3)
            or (giocata == 2 and pc == 1)
            or (giocata == 3 and pc == 2)):
        punteggioGiocatore += 1
        print("Vinci tu:")
    elif ((pc == 1 and giocata == 3)
            or (pc == 2 and giocata == 1)
            or (pc == 3 and giocata == 2)):
        punteggioPc += 1
        print("Vince il PC:")
    else:
        print("Pari:")

    print("%d-%d" % (punteggioGiocatore, punteggioPc))

if punteggioGiocatore > punteggioPc:
    print("Hai vinto la sfida!")
else:
    print("Il PC ha vinto la sfida!")
