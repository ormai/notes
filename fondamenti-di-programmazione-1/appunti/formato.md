# Manipolazione del formato

L'operatore `%` quando è usato tra [[stringhe]] è l'**operatore di formato**.

`%d` si riferisce agli `int`, `%f` si riferisce ai `float`, `%s` alle `str`.

```python
PREZZO_PRODOTTO = 15
ProdottiVenduti = int(input("Numero di prodotti venduti: "))
incasso = PREZZO_PRODOTTO * ProdottiVenduti

print("Incasso: %.2f" % incasso)

# Numero di prodotti venduti: 5
# Incasso: 75.00 
```

```python
title1 = "Quantity:"
title2 = "Price:"
print("%-10s %10d" % (title1, 24))
print("%-10s %10.2f" % (title2, 17.29))

# Quantity:          24
# Price:          17.29
```

---

*C. Horstmann, R. D. Necaise - Concetti di informatica e fondamenti di Python - Apogeo Education (9788891635433)* §2.5.3 (p. 60)