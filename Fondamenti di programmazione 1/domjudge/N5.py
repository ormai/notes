# Scrivere un programma che, letti da input tre interi positivi, A, B e C
# verifichi se questi possono rappresentare le lunghezze dei lati di un
# triangolo, e in caso affermativo, stabilisca di che tipo di triangolo si
# tratta. Più in dettaglio, il programma deve effettuare le seguente
# operazioni:
# - Leggere A, B e C da input
# - Controllare che ognuno dei tre valori sia minore della somma degli altri
#   due
# - Se il controllo precedente restituisce False (falso), il programma deve
# stampare la stringa “NO”
# - Altrimenti,
#     - il programma stabilisce di che tipo di triangolo si tratta e stampa una
#       tra le seguenti stringhe “TRIANGOLO EQUILATERO”, “TRIANGOLO ISOSCELE”
#       o “TRIANGOLO SCALENO”, a seconda del tipo di triangolo.

Lato1 = int(input())
Lato2 = int(input())
Lato3 = int(input())

if not((Lato1 < (Lato2 + Lato3)) and (Lato2 < (Lato1 + Lato3))
       and (Lato3 < (Lato1 + Lato2))):
    print("NO", end="")
elif Lato1 == Lato2 == Lato3:
    print("TRIANGOLO EQUILATERO", end="")
elif ((Lato1 == Lato2) or (Lato2 == Lato3) or (Lato1 == Lato3)):
    print("TRIANGOLO ISOSCELE", end="")
else:
    print("TRIANGOLO SCALENO", end="")
