# Teoria dei grafi

I grafi sono strutture discrete che consistono di nodi (vertices, $V$) e archi (edges $E$)[^1]. Un grafo $G$ è la coppia di [[Insiemi]] $$G = (V, E)$$
Rappresentazione:

1. [[Matrice]] di incidenza, $I \in \Bbb R^{|V| \times |E|}$ $$I_{i,j} = \begin{cases}1 & se\ l'arco\ j\ è\ associato\ al\ nodo\ i \\ 0 & altrimenti \end{cases}$$
2. matrice di adiacenza, $A \in \Bbb R^{|V| \times |V|}$[^2] $$A_{i,j} = \begin{cases} 1 & se\ l'arco\ i,j \in E \\ 0 & altrimenti \end{cases}$$

Quando gli archi sono coppie ordinate $(v,w)$ il grafo è **orientato**. Quando $v$ e $w$ coincidono l'arco è un'**anello**. Se gli archi sono insiemi il grafo è **non orientato** e $v$ e $w$ non possono coincidere[^3].

Sia $n$ il numero di nodi. Il numero massimo di archi per un grafo orientato è $n^2$, mentre per un grafo non orientato è $n\frac {n-1}2$. Quando, in un grafo orientato, tutti i possibili archi esistono questo è **denso**, se invece il numero di archi è $n$ il grafo è **sparso**.

Presi due nodi $a$ e $b$, se esiste l'arco $(a,b)$ allora i due nodi sono **adiacenti**. In un grafo non orientato $(a,b)$ e $(b,a)$ sono lo stesso arco. In un grafo orientato il primo sarebbe *uscente* da $a$ ed *entrante* in $b$. Nel caso di grafi orientati ogni nodo ha un grado di entrata (numero di archi entranti) ed un grado di uscita (numero di archi uscenti). In un grafo non orientato il **grado** sarebbe il numero di archi e di conseguenza il numero di nodi adiacenti.

Un **sotto grafo** di $G$ è un grafo $G' = (V', E')$ tale che $V' \subseteq V$, $E' \subseteq E$ e $E' \subseteq V' \times V'$. Se $V' = V$, allora $G$ è un sotto grafo di supporto.

Un **percorso** è un [[Insiemi|insieme]] di nodi $v_0, v_1, \ldots, v_k$ tale che $v_i, v_{i + 1} \in E$. La lunghezza di un percorso è il numero di archi che lo formano. Un **cammino** è un percorso senza ripetizioni di nodi. È ammessa la coincidenza del primo e ultimo nodo $v_0 = v_k$, si ha così un **ciclo**. In assenza di cicli il cammino è *semplice*.

Un grafo è **connesso** se per ogni coppia di nodi esiste almeno un cammino che li associa. Un grafo orientato è fortemente connesso se per ogni coppia di archi adiacenti esistono due archi che li collegano, con versi opposti. Altrimenti si ha un grafo debolmente connesso.

Per un grafo orientato la **chiusura transitiva** è un grafo distinto che consiste degli stessi nodi e degli archi mancanti.

Un **albero** è un grafo non orientato, connesso e aciclico, in cui ogni nodo ha un solo padre e dei figli. Ha una struttura gerarchica in cui la **radice** dell'albero non ha padre. I nodi che non hanno figli sono **foglie**.

$$grado = 1 \iff nodo\ foglia$$

Un grafo orientato è una collezione di alberi, detto *foresta*.


> [!example]-
> ![[grafo-esempio.png]]
> $V = \{1, 2, 3, 4, 5, 6\}$
> $E=\{(1, 2), (1, 3), (2, 3), (2, 4), (3, 5), (4, 6), (5, 6)\}$
> $$I=\left[\begin{array}{} 1 & 1 & 0 & 0 & 0 & 0 & 0  \\ 1 & 0 & 1 & 1 & 0 & 0 & 0 \\ 0 & 1 & 1 & 0 & 1 & 0 & 0 \\ 0 &  0 & 0 & 1 & 0 & 1 & 0  \\ 0 & 0 & 0 & 0 & 1 & 0 & 1 \\ 0 & 0 & 0 & 0 & 0 & 1 & 1 \end{array}\right]$$
> $$A = \left[\begin{array}{} 0 & 1 & 1 & 0 & 0 & 0 \\ 1 & 0 & 1 & 1 & 0 & 0 \\ 1 & 1 & 0 & 0 & 1 & 0 \\ 0 & 1 & 0 & 0 & 0 & 1 \\ 0 & 0 & 1 & 0 & 0 & 1 \\ 0 & 0 & 0 & 1 & 1 & 0 \end{array}\right]$$
> Un possibile percorso: $1 \to 4 : 1, 2, 3, 1, 2, 4$
> Un possibile cammino: $1 \to 6 : 1, 2, 4, 6$
> Ciclo: $1, 2, 3, 1$

> [!info] Per disegnare grafi e alberi: https://csacademy.com/app/graph_editor/

[^1]: Rosen, Discrete Mathematics and Its Application
[^2]: in un grafo non orientato sarà simmetrica
[^3]: un insieme può contenere un elemento una volta sola