def main():
    N = input()
    print(tranform(N), numberOfDigit(tranform(N)), end="")

def tranform(n):
    brokenDown = []
    current = ''

    for i in n:
        if current != i:
            current = i
            brokenDown.append([i])
        else:
            brokenDown[len(brokenDown) - 1].append(i) 

    result = 0

    for i in range(len(brokenDown)):
        result = result * 10 + len(brokenDown[i]) 
        result = result * 10 + int(brokenDown[i][0])

    return result

def numberOfDigit(n):
    quoziente = n
    risultato = 0
    while quoziente > 0:
        quoziente //= 10
        risultato += 1

    return risultato

main()
