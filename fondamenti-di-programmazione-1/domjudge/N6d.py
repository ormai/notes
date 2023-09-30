# Scrivere un programma che permetta di stabilire la stagione corrispondente
# al Mese inserito come intero dall’utente.

# Ad esempio, se l’utente digita 1 che corrisponde a Gennaio il programma deve
# stampare “INVERNO”. 

# Qualora l’utente digitasse un numero non compreso tra 1 e 2, il programma deve
# stampare “Mese NON VALIDO”.

# Qualora il Mese sia Marzo, Giugno, Settembre o Dicembre, ovvero un Mese a
# cavallo di due stagioni, si richieda all’utente di specificare anche il
# giorno. Se il giorno è compreso tra 1 e 20 (estremi inclusi) si considera la
# stagione precedente altrimenti quella successiva. Per semplicità, si consideri
# la stagione successiva anche se il giorno inserito fosse non valido, ad 
# esempio perché minore di 1.

# Ad esempio, se l’utente digita 6 che corrisponde a Giugno e come giorno digita
# 15 il programma deve stampare “PRIMAVERA”.

Mese = int(input())

if not(Mese >= 1 and Mese <= 12):
    print("Mese NON VALIDO", end="")
elif Mese >= 1 and Mese < 3:
    print("INVERNO", end="")
elif Mese > 3 and Mese < 6:
    print("PRIMAVERA", end="")
elif Mese > 6 and Mese < 9:
    print("ESTATE", end="")
elif Mese > 9 and Mese < 12:
    print("AUTUNNO", end="")
elif Mese == 3:
    giorno = int(input())
    if giorno >= 1 and giorno <= 20:
        print("INVERNO", end="")
    else:
        print("PRIMAVERA", end="")
elif Mese == 6:
    giorno = int(input())
    if giorno >= 1 and giorno <= 20:
        print("PRIMAVERA", end="")
    else:
        print("ESTATE", end="")
elif Mese == 9:
    giorno = int(input())
    if giorno >= 1 and giorno <= 20:
        print("ESTATE", end="")
    else:
        print("AUTUNNO", end="")
elif Mese == 12:
    giorno = int(input())
    if giorno >= 1 and giorno <= 20:
        print("AUTUNNO", end="")
    else:
        print("INVERNO", end="")
