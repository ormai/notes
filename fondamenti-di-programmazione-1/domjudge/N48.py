seq = []
n = int(input())
while n >= 0:
    seq.append(n)
    n = int(input())

soloCrescente = True

sottosequenze = []
sottosequenzaCorrente = []

for i in range(len(seq)):
    if i == len(seq) - 1:
        sottosequenzaCorrente.append(seq[i])
        sottosequenze.append(sottosequenzaCorrente)
    else:
        if i + 1 < len(seq):
            if seq[i] <= seq[i + 1]:
                sottosequenzaCorrente.append(seq[i])
            else:
                sottosequenzaCorrente.append(seq[i])
                sottosequenze.append(sottosequenzaCorrente)
                sottosequenzaCorrente = []
                soloCrescente = False

if len(seq) == 0:
    print("Empty", end="")
else:
    piùLunga = []
    for i in sottosequenze:
        if len(i) > len(piùLunga):
            piùLunga = i

    unita = 0
    for i in piùLunga:
        unita = unita * 10 + i

    print(unita)
    print(len(piùLunga), end="")
