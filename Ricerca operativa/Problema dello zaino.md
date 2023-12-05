# Problema dello zaino

Si ha uno zaino di capacità $b > 0$ ed $n$ tipi di oggetti.

$$Z \begin{cases}
\underset x \max z = & c_1 x_1 + c_2 x_2 + \ldots + c_n x_n \\
& c_1 x_1 + c_2 x_2 + \ldots + c_n x_n \leq b \\
& x_1,\ x_2,\ \ldots,\ x_n \geq 0 \\
& x_1\, x_2,\ \ldots,\ x_n\ {\rm int}
\end{cases}$$

dove ($j=1,\ \ldots,\ n$)
- $x_j$ è il numero di oggetti di tipo $j$ da inserire nello zaino
- $c_j > 0$ è il valore di un oggetto di tipo $j$
- $a_j$ è il peso di un oggetto di tipo $j$

## Problema dello zaino binario

Si hanno esattamente $n$ oggetti.

$$Z_B \begin{cases}
\underset x \max z = & c_1 x_1 + c_2 x_2 + \ldots + c_n x_n \\
& c_1 x_1 + c_2 x_2 + \ldots + c_n x_n \leq b \\
& c_1,\ x_2,\ \ldots,\ x_n \in \{0, 1\}
\end{cases}$$

dove
- $x_j$ è $1$ se l'oggetto $j$ viene inserito nello zaino, altrimenti è $0$
- $b > 0$ è la capacità dello zaino
- $c_j > 0$ è il valore dell'oggetto $j$
- $a_j > 0$ è il peso dell'oggetto $j$