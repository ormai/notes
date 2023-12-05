# Algebra delle matrici

Queste operazioni sono un'estensione delle operazioni sui [[Vettore|vettori]] essendo questi [[Matrice|matrici]] con una sola riga o colonna.

---

La [[somma]] di due matrici si fa componente per componente

$$\left[ \begin{array}{cccc} a_{11} & a_{12} & \ldots & a_{1m} \\ a_{21} & a_{22} & \ldots & a_{2m} \\ \vdots & \vdots &  & \vdots \\ a_{n1} & a_{n2} & \ldots & a_{nm}\end{array} \right] + \left[ \begin{array}{cccc} b_{11} & b_{12} & \ldots & b_{1m} \\ b_{21} & b_{22} & \ldots & b_{2m} \\ \vdots & \vdots &  & \vdots \\ b_{n1} & b_{n2} & \ldots & b_{nm}\end{array} \right]=$$

$$\left[ \begin{array}{cccc} a_{11} + b_{11} & a_{12} + b_{12} & \ldots & a_{1m} + b_{1m} \\ a_{21} + b_{21} & a_{22} + b_{22} & \ldots & a_{2m} + b_{2m} \\ \vdots & \vdots &  & \vdots \\ a_{n1} + b_{n1} & a_{n2} + b_{n2} & \ldots & a_{nm} + b_{nm} \end{array} \right]$$

Il multiplo [[reali|scalare]] di una matrice è definito componente per componente

$$k\left[ \begin{array}{cccc} a_{11} & a_{12} & \ldots & a_{1m} \\ a_{21} & a_{22} & \ldots & a_{2m} \\ \vdots & \vdots &  & \vdots \\ a_{n1} & a_{n2} & \ldots & a_{nm}\end{array} \right]=\left[ \begin{array}{cccc} ka_{11} & ka_{12} & \ldots & ka_{1m} \\ ka_{21} & ka_{22} & \ldots & ka_{2m} \\ \vdots & \vdots &  & \vdots \\ ka_{n1} & ka_{n2} & \ldots & ka_{nm}\end{array} \right]$$

## Matrice per vettore

Se $A$ è una matrice $n\times m$ con vettori riga $\vec w_1,\ldots,\vec w_n$, e $\vec x$ è un vettore in $\Bbb R^m$ allora

$$A\vec x = \left[ \begin{array}{c}\ -\ \vec w_1\ -\ \\\ -\ \vec w_2\ -\ \\ \vdots \\\ -\ \vec w_n\ -\ \end{array} \right] \vec x = \left[ \begin{array}{c} \vec w_1 \cdot \vec x \\ \vec w_2 \cdot \vec x \\ \vdots \\ \vec w_n \cdot \vec x \end{array} \right]$$

$A\vec x$ è una matrice le cui righe sono il [[prodotto-scalare|prodotto scalare]] di ciascuna riga di $A$ per il [[Vettore]] $\vec x$.

Questo si può fare solo se il numero di colonne di $A$ è uguale al numero di componenti di $\vec x$.

(Righe per vettore da una colonna vettore)

---

Il prodotto si può anche fare con le colonne invece che le righe di $A$.

Se i vettori colonna di una matrice $n\times m$ sono $\vec v_1,\ldots,\vec v_m$ e $\vec x$ è un vettore in $\Bbb R^m$ con le componenti $x_1,\ldots,x_m$, allora

$$A\vec x=\left[ \begin{array}{cccc} \vert & \vert & & \vert \\ \vec v_1 & \vec v_2 & \ldots & \vec v_m \\ | & | & & |\end{array}\right] \left[ \begin{array}{c} x_1 \\ x_2 \\ \vdots \\ x_m \end{array} \right] = x_1\vec v_1 + x_2\vec v_2 + \ldots + x_m\vec v_m$$

> [!note] $A\vec x$ è la [[Combinazione lineare]] delle colonne di $A$ con le componenti di $\vec x$ come coefficienti.

> [!tip] Regole per $A\vec x$
> sia $A$ una matrice $n\times m$ e siano $\vec x$ e $\vec y$ due vettori in $\Bbb R^m$ e $k$ uno scalare:
> 1. $A(\vec x + \vec y)=A\vec x + A\vec y$
> 2. $A(k\vec x) = k(A\vec x)$