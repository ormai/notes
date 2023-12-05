# Scrivere un programma che, letti da input due numeri interi A e B, con B
# diverso da 0, calcoli e stampi il risultato delle operazioni A+B, A-B, A*B,
# A//B, e A%B, secondo il formato descritto nel seguente esempio.

# Esempio. Se A fosse 5, e B fosse 3, il programma dovrebbe stampare:
# Somma: 8
# Differenza: 2
# Moltiplicazione: 15
# Quoziente: 1
# Resto: 2

A = int(input())
B = int(input())

print("Somma:", A + B)
print("Differenza:", A - B)
print("Moltiplicazione:", A * B)
print("Quoziente:", A // B)
print("Resto:", A % B, end="")
