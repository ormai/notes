# Variabili

Una variabile è una posizione nella memoria del computer in cui si possono archiviare informazioni durante l'esecuzione di un programma.

L'*identificatore di variabile* è un nome dato ad un valore.

Assegnando un valore ad una variabile si effettua un'operazione detta **assegnamento**. Quando ciò si fa per la prima volta si dice **inizializzazione** della variabile. Ogni volta che nel programma la variabile viene usata, si fa un **riferimento**.

```python
>>> a = "brufolo"
# Sottile differenza per interprete shell
>>> a
'brufolo'
>>> print(a)
brufolo
```

Dopo che una variabile è stata inizializzata con un determinato [[data-types|tipo]], dovrebbe sempre memorizzare un valore di quel tipo.

## Nomi di variabili

 Python impone alcune regole nell'assegnare un nome alla propria variabile:
- le variabili possono contenere lettere, cifre e `_`;
- il primo carattere può essere solo una lettera o un `_`;
- alcune parole sono **riservate** (keywords) e non possono essere usate;
- **case sensitive**, `ciao` è diverso da `Ciao`.

### Convenzioni

È molto diffuso l'uso della forma a gobba di cammello (**camel casing**). Convenzionalmente il nome di una variabile deve essere **descrittivo**. 
Normalmente il nome di una variabile comincia con una lettera minuscola, può cominciare con una lettere maiuscola quando descrive dato inserito dall'utente. Il nome di una costante è scritto con parole maiuscole. 

```python
contatoreDiCicli = 0
NumeroDaSommare = int(input("Scrivi un numero da sommare: "))
SPEED_OF_LIGHT = 299792458
```