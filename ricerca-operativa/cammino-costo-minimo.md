# Problema del cammino di costo minimo

> [!note] È un caso particolare di [problema di flusso a costo minimo](flusso-costo-minimo.md).

Si ha un solo nodo di origine $s$, che produce flusso, $d_s = 1$, e si ha un solo nodo di destinazione $t$, che richiede flusso, $d_t = -1$. Tutti gli altri nodi $i$ ($i \neq s,t$) sono nodi di transito, quindi $d_i = 0$. Ciascun arco ha un certo costo $c_{i,j}$.

$$\large PCCM_{s,t} \begin{cases} \underset f\min z = & c^T f \\  & Af = d \\ & f \geq 0 \end{cases}$$

dove
- $A$ è la matrice di incidenza del [[grafi|grafo orientato]]
- $d = \left[\begin{array}{c} d_s = 1 \\ d_t = -1 \\ 0 \\ \vdots \\ 0 \end{array}\right]$

$PCCM_{s,t}$ ammette almeno una soluzione ottima $f^*$ binaria $f^*_{i,j} \in \{0, 1\}$. Per ogni componente $f^*$, se $f^*_{i,j} = 1$ l'arco $(i, j)$ appartiene al cammino minimo da $s$ a $t$, altrimenti non vi appartiene.

## Problema del cammino di costo minimo da un nodo a tutti gli altri

Si ha un solo nodo di origine $s$, con $d_s = |V| - 1$. Tutti gli altri nodi sono di destinazione (in numero $|V| - 1$), con $d_i = -1$, $i \neq s$. Ciascun arco ha un certo costo $c_{i, j}$.

$$\large PCCM \begin{cases} \underset f\min z = & c^T f \\  & Af = d \\ & f \geq 0 \end{cases}$$

dove
- $A$ è la matrice di incidenza del grafo orientato
- $d = \left[\begin{array}{c} d_s = |V| - 1 \\ -1 \\ \vdots \\ -1 \end{array}\right]$

$PCCM$ ammette una soluzione ottima $f^*$ **intera**. Per ogni componente di $f^*$ se $f^*_{i,j} > 0$, allora l'arco $(i,j)$ appartiene all'albero dei cammini minimi da $s$ a tutti gli altri archi. Non vi appartiene invece se $f^*_{i,j} = 0$.

## Algoritmo di Dijkstra

> [!warning] I costi (pesi) sugli archi devono essere non negativi.^[CLRS, Introduction to Algorithms, fourth edition, p. 620]

Risolve $PCCM$ (da un solo nodo a tutti gli altri) in $O(|V|^2)$,  solo se $c_{i,j} \geq 0$, per ogni $(i, j) \in E$.

- $W$ è l'[[insiemi|insieme]] dei nodi etichettati permanentemente
- etichette:
    - $\rho(i)$ è il costo di un cammino dal nodo $s$ al nodo $i$
    - $pred(i)$ è il nodo che precede $i$ nel cammino da $s$ a $i$

1. Inizializzazione
    $W = \emptyset$
    $\begin{cases} \rho(s) = 0 \\ \rho(i) = +\infty,\ \forall i \in V \land i \neq s\end{cases}$
    $pred(i) = s,\ \forall i \in V$
2. Svolgimento
    - Fra i nodi non appartenenti a $W$ si individua il nodo $v$ con etichetta $\rho$ più piccola
    $$\rho(v) = \underset{i \notin W} \min \rho(i)$$
        e si inserisce in $W$, rendendo così l'etichetta permanente.
    - Per ogni altro nodo $i \notin W$ per cui $(v, i) \in E$ si calcola $\rho(v) + c_{v,i}$ e se questa è $< \rho (i)$ si pone $\rho(i) = \rho(v) + c_{v,i}$ e $pred (i) = v$.
3. Fine quando $W = V$ 

Il risultato è che per ogni $i \in V$, $\rho(i)$ è il costo di un cammino da $s$ a $i$, mentre $pred(i)$ è il nodo che precede $i$ andando da $s$ a $i$.

https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm