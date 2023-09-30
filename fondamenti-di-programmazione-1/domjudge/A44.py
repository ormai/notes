def main():
    numero = convert(input())
    if fortunato(numero):
        print("FORTUNATO", end="")
    else:
        print("SFORTUNATO", end="")


def fortunato(n):
    primaParte = n
    secondaParte = []
    for _ in range(len(n) // 2):
        secondaParte.insert(0, primaParte.pop())

    if sum(primaParte) == sum(secondaParte):
        return True
    return False

def convert(s):
    result = []
    for i in s:
        result.append(int(i))
    return result

main()
