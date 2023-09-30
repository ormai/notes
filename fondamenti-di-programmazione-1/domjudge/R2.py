def main():
    N = int(input())
    if N % 2 != 0: 
        print("NO", end="")
        return
    L = []
    for _ in range(N): L.append(int(input()))
    if equalHalves(L):
        print("SI", end="")
    else:
        print("NO", end="")

def equalHalves(lista):
    if len(lista) == 0:
        return True

    if lista[0] == lista[len(lista) // 2]:
        if len(lista) == 2: return True
        lista.pop(lista[len(lista) // 2])
        lista.pop(lista[0])
        return lista
    else:
        return False

main()
