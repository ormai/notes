---
aliases:
  - cicli
  - for
  - while
---

# Iterazione

L'iterazione è un modo per ripetere un'azione un certo numero di volte.

Quando l'iterazione è definita, le azioni vengono ripetute un determinato numero di volte, quando invece è indefinita le operazioni vengono ripetute finché una certa condizione è vera.

## while

```python
while condizione:
  blocco di istruzioni
```

Nel blocco di istruzioni è necessario che ce ne siano alcune che aggiornano i dati della condizioni, altrimenti il ciclo non avrebbe fine, sarebbe in teoria infinito.

Talvolta il ciclo `while` può essere controllato da un **contatore**. Ciò è utile quando le istruzioni devono essere ripetute un determinato numero di volte.

```python
contatore = 1

while contatore <= 10:
  print(contatore, end=' ')
  contatore += 1
```

## for

Il ciclo for è ottimo per iterare attraverso gli elementi di un [[list|contenitore]].

```python
for variabile in contenitore:
  blocco di istruzioni
```

Il *blocco di istruzioni* è eseguito per ciascun elemento del *contenitore*. Alla *variabile* di controllo viene assegnati `contenitore[0]`, `contenitore[1]`, `contenitore[2]`, ... Qui si nota una differenza con il [[#while]], poiché in quel caso la [[variabile]] di controllo vengono assegnati dei valori (`0`, `1`, `2`, ...), dopotutto funge da contatore.
Dunque nel ciclo `while` la variabile di controllo è detta **variabile di indice** poiché contiene sempre l'indici di un elemento, mentre nel ciclo `for` la variabile di controllo è detta **variabile elemento** poiché contiene l'elemento, in questo caso del contenitore.

Si può usare il ciclo `for` anche senza l'uso di un contenitore, attraverso la [[functions|funzione]] `range`, che crea una sequenza di numeri reali utilizzabili come contenitore.

```python
for i in range(1, 10):
  print(i)
```

Il secondo valore passato a `range` non fa parte della sequenza.

```python
for i in range(5) # La sequenza comincia da 0 con incrementi unitari, 5 non ne fa parte.

for i in range(1, 5) # La sequenza inizia dal primo argomento.

for i in range(0, 11, 2) # Il terzo argomento è l'incremento.
```

## Cicli annidati

Proprio come per le [[decisioni]] anche i cicli possono essere annidati. Un caso comune di cicli annidati riguarda il riempimento di una tabella.