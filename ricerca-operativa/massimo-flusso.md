# Problema del massimo flusso

> [!note] È un caso particolare di [[flusso-costo-minimo|problema di flusso a costo minimo]].

Rappresentabile tramite un [[teoria-dei-grafi|grafo orientato]] $G = (V, E)$, dove si ha un solo nodo di origine $s$ che ha solo archi uscenti e produce una quantità di flusso $v \geq 0$. Si ha un solo nodo di destinazione $t$ che ha soli archi entranti e richiede una quantità $v \geq 0$. Tutti gli altri nodi $i:i \neq s,t$ sono di transito. Ciascun arco $(i, j)$ ha una capacità massima $b_{i, j}$.

Si vuole *massimizzare* il flusso $v$ prodotto da $s$ e richiesto da $t$.

$$\large PMF = \begin{cases} \underset{f,v}{\max} & z = v  \\ & Af + dv = 0 \\ & f \leq b \\ & f \geq 0 \end{cases}$$

dove
- $A$ è la matrice di incidenza del grafo
- $d = \left[\begin{array}{} d_s = -1 \\ d_t = 1 \\ 0 \\ \vdots \\ 0 \end{array}\right]$, (in questa variante di $PFCM$ non rappresenta la divergenza)

$PMF$ ammette *sempre* almeno una soluzione ottima $\left[\begin{array}{} f^* & v^*\end{array}\right]^T$.

> [!important] Taglio separatore sorgente-terminale (abbr. taglio)
> Partiziona $V$ in due sottoinsiemi $W$ e $\bar W$, si indica come $(W, \bar W)$, valgono $$W \cup \bar W = V$$ $$W \cap \bar W = \emptyset$$ $$s \in W$$ $$t \in \bar W$$
> 
> $s$ e $t$ non possono trovarsi nella stessa partizione.
> 
> La capacità di un taglio $(W, \bar W)$ è
> $$C(W, \bar W) = \sum_{\begin{array}{c} (i, j) \in E \\ i \in W \\ j \in \bar W \end{array}} b_{i,j}$$
> 
> Il **minimo taglio** è un taglio con capacità minima.

$$v = \sum_{\begin{array}{c} (i,j) \in E \\ i \in W \\ j \in \bar W \end{array}} f_{i,j} - \sum_{\begin{array}{c} (i,j) \in E \\ i \in \bar W \\ j \in W \end{array}} f_{i, j}$$

> [!important] Teorema del massimo flusso e minimo taglio
> Sia $\left[\begin{array}{} f & v \end{array}\right]^T$ un flusso ammissibile per $PMF$ [^1] e $(W, \bar W)$ un taglio. Allora
> $$v \leq C(W, \bar W)$$
> 
> $\left[\begin{array}{} f & v \end{array}\right]^T$ è ottimo e $(W, \bar W)$ è minimo se e solo se
> 1. $$C(W, \bar W) = v$$
> 2. $$\begin{cases} f_{i,j} = b_{i,j} \qquad (i,j) \in E,\ i \in W,\ j \in \bar W \\ f_{i,j} = 0 \qquad (i,j) \in E,\ i \in \bar W,\ j \in W\end{cases}$$

## Algoritmo di Ford e Fulkerson

Risolve $PMF$ in $O(|V| \cdot |E| \cdot \underset{(i,j)\in E} \max b_{i,j})$, se le capacità degli archi sono [[razionali|numeri razionali]], costruendo cammini incrementali da $s$ a $t$. Termina quando non esistono più cammini incrementali.

Un **cammino incrementale** è un cammino non orientato da $s$ a $t$, lungo il quale il flusso può essere incrementato di $\varepsilon > 0$.

Ad ogni nodo $j$ si assegna una coppia di etichette $[pred(j),incr(j)]$[^2]. I nodi etichettati sono contenuti in una lista $L$.

- All'inizio di ogni iterazione ad $s$ è assegnato $[pred(s) = +s,incr(s) = +\infty]$.
    - Si estrae da $L$ un nodo $i$ che viene usato per etichettare i nodi non etichettati $j$:
         - $j \notin L; \quad (i,j) \in E; \quad f_{i,j} < b_{i,j}$, quindi si pone $$incr(j) = \min\{incr(i), b_{i,j} -f_{i,j}\}$$ $$pred(j) = +i$$
         $j$ entra in $L$
         - $j \notin L; \quad (j, i) \in E; \quad f_{j,i} > 0$ quindi si pone: $$incr(j) = \min\{incr(i), f_{j,i}\}$$ $$pred(j) = -i$$
         $j$ entra in $L$
    - Il cammino incrementale è costruito quando si etichetta $t$. Si può anche costruire partendo da $t$, a ritroso, leggendo $pred(j)$ e arrivando a $s$.
- Dopo che il cammino incrementale è costruito, si incrementa o decrementa il suo flusso, rispettivamente per gli archi *in avanti* e per gli archi *all'indietro*, di una stessa quantità $\varepsilon = incr(t)$. Ciò risulta in un incremento complessivo del flusso $v$ da $s$ a $t$ di $\varepsilon$.
- Termina quando non esistono più cammini incrementali.

All'ultima iterazione i nodi $i \in L$ costituiscono gli elementi di $W^*$. $(W^*, \bar W^*)$ è un un taglio a capacità minima.
  
[^1]: quindi una soluzione ammissibile per $PMF$
[^2]: $pred(j)$ è il predecessore di $j$ lungo il cammino incrementale. $incr(j)$ è il massimo incremento di flusso possibile lungo il cammino incrementale