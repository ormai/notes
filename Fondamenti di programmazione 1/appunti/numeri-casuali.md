# Numeri casuali

In verità si tratta di numeri pseudocasuali.

```python
import random

random.randint(1, 6) # genera un numero tra 1 e 6 (estremi inclusi)
```

`randint` genera dei numeri a partire da un 'seme'. Questo può essere arbitrariamente impostato dal programmatore per manipolare la generazione pseudocasuale.

```python
random.seed(0)
# da ora in poi randint() restiuirà sempre gli stessi valori ogni votla che viene chiamato
```