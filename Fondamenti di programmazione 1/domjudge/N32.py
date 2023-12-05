# Costruisci la sequenza
seq = []
n = int(input())
while n != 0:
    seq.append(n)
    n = int(input())

# Trova il numero più grande nella sequenza e salva il suo indice
apice = 0
indApx = 0
for i in range(0, len(seq)):
    if seq[i] >= apice:
        apice = seq[i]
        indApx = i

# Condizione: a sinistra dell'apice gli elementi della sequenza devono essere
# consecutivamente strettamente crescenti, mentre a destra dell'apice gli
# elementi della sequenza devono essere consecutivamente strettamente
# decrescenti

condizione = True
for i in range(0, len(seq)):
    if i + 1 < len(seq):
        if ((i < indApx and not(seq[i] < seq[i + 1])) or
                    (i > indApx and not(seq[i] > seq[i + 1]))):
            condizione = False

if len(seq) > 2 and condizione and indApx != len(seq) - 1 and indApx > 0:
    print("SI", end="")
else:
    print("NO", end="")
