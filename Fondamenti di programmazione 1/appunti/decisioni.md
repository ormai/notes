# Prendere decisioni

Condizione e a una via:

```python
if condizione:
  blocco di istruzioni 1
```

Condizione a due vie:

```python
if condizione:
  blocco di istruzioni 1
else: 
  blocco di istruzioni 2
```

Condizione a più vie:

```python
if condizione 1:
  blocco di istruzioni 1
elif condizione 2: 
  blocco di istruzioni 2
elif condizione n: 
  blocco di istruzioni n
else:
  blocco di istruzioni di default
```


### If innestati

Dentro un `if` si può mettere un altro `if`.

```python
if condizione:
  if condizione:
    blocco di istruzioni 1
  else: 
    blocco di istruzioni 2
else: 
  blocco di istruzioni 1
```

Le condizioni non sono altro che espressioni [[data-types|booleane]] che possono essere composte attraverso `or`, `and`, `not`.

## Espressioni condizionali

Un modo più compatto per prendere decisioni.

``valore 1 if condizione else valore2``

Se la *condizione* è vera l'espressione produrrà *valore1*, altrimenti *valore2*.

```python
print("This will be printed") if 3 > 0 else print("This is ignored")

print("This is ignored") if 3 < 0 else print("This will be printed")
```

## Corto circuito

Le espressioni composte sono valutate da sinistra verso destra. In alcuni casi il valore dell'espressione composta è determinato ancora prima che tutte le [[proposition|proposizioni]] al suo interno siano valutate. eg per l'espressione `A or B and C` se `A` è vera la valutazione di `B` e `C` non sarà effettuata.