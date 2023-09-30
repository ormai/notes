# Trovare i duplicati in una lista

seq = []
n = int(input())
while n != -1:
    seq.append(n)
    n = int(input())

duplicate = False

for i in range(len(seq)):
    for j in range(i + 1, len(seq)): # Escludi tutti gli elementi prima di i
        if seq[i] == seq[j]:
            duplicate = True

if duplicate:
    print("There is a duplicate")
else:
    print("There are no duplicates")
