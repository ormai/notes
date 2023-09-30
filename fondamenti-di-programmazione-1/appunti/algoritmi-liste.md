# Algoritmi elementari che operano su liste

## Riempire una lista

```python
n = int(input())
lista = []
for i in range(n):
  lista.append(input())
```

## Riempire una matrice

```python
n = int(input()) # Numero di righe
m = int(input()) # Numero di colonne
matrice = []
for i in range(n):
  matrice.append([])
  for j in range(m):
    matrice[i].append(input())
```

## Somma/concatenazione degli elementi di una lista

```python 
lista = [1, 2, 3]
risultato = 0
for e in lista:
  risultato += e
```

```python
lista = ["a", "b", "c"]
risultato = ""
for e in lista:
  risultato += e
```

## Separatori

```python
lista = [1, 2, 3, 4, 5, 6]
risultato = ""
for i in range(len(lista)):
  if i > 0: # Non si mette il separatore prima del primo elemento
    risultato += ", "
  risultato += lista[i]
```

## Massimo e minimo

```python
lista = [3, 9, 24, 2, 5]
massimo = lista[0]
minimo = lista[0]

for i in range(1, len(lista)):
  if lista[i] > massimo:
    massimo = lista[i]
  if lista[i] < minimo:
    minimo = lista[i]
```

```python
lista = ["patata", "cipolla", "scarpa", "sgabello"]
piuLunga = lista[0]
piuCorta = lista[0]

for i in range(1, len(lista)):
  if len(lista[i]) > len(piuLunga):
    piuLunga = lista[i] 
  if len(lista[i]) < len(piucorta):
    piuCorta = lista[i]
```

## Ricerca lineare

```python
lista = [9, 7, 5, 3]
valoreDaCercare = 3

if valoreDaCercare in lista:
  posizione = lista.index(valoreDaCercare)
  print("Trovato in posizione", posizione)
else:
  print("Elemento non trovato")
```

```python
# Trovare il primo elemento che soddisfi una certa proprietà. In questo esempio un elemento maggiore di 50.
lista = [393, 973, 1412, 5, 62, 17]
soglia = 50
posizione = 0
trovato = False

while posizione < len(lista) and not trovato:
  if lista[posizione] > soglia:
    trovato = True
  else:
    pos += 1
```

## Conteggio delle corrispondenze

```python
# Trovare tutti gli elementi maggiori di 50.
lista = [393, 973, 1412, 5, 62, 17]
soglia = 50
risultato = []
contatore = 0

for n in lista:
  if n > soglia:
    risultato.append(n)
    contatore += 1
```

## Eliminazione di corrispondenze

```python
lista = [393, 973, 1412, 5, 62, 17]
soglia = 50

i = 0
while i < len(lista):
  if lista[i] < soglia:
    lista.pop(i)
  else:
    i += 1
```

## Scambio di elementi

```python
lista = [1, 2, 3, 4, 5]

temp = lista[2] # Serve una variabile temporanea
lista[2] = lista[0]
lista[0] = temp

# [3, 2, 1, 4, 5]
```