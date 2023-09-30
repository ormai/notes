# Conversione di tipo

```python
>>> -98.32 + 27
-71.32
```

In questo caso `int` viene convertito in `float` poiché quest'ultimo è un tipo più generale.

```python
# Funzioni di conversione
int()
float()
str()
```

La funzione `int` tronca la parte decimale. La funzione `round` approssima ad una certa cifra decimale.

```python
>>> n = 1/3
>>> print(round(n,2))
>>> 0.33
```