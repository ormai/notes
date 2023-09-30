# Scrivere un programma che individui il giocatore vincente in una mano del
# gioco della briscola. Ovvero, si richiederanno come input (nell’ordine):
# 1. il seme della briscola (un numero da 1 a 4),
# 2. il seme della carta tirata dal primo giocatore (un numero da 1 a 4),
# 3. la carta giocata dal primo giocatore (un numero da 1 a 10, 1 rappresenta
# l’asso, 2 rappresenta 2 etc... fino a 8 che rappresenta il fante, 9 il cavallo
# e 10 il re),
# 4. il seme della carta tirata dal secondo giocatore (un numero da 1 a 4),
# 5. la carta giocata dal secondo giocatore (un numero da 1 a 10, 1 rappresenta
# l’asso, 2 rappresenta 2 etc... fino a 8 che rappresenta il fante, 9 il cavallo
# e 10 il re).

# Il programma deve quindi stampare “VINCE GIOCATORE 1” oppure “VINCE GIOCATORE
# 2” senza andare a capo per indicare se ha vinto il primo giocatore oppure il
# secondo.

# Per semplicità si può assumere che l’input fornito sia valido, ovvero non
# vengano mai inseriti semi non compresi tra 1 e 4 e carte non comprese tra 1 e
# 10.

# Si ricorda che la Briscola si gioca con un mazzo di 40 carte diviso in 4 semi,
# ciascuno di 10 carte e che le regole della Briscola prevedono i seguenti
# criteri per vincere una mano del gioco. Il primo giocatore a giocare una carta
# (detto giocatore di mano) determina con la stessa il seme di mano. Il secondo
# giocatore non ha alcun obbligo di giocare un particolare seme. La mano è
# aggiudicata al secondo giocatore se questi gioca una carta del seme di mano
# con valore di presa maggiore, o una carta del seme di briscola anche se con
# valore di presa inferiore. Si riportano di seguito i valori di presa delle
# singole carte:
# - ASSO Valore 11
# - TRE Valore 10.5
# - RE Valore 10
# - CAVALLO Valore 9
# - FANTE Valore 8
# - 7 Valore 7
# - 6 Valore 6
# - 5 Valore 5
# - 4 Valore 4
# - 2 Valore 2

SemeBriscola = int(input())
Seme1 = int(input())
Carta1 = int(input())
Seme2 = int(input())
Carta2 = int(input())

# In base alla carta si assegna il suo valore nel gioco
if Carta1 == 1:
    valore1 = 11
elif Carta1 == 3:
    valore1 = 10.5
else:
    valore1 = Carta1

if Carta2 == 1:
    valore2 = 11
elif Carta2 == 3:
    valore2 = 10.5
else:
    valore2 = Carta2

# Si confrontano le mani
if Seme1 == Seme2 and valore1 > valore2:
    print("VINCE GIOCATORE 1", end="")
elif Seme1 == Seme2 and valore1 < valore2:
    print("VINCE GIOCATORE 2", end="")
elif Seme1 != Seme2 and Seme2 == SemeBriscola:
    print("VINCE GIOCATORE 2", end="")
else:
    print("VINCE GIOCATORE 1", end="")
