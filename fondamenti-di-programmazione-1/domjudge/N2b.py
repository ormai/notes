# Scrivere un programma che letti da input due numeri interi rappresentanti
# rispettivamente la base e l’altezza di un rettangolo, calcoli e stampi l’area
# e il perimetro. Si ricorda che per un rettangolo di base
# B e altezza A l’area si calcola come B*A mentre il perimetro come (B*2)+(A*2).
# Il programma deve stampare seguendo il formato mostrato nel seguente esempio.

# Esempio. Se la base fosse 3 e l’altezza 4, il programma stamperebbe:
# AREA: 12
# PERIMETRO: 14

B = int(input())
H = int(input())

print("AREA:", B * H)
print("PERIMETRO:", (2 * B)+(2 * H), end="")
