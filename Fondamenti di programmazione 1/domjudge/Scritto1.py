def main():
    N = int(input())
    M = int(input())
    A = int(input())
    griglia = []
    for i in range(N):
        griglia.append([])
        for _ in range(M):
            griglia[i].append(input())


    if (numeroTotaleAlberi(griglia) == A and condizioneDue(griglia)
            and condizioneTre(griglia)):
        print("OK", end="")
    else:
        print("NO", end="")

def condizioneTre(griglia):
    for i in range(len(griglia)):
        for j in range(len(griglia[0])):
            alberi = 0
            if griglia[i][j] != "*" and int(griglia[i][j]) > 0:
                if (i - 1 >= 0 and j - 1 >= 0
                        and griglia[i - 1][j - 1] == "*"):
                    alberi += 1
                if (i - 1 >= 0 and griglia[i - 1][j] == "*"):
                    alberi += 1
                if (i - 1 >= 0 and j + 1 < len(griglia[0])
                        and griglia[i - 1][j + 1] == "*"):
                    alberi += 1
                if (i + 1 < len(griglia) and j + 1 < len(griglia[0])
                        and griglia[i + 1][j + 1] == "*"):
                    alberi += 1
                if i + 1 < len(griglia) and griglia[i + 1][j] == "*":
                    alberi += 1
                if (i + 1 < len(griglia) and j - 1 >= 0
                        and griglia[i + 1][j - 1] == "*"):
                    alberi += 1
                if (j + 1 < len(griglia[0]) and griglia[i][j + 1] == "*"):
                    alberi += 1
                if j - 1 >= 0 and griglia[i][j - 1] == "*":
                    alberi += 1


                if int(griglia[i][j]) != alberi:
                    return False

    return True

def condizioneDue(griglia):
    for i in range(len(griglia)):
        alberi = 0
        case = 0
        for j in range(len(griglia)):
            if griglia[i][j] == "*":
                alberi += 1
            elif griglia[i][j] != "*" and int(griglia[i][j]) > 0:
                case += 1

        if alberi > case:
            return False

    return True

def numeroTotaleAlberi(griglia):
    cont = 0
    for i in range(len(griglia)):
        for j in range(len(griglia[0])):
            if griglia[i][j] == "*":
                cont += 1
    return cont

main()
