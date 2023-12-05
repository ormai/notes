n = int(input("Dammi un intero: "))

elementi=[]
elementiInvertito=[]

while n != -1:
    elementi.append(n)
    n = int(input("Dammi un intero: "))

for i in range(0, len(elementi)):
    print(elementi[len(elementi)-1-i])

# print(elementi[::-1])
