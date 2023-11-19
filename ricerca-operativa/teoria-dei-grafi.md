Per disegnare grafi e alberi: https://csacademy.com/app/graph_editor/

# Teoria dei grafi

I grafi sono strutture discrete che consistono di nodi (vertices, $V$) e archi (edges $E$)^[Rosen, Discrete Mathematics and Its Application].

Un grafo $G$ è individuato da una coppia di [[insiemi]]: l'insieme dei nodi $V$ e l'insieme degli archi $E$

$$G = (V, E)$$

![[grafo-esempio.png]]

$V = \{1, 2, 3, 4, 5, 6\}$

$E=\{(1, 2), (1, 3), (2, 3), (2, 4), (3, 5), (4, 6), (5, 6)\}$

Rappresentazione matriciale

1. [[matrice]] di incidenza, $A \in \Bbb R^{|V| \times |E|}$ $$A_{ij} = \begin{cases}1 & se\ l'arco\ j\ è\ associato\ al\ nodo\ i \\ 0 & altrimenti \end{cases}$$ $$A=\left[\begin{array}{} 1 & 1 & 0 & 0 & 0 & 0 & 0  \\ 1 & 0 & 1 & 1 & 0 & 0 & 0 \\ 0 & 1 & 1 & 0 & 1 & 0 & 0 \\ 0 &  0 & 0 & 1 & 0 & 1 & 0  \\ 0 & 0 & 0 & 0 & 1 & 0 & 1 \\ 0 & 0 & 0 & 0 & 0 & 1 & 1 \end{array}\right]$$
2. matrice di adiacenza, $A \in \Bbb R^{|V| \times |V|}$[^1] $$a_{ij} = \begin{cases} 1 & se\ l'arco\ i,j \in E \\ 0 & altrimenti \end{cases}$$ $$A = \left[\begin{array}{} 0 & 1 & 1 & 0 & 0 & 0 \\ 1 & 0 & 1 & 1 & 0 & 0 \\ 1 & 1 & 0 & 0 & 1 & 0 \\ 0 & 1 & 0 & 0 & 0 & 1 \\ 0 & 0 & 1 & 0 & 0 & 1 \\ 0 & 0 & 0 & 1 & 1 & 0 \end{array}\right]$$

Un **sotto grafo** di $G$ è un grafo $G' = (V', E')$ tale che $V' \subseteq V$, $E' \subseteq E$ e $E' \subseteq V' \times V'$. Se $V' = V$, allora $G$ è un sotto grafo di supporto.

Un **percorso** è un insieme di nodi $v_0, v_1, \ldots, v_k$ tale che $v_i, v_{i + 1} \in E$. La lunghezza di un percorso è il numero di archi che lo formano.
Es: $1 \to 4 : 1, 2, 3, 1, 2, 4$

Un **cammino** è un percorso senza ripetizioni di nodi, a parte il caso del ciclo dove $v_0 = v_k$.
Es: $1 \to 6 : 1, 2, 4, 6$
Ciclo: $1, 2, 3, 1$

Un grafo è **connesso** se per ogni coppia di nodi esiste almeno un cammino che li associa.

Un **albero** è un grafo connesso privo di cicli.

Il **grado di un nodo** è il numero di archi che coinvolgono il nodo.

$$grado = 1 \iff nodo\ foglia$$

[^1]: la matrice è simmetrica perché il grafo è non orientato