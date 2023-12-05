seq = []
for i in range(10):
  seq.append(int(input()))

sottosequenze = []
sottosequenzaCorr = []
posizioneDue = []
for i in range(len(seq)):
  if i != len(seq):
    if seq[i] != 2:
      sottosequenzaCorr.append(seq[i])
    else:
      sottosequenze.append(sottosequenzaCorr)
      posizioneDue.append(i)
      sottosequenzaCorr = []
  else:
    sottosequenzaCorr.append(seq[i])
    sottosequenze.append(sottosequenzaCorr)
  
for i in sottosequenze:
  print(i)

for i in posizioneDue:
  print(i)
