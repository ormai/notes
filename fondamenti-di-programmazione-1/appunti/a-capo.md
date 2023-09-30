# Andare a capo

Quando un'espressione aritmetica non entra in un'unica riga si può andare a capo a patto si metta l'intera espressione tra `()`, oppure terminando la riga con `\`.

```python
var = ((-b + sqrt(b ** 2 - 4 * a * c))
      / (2 * a))
```

oppure

```python
var = (-b + sqrt(b ** 2 - 4 * a * c)) \
      / (2 * a)
```