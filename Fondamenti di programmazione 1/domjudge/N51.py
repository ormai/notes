seq1 = []
n = input()
while n != ".":
    seq1.append(n)
    n = input()

seq2 = []
m = input()
while m != ".":
    seq2.append(m)
    m = input()

for i in seq1:
    for j in seq2:
        if i == j:
            print(i, end="")
            exit(0)

print("DISGIUNTE", end="")
