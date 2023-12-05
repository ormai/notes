---
aliases:
  - vector
  - vectors
  - vettore
---

# Vettori

Segmento orientato in $\Bbb R^n$. Indicato con una lettera minuscola $\vec a$ o con il suo punto iniziale e il suo punto finale $\overrightarrow{AB}$.

Un vettore $\overrightarrow{AB}$ ha:
- [[direzione]] (la [[retta]] passante per $A$ e $B$)
- verso (da $A$ a $B$ e non il contrario)
- [[modulo]] $||\overrightarrow{AB}||$ (la lunghezza del segmento)

Due vettori uguali hanno uguale direzione, verso e modulo. Due vettori [[parallelismo|paralleli]] hanno uguale direzione e le componenti sono multipli.

> [!tip] I vettori sono rappresentabili come [[Matrice|matrici]] con una sola colonna
> $$\vec v = \left[ \begin{array}{cc|r} v_1 \\ v_2 \\ \vdots \\ v_n \end{array} \right]$$
> gli [[reali|scalari]] $v_i$ sono le componenti del vettore.

L'[[Insiemi|insieme]] dei vettori con $n$ componenti è $\Bbb R^n$; $\Bbb R^n$ è uno [[Spazio lineare|spazio vettoriale]].

I vettori sono rappresentabili nel [[Piano cartesiano|piano cartesiano]] come una freccia che inizia nell'origine e finisce nel punto $(x,y)$. Similmente in $\Bbb R^3$.

il **vettore nullo** è il vettore di lunghezza $0$ tale che: $$\vec 0 = \overrightarrow{OO}=\left[ \begin{array}{cc|r} 0 \\ 0 \\ \vdots \\ 0 \end{array} \right]$$

L'**opposto** di un vettore $\vec a$ è il vettore con modulo e direzione uguale a quelli di $\vec a$, ma con il verso opposto: $-\vec a$.

> [!tip] $\vec a + (-\vec a) = \vec 0$ ^1dc604

**Traslare** un vettore nel [[piano]] ne preserva direzione e lunghezza e consiste nel [[somma|sommare]] delle costanti alle componenti $$(a + x, b+y)$$

## Lunghezza

La lunghezza o _norma_ o [[modulo]] di un vettore è data da $$||\ \vec v\ || = \sqrt{v_1^2+v_2^2+\ldots +v_n^2}$$