# Scrivere un programma che, letto da input un numero intero N che rappresenta 
# il voto conseguito all’esame di Fondamenti, comunica allo studente se l’esame 
# è stato superato o meno. Più in dettaglio, il programma deve effettuare le 
# seguente operazioni:
# - Leggere N da input
# - Se N è minore (<) di 0 oppure maggiore di 30 deve stampare la stringa “VOTO NON VALIDO”
# - Altrimenti, se N è maggiore o uguale a 18 (>=) il programma deve stampare la stringa “ESAME
# SUPERATO”
# - Altrimenti, deve stampare la stringa “BOCCIATO”.

Voto = int(input())

if Voto < 0 or Voto > 30:
    print("VOTO NON VALIDO", end="")
elif Voto >= 18:
    print("ESAME SUPERATO", end="")
else:
    print("BOCCIATO", end="")
