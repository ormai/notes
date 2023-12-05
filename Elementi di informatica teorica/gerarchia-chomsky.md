# Gerarchia di Chomsky

Le grammatiche si classificano a seconda delle regole di produzione usate.[^1]

> [!tip] Grammatiche di tipo **tipo 3**, **lineare destre** (e sinistre) o regolari
> $$A\to bC$$
> $$A\to b$$
> dove $A$ e $C$ sono simboli non terminali e $b$ è un simbolo terminale.
> 
> Ci può essere un solo carattere non terminale a sinistra.
> A destra ci può essere un solo carattere terminale, opzionalmente seguito da uno non terminale.
> <br>
> Questo tipo di linguaggio è riconosciuto da un automa a stati finiti, e può essere definito come espressione regolare.
> Esempio: $L_3=\{a^n:n\geq0\}$

> [!tip] Grammatiche di **tipo 2**, **non contestuali**
> $$A\to w$$
> dove $A$ è un simbolo non terminale e $w$ può essere uno o più simboli terminali o non terminali.
> <br>
> Questo tipo di linguaggio è riconosciuto da un automa a pila non deterministico
> Esempio: $L_2=\{a^nb^n:n\geq0\}$

> [!tip] Grammatiche di **tipo 1**, **sensibili al contesto**
> $$wAv\to wzv$$
> dove $w$, $v$ e $z$ sono stringhe di simboli terminali e/o non terminali. $w$ e $v$ possono essere vuote, ma $z$ non può essere vuota.
> <br>
> Questo tipo di grammatica prevede che nelle regole di produzione, a sinistra, ci possa essere una stringa di simboli anche terminale, oltre che non terminali.
> È consentito $S\to\varepsilon$ solo se $S$ non compare a destra in nessuna regola di produzione.
> Esempio: $L_1=\{a^nb^nc^n:n\geq0\}$

> [!tip] Grammatiche di **tipo 0**, **illimitate**
> Tutte le grammatiche sono di tipo 0.

[^1]: https://en.wikipedia.org/wiki/Chomsky_hierarchy#The_hierarchy