# Equazione parametrica e vettoriale di rette in R²

- $l$ è una [[retta]] in $\Bbb R^2$.
- $Q=(x_0,y_0)$ è un [[punto]] fissato su $l$
- $P=(x,y)$ è un punto generico di $l$
- $\vec v=\left[ \begin{array}{cc|r} a \\ b \end{array} \right]$ è un [[Vettore|Vettore]] di direzione per $l$ (Quindi $\vec v = \overrightarrow{AB}$ e $A$, $B$ sono due punti distinti di $l$)
- $\overrightarrow{OP}$ è un multiplo di $\vec v$, quindi $\overrightarrow{OP}=k\vec v,\ k\in\Bbb R$.

![[equazioni-di-rette.excalidraw|center]]

$$\large \boxed{\overrightarrow{OP}=\overrightarrow{OQ}+\overrightarrow{QP}}$$

$$\left[ \begin{array}{cc|r} x \\ y \end{array} \right] = \left[ \begin{array}{cc|r} x_0 \\ y_0 \end{array} \right] + k \left[ \begin{array}{cc|r} a \\ b \end{array} \right],\quad k\in\Bbb R\qquad\qquad(equazione\ vettoriale)$$

$$\left\{\begin{array}{rcl} x = x_0 + at \\ y = y_0 + bt \end{array}\right.\ ,\quad t\in\Bbb R\qquad\qquad (equazione\ parametrica)$$

Notare che per $t=0$ si ha $Q$ e che per $t=1$ si ha $P$.

> [!note] Le componenti del vettore di direzioni sono i coefficienti di $t$.