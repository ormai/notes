---
aliases: "algebra vettoriale"
---

# Algebra vettoriale

Operazioni tra e su [[Vettore|vettori]].

## Somma

La somma avviene per componenti.

$$\vec v + \vec w = \left[ \begin{array}{cc|r} v_1 \\ v_2 \\ \vdots \\ v_n \end{array}  \right] + \left[ \begin{array}{cc|r} w_1 \\ w_2 \\ \vdots \\ w_n \end{array} \right] = \left[ \begin{array}{cc|r} v_1 + w_1 \\ w_2 + w_2 \\ \vdots \\ v_n + w_n \end{array} \right]$$

Differenza:

$$\vec v - \vec w = \vec v + (-\vec w\ )$$

![[Vettore#^1dc604]]

## Moltiplicazione con scalari

_Si moltiplica un vettore e uno scalare e si ottiene un vettore_.

$$k\vec v = k \left[ \begin{array}{cc|r} v_1 \\ v_2 \\ \vdots \\ v_n \end{array} \right] = \left[ \begin{array}{cc|r} k v_1 \\ k v_2 \\ \vdots \\ k v_n \end{array} \right]$$

$$k\vec v = \underbrace{\vec v+\vec v+\vec v+\ldots+ \vec v}_{n\ volte}$$

$k\vec v$ è il vettore con:
- modulo $|k|\cdot ||\vec v ||$
- uguale direzione
- uguale verso (verso opposto se $k<0$)

## Prodotto scalare

Si [[moltiplicazione|moltiplicano]] due [[Vettore|vettori]] e si ottiene uno [[reali|scalare]]. Anche qui si procede per componenti.

$$\vec v \cdot \vec w = v_1 w_1 + v_2 w_2 + \ldots + v_n w_n$$

Non si distingue tra colonna vettore o riga vettore.

$$\vec v \cdot \vec w = ||\ \vec v\ ||\cdot \cos(\theta)\cdot ||\ \vec w\ ||$$
dove $\theta$ è l'[[angolo]] tra i due vettori.

> [!tip] $\vec v \cdot \vec v = v_1 v_1 + v_2 v_2 + \ldots + v_n v_n = ||\ \vec v\ ||^2$

> [!tip] Se $\vec v\cdot \vec w= 0$ allora $\vec v=0$ o $\vec w=0$.
> Se $\vec v\neq 0$ e $\vec w\neq 0$ allora $\vec v\cdot \vec w= 0$ se e solo se i due vettori sono perpendicolari e quindi il loro angolo compreso è $90°$ il cui $\cos$ è $0$.


# Prodotto vettoriale

Si [[moltiplicazione|moltiplicano]] due [[Vettore|vettori]] e si ottiene un vettore.

In $\Bbb R^3$ il prodotto vettoriale di $\vec v \times \vec w$ è il [[Vettore|Vettore]]

![[piano-passante-per-v-e-w.png|right|250]]
- [[ortogonalità|perpendicolare]] al piano passante per $\vec v$ e $\vec w$
- con modulo pari alla superficie del parallelogramma generato da $\vec v$ e $\vec w$, ovvero $$||\ \vec v\times \vec w\ || = ||\ \vec v\ || \cdot ||\ \vec w\ || \cdot \sin(\theta)$$
- la cui direzione segue la _regola della mano destra_

![[regola-della-mano-destra.png|center|400]]

### Proprietà del prodotto vettoriale

1. $\vec v\times \vec w = -(\ \vec v \times \vec w\ )$
2. $(k\vec{v} \ ) \times \vec{w}=k(\vec{v} \times \vec{w})=\vec{v} \times(k \vec{w})$
3. $\vec{v} \times(\vec{u}+\vec{w})=\vec{v} \times \vec{u}+\vec{v} \times \vec{w}$
4. $\vec{v} \times \vec{w}=\vec{0}$ sse $\vec{v}$ è parallelo a $\vec{w}$
5. $\vec{v} \times \vec{v}=\vec{0}$
6. $\vec{e}_1 \times \vec{e}_2=\vec{e}_3, \quad \vec{e}_2 \times \vec{e}_3=\vec{e}_1, \quad \vec{e}_3 \times \vec{e}_1=\vec{e}_2$ e $\vec{e}_2 \times \vec{e}_1=-\vec{e}_3, \quad \vec{e}_3 \times \vec{e}_2=-\vec{e}_1, \quad \vec{e}_1 \times \vec{e}_3=-\vec{e}_2$^[In notazione alternativa $e_1 = \hat i$, $e_2 = \hat{j}$, $e_3 = \hat k$]

> [!danger] Il prodotto vettoriale non è associativo

Definizione per componenti:

$$\left[ \begin{array}{cc|r} {\color{magenta}v_1} \\ {\color{orange}v_2} \\ {\color{blue}v_3} \end{array} \right] \times \left[ \begin{array}{cc|r} {\color{grey}w_1} \\ {\color{lightgreen}w_2} \\ {\color{cyan}w_3} \end{array} \right] = ({\color{magenta}v_1} \vec e_1 + {\color{orange}v_2} \vec e_2 + {\color{blue}v_3} \vec e_3) \times ({\color{grey}w_1} \vec e_1 + {\color{lightgreen}{\color{lightgreen}w_2}} \vec e_2 + {\color{cyan}w_3} \vec e_3)$$

$$=({\color{orange}v_3}{\color{cyan}w_3}-{\color{blue}v_3}{\color{lightgreen}w_2})\vec e_1 + ({\color{blue}v_3}{\color{grey}w_1}-{\color{magenta}v_1}{\color{cyan}w_3})\vec e_2 + ({\color{magenta}v_1}{\color{lightgreen}w_2} - {\color{orange}v_2}{\color{grey}w_1})\vec e_3$$

$$=\left[ \begin{array}{cc|r} {\color{orange}v_2}{\color{cyan}w_3}-{\color{blue}v_3}{\color{lightgreen}w_2} \\ {\color{blue}v_3}{\color{grey}w_1}-{\color{magenta}v_1}{\color{cyan}w_3} \\ {\color{magenta}v_1}{\color{lightgreen}w_2}-{\color{orange}v_2}{\color{grey}w_1} \end{array} \right]$$