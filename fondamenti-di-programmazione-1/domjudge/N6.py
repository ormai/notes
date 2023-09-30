# Un anno è secolare se è divisibile per 100: ad esempio, sono stati anni
# secolari il 1700 e 2000. 

# Un anno è bisestile se NON è secolare ed è divisibile per 4 oppure se è
# secolare ed è divisibile per 400. 

# Ad esempio, il 1896 e il 1996 sono stati entrambi bisestili (non secolari
# divisibili per 4); il 1700, il 1800 e il 1900 non sono stati bisestili 
# (secolari non divisibili per 400); il 1600 e il 2000 sono stati bisestili 
# (secolari divisibili per 400).

# Scrivere un programma che, letto da input un intero positivo che rappresenta
# un anno, stampi la stringa “BISESTILE” se l’anno introdotto è bisestile e la
# stringa “NON BISESTILE” altrimenti.

Anno = int(input())

if (not(Anno % 100 == 0) and (Anno % 4 == 0)) or \
        (Anno % 100 == 0 and Anno % 400 == 0):
    print("BISESTILE", end="")
else:
    print("NON BISESTILE", end="")
