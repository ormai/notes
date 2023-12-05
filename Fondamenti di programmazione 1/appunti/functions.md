# Funzioni

Una funzione è un blocco di codice riutilizzabile, al quale è assegnato un nome, che svolge un determinato compito. Una funzione può ricevere argomenti tra `()`. Nella maggior parte dei casi una funzione restituisce un valore (`return`). Quando così non è una funzione restituisce `None`.

```python
def quadrato(x):
  '''restituiscce il quadrato di un numero'''
  return x * x
```

Le funzioni sono un modo creare **astrazione**, nascondendo così dettagli complessi. Servono anche ad evitare di **ripetere codice** simile a risolvere la medesima classe di problemi. Un problema complesso può essere scomposto in sotto-problemi, ciascuno risolto da una specifica funzione.

È buona norma non modificare direttamente le variabili passate come parametri.

![[funzione-scatola-nera.excalidraw|center|800]]

## Numero variabile di parametri

```python
def func(*value)
  som = 0
  for i in values:
    som += i
  return som 
```

In questo caso `values` è una [[tuple]] che contiene tutti i parametri passati a `func`, che possono essere un numero variabile.

## Funzioni come scatole nere

Non è affatto necessario che l'utente utilizzatore di una funziona sappia come questa sia implementata. L'utente deve solo conoscere le specifiche di una funzione, ovvero il ruolo degli argomenti e il tipo di valore restituito.

# Struttura di un programma Python con funzioni

```python
def main():
  # acquire data
  x = input()
  y = "a"
  z = "d"
  h = x + a

  # Call functions
  aFunction(x)
  someOtherFunction(y, z)

def aFunction(a):
  # do things

def someOtherFuction(d, c):
  # do different things

# The program begins here
main()
```

Se il corpo di una funzione non entra nella finestra dell'editor, allora probabilmente va scomposta in più funzioni.