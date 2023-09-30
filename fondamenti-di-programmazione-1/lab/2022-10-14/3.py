# Un chilometro è 1/10000 di 90 gradi (1km = 0.009 gradi).
# Ogni grado sono 60 minuti d'arco.
# Un miglio nautico è un minuto d'arco.

chilometri = float(input("Inserisci il valore da convertire: "))
print("Il valore convertito è:", chilometri * ((1/10000) * 90 * 60))
