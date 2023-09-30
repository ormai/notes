---
aliases: 
  - lista
  - liste
---

# Liste

In Python una **lista** è una un tipo di dato, o anche una struttura di dati, che permette di realizzare raccolte di più valori.

```python
values = [1, 2, 3, 4, 5]
```

Una lista è una **sequenza** di elementi. Ad ognuno di essi è associata una posizione, o *indice* (index). Lo stesso vale per le stringhe, solo che le stringhe possono contenere solo caratteri e sono **immutabili**. Mentre le liste possono contenere qualsiasi [[data-types|tipo di dato]] e sono mutabili.

```python
>>> print(values[3])
4
>>> values[3] = 8
>>> print(values[3])
8
>>> print(values)
[1, 2, 3, 8, 5]
```

Il numero degli elementi di una lista si ricava attraverso la funzione `len()`.

```python
>>> len(values)
5
```

## Index out of range

Tentare di accedere ad un elemento di una lista che non esiste causa un eccezione e il programma si interrompe.

```python
>>> values[10] = 10 # run-time exeption
```

Per evitare questo problema è sufficiente controllare in anticipo che l'indice che si ha intenzione di utilizzare rientri nella lunghezza della lista.

```python
if 0 <= i and i < len(values):
  values[i] = number
```

### Riferimenti e alias

La [[variabili|variabile]] `values` non *contiene* alcun valore, la lista è salvata da qualche parte in memoria e la variabile contiene nient'altro che la sua posizione in memoria. Creando una copia di `values` non si fa altro che creare un riferimento (alias) alla medesima lista.

```python
>>> values = [1, 2, 3, 4, 5]
>>> numeri = values
>>> print(numeri)
[1, 2, 3, 4, 5]
>>> numeri == values
True
>>> numeri is values # controllo dell'identità strutturale
True
```

### Indici negativi

Python consente l'uso di indici negativi per accedere agli elementi di una lista in ordine inverso. Quindi `[-1]` è l'ultimo elemento della lista, `[-2]` il penultimo. Gli indice negativi vanno da `-1` a `-len(list)`

### Liste e stringhe

Liste e [[stringhe]] sono contenitori e in quanto tali godono di simili proprietà e funzioni.

- `in` verifica che un elemento si trovi in una lista. Ugualmente verifica se un carattere si trova in una stringa.
- `min` e `max` individuano l'elemento minimo e quello massimo tra gli elementi di un contenitore. Non è molto utile usarli con le stringhe.
- il ciclo [[iterazione#for|for]] si può utilizzare per scansionare qualsiasi contenitore.
- la funzione `sum` è utile per sommare tutti gli elementi di una lista, non funziona per le stringhe.

## Operazioni sulle liste

```python
lista = [a, b, c, ...]

# Aggiungere un elemento alla fine di una lista
lista.append(elemento) # 'elemento' viene aggiunto a 'lista' come suo ultimo elemento

# Aggiungere un elemento in una posizione specifica di una lista
lista.insert(indice, elemento) # 'elemento' viene aggiunto a 'lista' e avrà come indice l'argomento 'indice'. Se 'indice' eccede la lunghezza della lista, 'elemento' verrà aggiunto alla fine.

# Controllare se un certo elemento si trova in una lista
elemento in lista # True se 'elemento' appartiene a 'lista', altrimenti False

# Ricavare l'indice di un elemento in una lista 
lista.index(elemento, indice) # Restituisce l'indice della prima occorenza di 'elemento' in 'lista'. L'argomento 'indice' è opzionale e specifica la posizione da cui iniziare la ricerca. Se 'elemento' non appartiene a 'lista' si verifica un'eccezione, quindi è meglio controllare prima con l'operatore in.

# Estrarre un elemento da una lista
lista.pop(indice) # Restituisce l'elemento in posizione 'indice' e contemporanemente lo rimuove da 'lista'. Se l'argomento non è esplicitato eseguirà l'operazione sull'ultimo elemento della lista.

# Rimuovere un elemento da una lista
lista.remove(element) # Rivuole 'element' da 'lista', dove 'element' questa volta è un valore contenuto nella lista. Se 'element' non appartiene a 'lista' si verifica un eccezzione. È meglio controllare prima.

# Concatenazione e replicazione
[2, 4, 6, 8] + [1, 3, 5, 7, 9] # restituisce la lista [2, 4, 6, 8, 1, 3, 5, 7, 9]
valori = [0] * 10 # equivale a [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
quarters = [1, 2, 3] * 4 # equivale a [1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3]

# Somma, massimo e minimo
sum([2, 13, 96, 1]) # restituisce 112
max([2, 13, 96, 1]) # restituisce 96
min([2, 13, 96, 1]) # restituisce 1

# Ordinamento
lista.sort() # Restituisce 'lista' con gli stessi elementi di prima ma ordinati in senso crescente. Nel caso in cui gli elementi della lista siano stringhe si tiene conto dell'ordinamento lessicografico.

# Creare la copia di una lista
list(lista) # La funzione list() restituirà una copia di 'lista', non un suo riferimento. Quello che fa list() è creare una lista a partire da una sequenza di elementi, pertanto si può anche trasformare una stringa in una lista con questa funzione:
list("patata") # restituisce ['p', 'a', 't', 'a', 't', 'a']
```

## Slice

`lista[a : b : c]` dove `a` è l'indice incluso del primo elemento della porzione, e `b` è l'indice del primo elemento consecutivo alla porzione, quindi escluso. Questo particolare modo di indicare la porzione è utile perché `b - a` restituisce l'esatto numero degli elementi della porzione. `c` invece è il passo (step).

```python
>>> mesi = ["gennaio", "febbraio", "marzo", "aprile", "maggio", "giugno", "luglio", "agosto", "settembre", "ottobre", "novembre", "dicembre"]
>>> mesi[5 : 8]
['giugno', 'luglio', 'agosto']
>>> mesi[2 : 6 : 2]
['marzo', 'maggio']
>>> mesi[::-1]
['dicembre', 'novembre', 'ottobre', 'settembre', 'agosto', 'luglio', 'giugno', 'maggio', 'aprile', 'marzo', 'febbraio', 'gennaio']
>>> mesi[::-3]
['dicembre', 'settembre', 'giugno', 'marzo']
```

Gli indici sono facoltativi:

```python
lista[ : b] # Tutta la lista fino a 'b' (escluso)
lista[a : ] # La lista da 'a' in poi (incluso)
lista[ : ] # Si ottiene tutta la lista. Questo è un altro modo per fane una copia.
```

Questo sistema può anche essere usato per modificare una porzione della lista, con un numero variabile di elementi che conseguentemente modificherà la lunghezza della lista.

