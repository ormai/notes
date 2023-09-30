seq = []
parola = input()
while parola != 'FINE':
  seq.append(parola)
  parola = input()

if len(seq) % 2 == 0:
  print(seq[len(seq) // 2 - 1] + seq[len(seq) // 2])
else:
  print(seq[len(seq) // 2])
