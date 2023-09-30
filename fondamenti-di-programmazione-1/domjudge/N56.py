def main():
    global pavimento, penna, tartaruga
    # pavimento = [[0] * 20] * 20 # non va
    pavimento = [
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    ]
    penna = True # La penna inizialmente è abbassata
    tartaruga = [0, 0] # Posizione corrente della tartaruga [righa, colonna]
    comandi = []
    prendiComandi(comandi)
    for comando in comandi: # Esegui comandi
        match comando:
            case 1: penna = False # Alza la penna
            case 2: penna = True # Abbassa la penna
            case 3: moveRight() # Muoviti a est
            case 4: moveLeft() # Muoviti a ovest
            case 5: moveDown() # Muoviti a sud
            case 6: moveUp() # Muoviti a nord
            case 7: visualizzaPavimento(pavimento, len(pavimento))

def moveRight(): 
    passi = int(input("passi?"))
    print()
    for i in range(tartaruga[1] + 1, tartaruga[1] + passi + 1):
        if tartaruga[1] + 1 < len(pavimento):
            tartaruga[1] += 1 # aggiorna la posizione della tartaruga
            if penna:
                pavimento[tartaruga[0]][i] = 1 # scrivi sul pavimento

def moveLeft(): 
    passi = int(input("passi?"))
    print()
    for i in range(tartaruga[1] - 1, tartaruga[1] - passi -1, -1):
        if tartaruga[1] - 1 >= 0:
            tartaruga[1] -= 1
            if penna:
                pavimento[tartaruga[0]][i] = 1

def moveUp(): 
    passi = int(input("passi?"))
    print()
    for i in range(tartaruga[0] - 1, tartaruga[0] - passi -1, -1):
        if tartaruga[0] - 1 >= 0:
            tartaruga[0] -= 1
            if penna:
                pavimento[i][tartaruga[1]] = 1

def moveDown(): 
    passi = int(input("passi?"))
    print()
    for i in range(tartaruga[0] + 1, tartaruga[0] + passi + 1):
        if tartaruga[0] + 1 < len(pavimento):
            tartaruga[0] += 1
            if penna:
                pavimento[i][tartaruga[1]] = 1 

def visualizzaPavimento(pavimento, dim):
    for i in range(dim):
        for j in range(dim):
            if pavimento[i][j] == 1:
                print("*", end="")
            else:
                print(" ", end="")
        print()

def prendiComandi(comandi):
    n = int(input())
    while n != 9 and len(comandi) <= 100: # 9 è il tappo, 100 sono max comandi
        comandi.append(n)
        n = int(input())

main()
