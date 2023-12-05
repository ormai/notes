---
aliases:
    - linear transformation
    - applicazione lineare
---

# Trasformazione lineare

Una [[funzione]] $T$ da $\Bbb R^m$ a $\Bbb R^n$ è una _trasformazione lineare_^[Le trasformazioni lineari sono un tipo speciale di funzioni.] se esiste una [[Matrice]] $A$ di dimensioni $n\times m$ tale che $$\large T(\vec x)=A\vec x$$ per tutti gli $\vec x$ nello [[Spazio lineare|spazio vettoriale]] $\Bbb R^m$.

Denotando il vettore $T(\vec x)$ con $\vec y$ si ha $$\large \vec y = A\vec x$$

Qui $\vec y$ è l'output e $\vec x$ è l'input della trasformazione. Entrambi sono [[Vettore|vettori]].

In termini di componenti si ha

$$\left[\begin{array}{c} y_1 \\ y_2 \\ \vdots \\ y_3 \end{array}\right]=\left[\begin{array}{cccc} a_{11} & a_{12} & \ldots & a_{1m} \\ a_{21} & a_{22} & \ldots & a_{2m} \\ \vdots & \vdots & & \vdots \\ a_{n1} & a_{n2} & \ldots & a_{nm} \end{array}\right]\left[\begin{array}{c} x_1 \\ x_2 \\ \vdots \\ x_m \end{array}\right] = \left[\begin{array}{cccc} a_{11} x_1 + a_{12} x_2 + \ldots + a_{1m} x_m \\ a_{21} x_1 + a_{22} x_2 + \ldots + a_{2m} x_m \\ \vdots \quad\qquad  \vdots \ \ \quad\qquad\qquad \vdots \\ a_{n1} x_1 + a_{n2} x_2 + \ldots + a_{nm}x_m \end{array}\right]$$

> [!info] Le [[variabile|variabili]] di output $y_i$ sono [[funzione-lineare|funzioni lineari]] di quelle di input $x_j$.
> Una funzione lineare con $m$ variabili ha la forma $$y=c_1x_1+c_2x_2+\ldots+c_mx_m$$ per i coefficienti $c_1,c_2,\ldots,c_m$. 

Una trasformazione $T$ da $\Bbb R^m$ a $\Bbb R^n$ è lineare sse
1. $T(\vec v + \vec w)=T(\vec v) + T(\vec w)$ per tutti i $\vec v$ e $\vec w$ in $\Bbb R^m$
2. $T(k\vec v) = kT(\vec v)$ per tutti i vettori $\vec v$ in $\Bbb R^m$ e tutti gli [[reali|scalari]] $k$.

> [!tip] Le colonne della matrice di una trasformazione lineare
> Si consideri $T:\Bbb R^m\to \Bbb R^n$. La matrice di $T$ è
> $$A\left[\begin{array}{cccc} | & | & & | \\ T(\vec e_1) & T(\vec e_2) & \ldots & T(\vec e_m) \\ | & | & & |\end{array}\right]$$ dove $\vec e_i = \left[\begin{array}{c} 0 \\ 0 \\ \vdots \\ 1 \\ \vdots \\ 0 \end{array}\right]$ in cui l'$1$ si trova alla riga $i$esima.
> Quindi $$T(\vec e_i) = A\vec e_i=\left[\begin{array}{cccccc} | & | & & | & & | \\ \vec v_1 & \vec v_2 & \ldots & \vec v_i & \ldots & \vec v_m \\ | & | & & | & & | \end{array}\right] \left[\begin{array}{c} 0 \\ 0 \\ \vdots \\ 1 \\ \vdots \\ 0\end{array}\right]=\vec v_1$$
> I vettori $\vec e_i$ sono [[Versore|vettori standard]].

## Geometricamente

Una trasformazione ha effetti geometrici diversi in base alla matrice coefficienti $A$:
- [[Ridimensionamento]]
- [[Proiezione ortogonale|proiezioni ortogonale]]
- [[Riflesso]]
- rotazione
- rotazione + ridimensionamento
- taglio