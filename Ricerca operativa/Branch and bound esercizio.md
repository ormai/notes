$$\begin{cases}
  z^*_{PLI} = \underset{x}{\min} & x_1 + 4x_2 \\
  & 4x_1 + 10x_2 \geq 25 & (I) \\
  & 9x_1 - 7x_2 \leq 12 & (II) \\
  & x2 \leq 6 & (III) \\
  & x \geq 0,\ x\ \rm \underline {INT}
\end{cases}$$

$z^*_{PL} = 8.5$ (è lower bound per $z^*_{PLI}$)
$x^*_{PL} = \left[\begin{array}{c} \frac 52 \\ \frac 32 \end{array}\right]$

### Visita in profondità

![[branch-and-bound-1.excalidraw|center|1000]]

$\begin{cases} \overline x = ? \\ \overline z = +\infty \end{cases}$

${PL}_1 \begin{cases} x_1 = 2 \\ 4x_1 + 10x_2 = 25\end{cases} \qquad \begin{cases} x_1 = 2 \\ x_2 = \frac {17}{10}\end{cases}$
$x^*_{PL_1} = \left[\begin{array}{cc|r} 2 \\ 1.7 \end{array}\right]$, $z^*_{PL_1} = 8.8$

---

$PL_3\begin{cases}x_1 \leq 2 \\ x_2 \leq 1\end{cases} \qquad INAMMISSIBILE$

---

$PL_4 \begin{cases} x_2 \geq 2 \\ x_1 \leq 2 \end{cases}\qquad \begin{cases} 4x_1 + 10x_2 \geq 25 \\ x_2 = 2\end{cases} \qquad \begin{cases} x_1 = \frac 54 \\ x_2 = 2 \end{cases}$ 

$x^*_{PL_4} = \left[\begin{array}{c} 1.25 \\ 2 \end{array}\right]$,  $z^*_{PL_4} = 9.25$

---

$PL_5\begin{cases} x_1 \leq 1 \\ x_2 \geq 2 \\ \bcancel{x_1 \leq 2}\end{cases} \qquad \begin{cases} 4x_1 + 10x_2 \geq 25 \\ x_2 = 1 \end{cases} \qquad \begin{cases} x_2 = \frac{21}{10} \\ x_1 = 1\end{cases}$

$x^*_{PL_5} = \left[\begin{array}{c} 1 \\ 2.1 \end{array}\right]$, $z^*_{PL_5} = 8.4$

---
 $PL_7\begin{cases} x_2 \leq 2 \\ x_1 \leq 1 \\ x_2 \geq 2 \\ x_1 \leq 1 \end{cases}\qquad \begin{cases} x_1 \leq 1 \\ x_2 = 2\end{cases}\qquad INAMMISSIBILE$

---

 $PL_8\begin{cases} x_2 \geq 3 \\ x_1 \leq 1 \\ x_2 \geq 2 \\ x_1 \leq 1 \end{cases}\qquad \begin{cases} x_1 \leq 1 \\ x_2 \geq 3\end{cases}$
 
$x^*_{PL_8}=\left[\begin{array}{c} 0 \\ 3 \end{array}\right]$, $z^*_{PL_8} = 12 = z^*_{PLI_8}$

La soluzione trovata è migliore dell'attuale ($?$), come il valore di funzione obiettivo ($+\infty$), quindi si aggiornano i valori segnati:

$\begin{cases} \overline x = \left[\begin{array}{cc|r} 0 \\ 3 \end{array}\right] \\ \overline z = 12\end{cases}$

---

$PL_6\begin{cases} x_1 \geq 2 \\ x_2 \geq 2 \\ x_1 \leq 2 \end{cases}\qquad \begin{cases} x_1 = 2 \\ x_2 \geq 2 \end{cases}$

$x^*_{PL_6} = \left[\begin{array}{c} 2 \\ 2 \end{array}\right]$, $z^*_{PL_6} = 10$

$\begin{cases} \overline x = \left[\begin{array}{c} 2 \\ 2 \end{array}\right] \\ \overline z = 10 \end{cases}$

---

$PL_2\begin{cases} x_1 \geq 3\end{cases}\qquad\begin{cases} x_1 = 3 \\ 9x_1 - 7x_2 = 12\end{cases} \qquad \begin{cases} x_1 = 3 \\ x_2 \leq \frac{15}7 \end{cases}$

$z^*_{PL_2} = \left[\begin{array}{cc|r} 3 \\ 2.14 \end{array}\right]$, $z^*_{PL_2}=11.56$

---

$z^*_{PLI}=10$, $x^*_{PLI}=\left[\begin{array}{cc|r} 2 \\ 2 \end{array}\right]$