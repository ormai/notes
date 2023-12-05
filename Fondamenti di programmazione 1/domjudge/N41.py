def main():
    global posti, postiNonFumatoriOccupati, postiFumatoriOccupati
    posti = [0] * 10
    postiFumatoriOccupati = 0
    postiNonFumatoriOccupati = 0

    while 0 in posti: # Finché non sono pieni tutti i posti
        fumatori = int(input("Digitare 1 per fumatori o 2 per non fumatori:"))

        if fumatori == 1:
            if postiFumatoriOccupati < 5:
                assegnaPostoFumatore()
            else:
                if altroReparto() and postiNonFumatoriOccupati < 5:
                    assegnaPostoNonFumatore()
                else:
                    print("Il prossimo volo parte tra 3 ore") 
        else:
            if postiNonFumatoriOccupati < 5:
                assegnaPostoNonFumatore()
            else:
                if altroReparto() and postiFumatoriOccupati < 5:
                    assegnaPostoFumatore()
                else:
                    print("Il prossimo volo parte tra 3 ore") 

def altroReparto():
    scelta = input("Reparto scelto al completo. \
Si desidera un posto nell'altro reparto (S/N)?")
    return True if scelta == 'S' else False

def assegnaPostoFumatore():
    global postiFumatoriOccupati
    numPosto = 0 # Serve unicamente per stampare il numero di posto

    for i in range(5):
        if posti[i] == 0:
            postiFumatoriOccupati += 1
            posti[i] = 1
            numPosto = i + 1
            break
    print("Reparto fumatori, posto", numPosto)

def assegnaPostoNonFumatore():
    global postiNonFumatoriOccupati
    numPosto = 0

    for i in range(5, 10):
        if posti[i] == 0:
            postiNonFumatoriOccupati += 1
            posti[i] = 1
            numPosto = i + 1
            break
    print("Reparto NON fumatori, posto", numPosto)

main()
