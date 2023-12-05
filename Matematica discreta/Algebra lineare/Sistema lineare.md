---
aliases:
    - sistemi lineari
    - sistema di equazioni
    - Gauss-Jordan
---

# Sistema lineare

[[Insiemi|Insieme]] di due o più [[equazione]] che ammettono le stesse soluzioni.[^1]

Un sistema è rappresentabile come la [[matrice]] dei suoi coefficienti. La *matrice aumentata* ha una colonna in più con i termini noti. La soluzione si può rappresentare come un [[vettore]][^soluzione].

[^soluzione]: $$\left[ \begin{array}{c} x_1 \\ x_2 \\ x_3 \\ x_4 \\ x_5 \end{array} \right] = \left[ \begin{array}{c} 2+t-4r \\ t \\ 2+r \\ 3+r \\ r \end{array} \right]$$

    Questa notazione conviene perché:
    
    1. il coefficiente della variabile dominante è $1$ ($x_1, x_2, \ldots$)
    2. la variabile dominante in ogni equazione non compare nelle altre equazioni
    3. le variabile dominanti compaiono in ordine naturale
    Queste proprietà rispettano i passi dell'algoritmo di [[#Eliminazione di Gauss-Jordan|Gauss-Jordan]]

## Eliminazione di Gauss-Jordan

[[algorithm|Algoritmo]] di Gauss-Jordan su un sistema lineare o su una matrice aumentata[^eliminatio]:
- si procede equazione per equazione, da sopra a sotto
- si supponga di essere arrivati alla riga $i$esima dove la variabile dominante è una certa $x_j$
    1. si divide la riga per uno [[reali|scalare]] cosicché il coefficiente di $x_j$ sia $1$
    2. si elimina $x_j$ da **tutte** le altre righe sommandovi un multiplo adatto della riga $i$
    3. si passa alla riga successiva
- se emerge un'equazione del tipo $zero=nonzero$ [[#Numero di soluzioni|il sistema è inconsistente e non ha soluzioni]]
- se si completa il processo per tutte le righe senza trovare inconsistenze si riordinano le equazioni in _ordine naturale_ facendo degli scambi
- una volta che ogni equazione è risolta per la rispettiva variabile dominante i valori delle variabili non dominanti (libere) possono essere scelte arbitrariamente, determinando così il valore delle prime

Applicare Gauss-Jordan ad una matrice aumentata ha come risultato una _matrice a gradini (fortemente) ridotta_^[reduced row-echelon form, $rref()$].

Una matrice si dice a gradini fortemente ridotta se rispetta queste proprietà
1. se una riga ha elementi diversi da zero, il primo è un $1$ iniziale (_pivot_)
2. se una colonna ha un $1$ iniziale gli altri elementi nella colonna sono $0$
3. se una riga ha un $1$ iniziale ogni colonna sopra ha un $1$ sulla sinistra
4. se ci sono righe con soli $0$, queste sono in basso

> [!note]- Sistema lineare sotto forma di matrice
> Si consideri il sistema $$\left\{\begin{array}{rcl} 3x_1 + x_2=7 \\ x_1 + 2x_2=4 \end{array}\right.$$ la cu matrice aumentata è $$\left[ \begin{array}{cc|r} 3 & 1 & 7 \\ 1 & 2 & 4 \end{array} \right]$$
> Il sistema si può scrivere in **forma vettoriale**
> $$\left[ \begin{array}{cc|r} 3x_1 & x_2 \\ x_1 & 2x_2 \end{array} \right] = \left[ \begin{array}{c} 7 \\ 4 \end{array} \right] \quad o \quad \left[ \begin{array}{c} 3x_1 \\ x_1 \end{array} \right] + \left[ \begin{array}{c} x_2 \\ 2x_2 \end{array} \right]= \left[ \begin{array}{c} 7 \\ 4 \end{array} \right] \quad o \quad x_1 \left[ \begin{array}{c} 3 \\ 1 \end{array} \right] + x_2 \left[ \begin{array}{cc|r} 1 \\ 2 \end{array} \right] = \left[ \begin{array}{cc|r} 7 \\ 4 \end{array} \right]$$
> 
> Risolvere il sistema vuole dire scrivere il vettore $\left[ \begin{array}{c} 7 \\ 4 \end{array} \right]$ come [[Ccombinazione lineare]] dei vettori $\left[ \begin{array}{c} 3 \\ 1 \end{array} \right]$ e $\left[ \begin{array}{cc|r} 1 \\ 2 \end{array} \right]$.
> Scrivendo il sistema nella sua **forma di matrici** $$\underbrace{\left[ \begin{array}{cc} 3 & 1 \\ 1 & 2 \end{array} \right]}_A \underbrace{\left[ \begin{array}{c} x_1 \\ x_2 \end{array} \right]}_{\vec x}=\underbrace{\left[ \begin{array}{c} 7 \\ 4 \end{array} \right]}_{\vec b}$$
> si ha che il sistema è $A\vec x = \vec b$
> Quindi la matrice aumentata del sistema lineare $\left[ \begin{array}{c|r} A & \vec b \end{array}  \right]$ si può scrivere come $$\large A\vec x = \vec b$$

## Numero di soluzioni

- un sistema è **consistente** se ha *almeno* una soluzione e può avere
    - *esattamente* una soluzione (tutte le variabili *dominano* e non ci sono variabili libere)
    - infinite soluzioni (c'è almeno una variabile libera)
- un sistema è **inconsistente** sse la sua matrice aumentata fortemente ridotta contiene una riga del tipo $\left[ \begin{array}{cccc|r}  0 & 0 & \ldots & 0 & 1\end{array} \right]$ che rappresenta l'equazione $0=1$

### Numero di equazioni & numero di incognite

Teorema:

1. Se un sistema lineare ha esattamente una soluzione, allora ci sono *almeno* tante equazioni quante variabili ($m\leq n$).^[cfr. [[Rango]]]

Ne deriva che

2. Un sistema con meno equazioni che incognite ($n < m$) non ha soluzioni, o ne ha infinite.

> [!example] Si consideri un sistema con due equazioni a tre incognite. Ogni equazione definisce un [[piano]]^[similmente: un sistema con due equazioni a due incognite avrà come soluzione il punto di intersezione di due rette (se ha soluzione, altrimenti le rette non si incontrano)].
> Nello spazio due piani posso essere paralleli (il sistema non ha soluzioni) oppure si intersecano lungo una [[retta]] (infinite soluzioni, come i punti della retta). Non è possibile che due piani si intersechino in un punto, quindi non è possibile che il sistema abbia una sola soluzione.
> ![[intersecting-parallel-planes.png|center]]

3. Un sistema con $n$ in $n$ variabili ha un'unica soluzione sse il [[Rango]] della sua matrice dei coefficienti $A$ è $n$.^[La matrice avrà $1$ lungo la diagonale principale e il resto sara tutto $0$]

[^1]: https://it.wikipedia.org/wiki/Sistema_di_equazioni

[^eliminatio]: Chiamato da Gauss *emliminatio vulgaris*