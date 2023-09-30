# Versione con le liste

# valori = []
# picchi = []
# giorni = []
#
# n = int(input())
# while n >= 0:
#   valori.append(n)
#   n = int(input())
#
# giorno = 0
# for i in range(len(valori)):
#   giorno += 1
#   if i + 1 < len(valori) and i - 1 >= 0:
#     if valori[i - 1] <= valori[i] and valori[i] >= valori[i + 1]:
#       picchi.append(valori[i])
#       giorni.append(giorno)
#
# for i in range(len(picchi)):
#   print("%-4d  %2d" % (picchi[i], giorni[i]))
#
# print("Numero dei picchi massimi rilevati:", len(picchi))
# print("Numero totale dei dati:", len(valori))
# print("Valore picco più basso:", min(picchi))

# Versione senza le liste

terzultimo = 0
penultimo = 0
n = int(input())
giorno = 0
numMassimiRelativi = 0
minore = n

while n >= 0:
  giorno += 1

  if giorno > 2:
    if terzultimo <= penultimo and penultimo >= n:
      print("%-4d  %2d" % (penultimo, giorno))
      numMassimiRelativi += 1
      if penultimo < minore:
        minore = penultimo

  terzultimo = penultimo
  penultimo = n
  n = int(input())

print("Numero di picchi massimi rilevati:", numMassimiRelativi)
print("Numero totale dei dati:", giorno)
print("Valore più basso:", minore)
