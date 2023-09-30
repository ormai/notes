# Stringhe

Una stringa è una serie di caratteri [UNICODE](https://en.wikipedia.org/wiki/Unicode).

Ogni carattere nella stringa ha una posizione che corrisponde a un determinato indice, partendo da zero. 

> A string is an array of characters.

Si può accedere ai caratteri di una stringa attraverso l'operatore di **subscript** (`[]`).

```python
>>> s = 'patata'
>>> print(s[0])
p
>>> print(s[4])
t
```

### Concatenazione

```python
>>> print('ciao'+'mondo')
ciaomondo
```

```python
>>> print(2*'ciao')
ciaociao
```

## len

La funzione `len()` serve a misurare la lunghezza di una stringa:

```python
>>> print(len('rombo')
5
```

Ricavare l'ultimo carattere di una stringa:

```python
>>> s = "Questa è una stringa"
>>> print("L'ultimo carattere di", s, "è", s[len(s)-1])
L'ultimo carattere di Questa è una stringa è a
```

## Sottostringhe

Si possono estrarre sottostringhe utilizzando l'operatore di subscript e i `:`

```python
sentence = "I gatti neri sono belli."

print(sentence[2:11]) # da sentence[2] a sentence[10] (l'estremo superiore è escluso)
# gatti ner

print(sentence[2:]) # da sentence[2] finoa alla fine
# gatti neri sono belli.

print(sentence[:11]) # dall'inizio fino a sentence[10]
# I gatti ner

print(sentence[-4:]) # Solo gli ultimi quattro caratteri
# lli.

print(sentence[:-4]) # dalla fine fino a sentence[len(sentence)-4+1]
# I gatti neri sono be

```

## in

L'operatore `in` determina se una sottostringa appartiene a una data stringa.

```python
stringa = "lucertola"
sottostringa = "luce"

if sottostringa in stringa:
  print("La stringa %s contiene la sottostringa %s." % (stringa, sottostringa))
```

L'operatore `not in` determina se una sottostringa non appartiene a una stringa.

```python
nome = "mario-goffredo"

if "-" not in nome:
  print("Il nome %s non contiene trattini." % nome)
```

> [!bug] la stringa vuota `''` appartiene ad ogni stringa
> ```python
> >>> '' in 'aeiou'
> True
> ```

## Sequenze di escape

`\n` return
`\t` tab
`\'` '
`\\` \

## Metodi per le stringhe

In [[python-introduzione|Python]] le stringhe in quanto [[object|oggetti]] godono di alcuni [[metodi]].

```python
>>> stringa = "Mario"
>>> print(stringa.upper())
MARIO
>>> print(stringa.lower())
mario
>>> print(string.replace("o", "a"))
Maria
```

È comune prendere [[decisioni]] in merito a [[stringhe]]. 



### Sottostringhe

| `stringa.count(sottostringa)`      | Restituisce il numero di ricorrenza di `sottostringa` in `stringa`.                              |
| ---------------------------------- | ------------------------------------------------------------------------------------------------ |
| `stringa.endswith(sottostringa)`   | Restituisce `True` se `stringa` termina con `sottostringa`, altrimenti `False`.                   |
| `stringa.startswith(sottostringa)` | Restituisce `True` se `stringa` comincia con `sottostringa`, altrimenti `False`.                  |
| `stringa.find(sottostringa)`       | Restituisce il valore dell'indice della prima occorrenza di `sottostringa`, `-1` se non ricorre. |

### Contenuto della stringa 

| `stringa.isalnum()`  | Restituisce `True` se la `stringa` non è vuota ed è costituita da sole lettere o cifre, altrimenti `False`.                     |
| -------------------- | ------------------------------------------------------------------------------------------------------------------------------- |
| `stringa.isalpha()`  | Restituisce `True` se la `stringa` non è vuota ed è costituita da sole lettere, altrimenti `False`.                             |
| `stringa.isdigit()`  | Restituisce `True` se la `stringa` non è vuota ed è costituita da sole cifre, altrimenti `False`.                               |
| `stringa.isspace()`  | Restituisce `True` se la `stringa` non è vuota e contiene solo caratteri di spaziatura (`' '`, `\n`, `\t`), altrimenti `False`. |
| `stringa.islower()`  | Restituisce `True` se la `stringa` contiene almeno una lettera e tutte le lettere sono minuscole, altrimenti `False`.           |
| `stringa.isuppder()` | Restituisce `True` se la `stringa` contiene almeno una lettere e tutte le lettere sono maiuscole, altrimenti `False.`           |
