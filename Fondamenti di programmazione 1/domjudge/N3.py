# Scrivere un programma che, letto da input un intero N verifichi se N è un 
# numero pari o meno. Più in dettaglio, il programma deve eseguire le seguenti
# operazioni:
# - Leggere N da input
# - Se N è pari stampare la stringa “PARI”
# - Altrimenti, stampare la stringa “DISPARI”

# Si ricorda che un numero è pari se il resto della divisione per 2 è 0; in 
# python, il resto viene calcolato dall’operatore % (modulo). Il controllo da
# eseguire sarebbe pertanto if(N%2==0)

N = int(input())

if N % 2 == 0:
    print("PARI", end="")
else:
    print("DISPARI", end="")
