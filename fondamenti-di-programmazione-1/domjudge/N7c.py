# Simulazione di un seggio elettorale.
# Ci sono tre candidati: 1, 2, 3.
# Si deve legggere una sequenza i cui possibili valori sono 4: 1, 2, 3, 0, dove
# 0 è il valore sentinella, che il presidente del seggio inserisce a fine giornata.
# A seconda del numero si deve incrementare il contatore dei voti di ciascun
# candidato.
# Infine, si deve stampare il numero di voti ricevuti da ciascun candidato,
# la percentuale arrotondata a 1 cifra decimale di ciascun candidato su totale
# dei voti e infine, stabilire se almeno uno dei tre candidati ha una percentuale
# maggiore del 50% e quindi è stato eletto, oppure se è necessario un ballottagio.

Voto = int(input())

candidato1 = 0
candidato2 = 0
candidato3 = 0

while Voto != 0: # Conta dei voti per ciascun candidato.
  if Voto == 1:
    candidato1 += 1
  elif Voto == 2:
    candidato2 += 1
  elif Voto == 3:
    candidato3 += 1
  
  Voto = int(input())

totale = candidato1 + candidato2 + candidato3

percentualeCandidato1 = 0
percentualeCandidato2 = 0
percentualeCandidato3 = 0

if totale != 0: # Stampa dei risultati per ciascun candidato
  percentualeCandidato1 = round((candidato1 / totale * 100), 1)
  percentualeCandidato2 = round((candidato2 / totale * 100), 1)
  percentualeCandidato3 = round((candidato3 / totale * 100), 1)

  print("1", candidato1, percentualeCandidato1)
  print("2", candidato2, percentualeCandidato2)
  print("3", candidato3, percentualeCandidato3)

# Individuazione del vincitore
vincitore = 0
votiMax = 0
candidati = [candidato1, candidato2, candidato3]
cont = 0

while cont < 3:
  if candidati[cont] > votiMax:
    vincitore = cont + 1
    votiMax = candidati[cont]
  cont += 1

if percentualeCandidato1 <= 50 and percentualeCandidato2 <= 50 and percentualeCandidato3 <= 50:
  print("BALLOTTAGGIO", end="")
else:
  print("VINCE", vincitore, end="")
