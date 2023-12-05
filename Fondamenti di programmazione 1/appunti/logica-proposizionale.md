---
aliases:
  - "logica proposizionale"
  - "calcolo proposizionale"
---

# Calcolo proposizionale

![[proposition]]

Le proposizioni possono essere semplici o composte. Il valore di verità è espresso in vero o falso, `1` o `0`, `True` o `False`. Quelle composte usano [[connectives|connettivi logici]] e il valore di verità dipende dalle proposizioni semplici da cui è composta e dal connettivo. I connettivi possono essere mono-argomentali, ovvero si applica a una sola proposizione, o bi-argomentali o n-argomentali.

Il connettivo `NOT` nega la proposizione ed è **unario**. 

Connettivi bi-argomentali sono:
- `AND` congiunzione, per essere vera devono essere vere tutte e due le proposizioni;
- `OR` disgiunzione inclusiva, devono essere vere tutte e due o almeno una delle due;
- `XOR` disgiunzione esclusiva, ne deve essere vera **solo e soltanto** una delle due.

I connettivi si possono unire in proposizioni composte. Qui gli operatori hanno la seguente precedenza:

1. `()`
2. `NOT`
3. `AND`
4. `OR`
5. `< > ≤≥ = ≠`

La tautologia, o teorema è una proposizione composta che è vera per qualsiasi valore attribuito alle preposizioni che lo compongono, un esempio è la [[leggi-de-morgan|Legge di de Morgan]]: `NOT(A AND B) = NOT A OR NOT B`.
**Contraddizione**: proposizione falsa per qualsiasi valore delle proposizioni che lo compongono.

## Forme disgiuntive normali
Utilizzano solo `NOT` `AND` `OR` per descrivere risultati dipendenti da valori di verità di proposizioni semplici. Si considerano le combinazioni per le quali si ottiene valore di verità e quando si ha **verità F** si antepone `NOT`. Si creano così proposizioni che vengono connesse da `AND` (congiunzioni). A loro volta queste congiunzioni vengono connesse con `OR` formando una **forma disgiuntiva normale**.