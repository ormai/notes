sequenza = []

N = int(input())
for i in range(N):
  sequenza.append(int(input()))

# somma = sum(sequenza)
# massimo = max(sequenza)
# minimo = min(sequenza)

MA = sequenza[0]
somma = 0
for i in sequenza:
  somma += i
  if i > MA:
    MA = i

ME = somma // len(sequenza)

print("media:", ME)
print("max:", MA)
print("Differenze con media:")
for X in sequenza:
  print(ME - X)
print("Differenze con max:")
for X in sequenza:
  print(MA - X)
