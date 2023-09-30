def main():
    lista = [9, 6, 5, 23, 96, 4, 5, 2, 1]
    bubbleSort(lista)
    print(lista)

def bubbleSort(arr):
    n = len(arr)
    swaps = True # Se non ci sono scambi la lista è già ordinata

    while swaps:
        swaps = False
        for i in range(n - 1):
            if arr[i] > arr[i + 1]:
                arr[i], arr[i + 1] = arr[i + 1], arr[i] # swap
                swaps = True
        n -= 1

main()
