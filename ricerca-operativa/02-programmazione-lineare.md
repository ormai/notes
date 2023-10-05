# Programmazione lineare (PL)


Sia un [problema decisionale](01-problemi-decisionali) con $n$ variabili decisionali ed $m$ risorse ed i seguenti dati:
- $c_j$ profitto unitario dopo la vendita di un prodotto di tipo $j$ ($j=1,\ldots,n$)
- $b_i$ quantità della risorsa $i$ disponibile ($i=1,\ldots,m$)
- $a_{ij}$ quantità di $b_i$ necessaria a produrre $c_j$

Il problema si può formulare matematicamente come

$$P\begin{cases} \underset{x_1, \ldots, x_n}{\max} & z = c_1 x_1 + c_2 x_2 + \ldots + c_n x_n\\ & a_{11}x_1+a_{12}x_2+\ldots+a_{1n}x_n\leq b_2 \\ & a_{21}x_2+a_{22}x_2+\ldots+a_{2n}x_n\leq b_2 \\ & \qquad\qquad\qquad \ldots \\ & a_{m1}x_1+a_{m2}x_2+\ldots+a_{mn}x_n\leq b_m \\ \\ & \qquad\qquad x_1,x_2,\ldots,x_n\geq 0\end{cases} $$


Dove $x_j$ è la quantità di prodotto di tipo $j$ da produrre ($j=1,\ldots,n$)

---

Sinteticamente:

$$P\begin{cases} \underset{x}{\min} & z = c^Tx \\ \\ & Ax\leq b, \\ & x\geq 0 \end{cases}$$

Dove:
- $A=\left[\begin{array}{cccc} a_{11} & a_{12} & \ldots & a_{1n} \\ a_{21} & a_{22} & \ldots & a_{2n} \\ \ldots & \ldots & \ldots & \ldots \\ a_{m1} & a_{m2} & \ldots & a_{mn} \end{array}\right]$ è la matrice dei coefficienti tecnologici
- $x=\left[\begin{array}{c} x_1 \\ x_2 \\ \vdots \\ x_n \end{array}\right]$ è il vettore delle variabili decisionali
- $c=\left[\begin{array}{cc|r} c_1 \\ c_2 \\ \vdots \\ c_n \end{array}\right]$ è il vettore dei costi
- $b=\left[\begin{array}{cc|r} b_1 \\ b_2 \\ \vdots \\ b_m \end{array}\right]$ è vettore delle risorse

---

Oppure:

$$P
\begin{cases}
    \underset{x}{\max} & z = c^Tx \\
    & a_i^T\leq b_i\quad i=1,\ldots,m \\
    & x_j\geq 0\quad j=1,\ldots,n
\end{cases}
$$

Dove: $a_i^T$ è la riga $i$-esima di $A$.