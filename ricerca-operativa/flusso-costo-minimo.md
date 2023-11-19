# Problema di flusso a costo minimo

Si vuole trasportare della merce da stabilimenti di produzione a punti vendita.

Rappresentabile tramite un [[teoria-dei-grafi|grafo orientato]] $G = (V, E)$ in cui si hanno nodi di *origine*, di *destinazione* e di *transito*.

- Variabili decisionali: $f_{i,j}$ è il **flusso** di merce sull'arco $(i,j)$
- Costi: $c_{i,j}$ è il costo per transitare sull'arco $(i,j)$
- Vincoli:
    - $l_{i,j}$ è la minima quantità di merce trasportabile su ogni arco $(i,j)$
    - $u_{i,j}$ è la massima quantità di merce trasportabile su ogni arco $(i,j)$
- Obiettivo: trasportare la merce dai nodi di origine ai nodi di destinazione, minimizzando i costi di trasporto.

> [!note] La **divergenza** di un nodo è
> $$d_i = \sum_{j:i,j \in E} f_{i,j} - \sum_{j:j,i \in E} f_{j,i}$$
> ovvero la differenza tra il flusso degli archi entranti e il flusso degli archi uscenti.
> 
> Per $d_i > 0$, $i$ è un nodo di origine;
> per $d_i < 0$, $i$ è un nodo di destinazione;
> per $d_i = 0$, $i$ è un nodo di transito.

---

$$\large PFCM \begin{cases}
  \underset f \min z = & c^T f \\
  & Af = d \\
  & l \leq f \leq u
  \end{cases}$$
dove
- $c \in \Bbb R^{|E|}$ è il [[vettore]] dei costi 
- $f \in \Bbb R^{|E|}$ è il vettore dei flussi
- $A \in \Bbb R^{|V| \times |E|}$ è la matrice di incidenza del grafo orientato
- $d \in \Bbb R^{|V|}$ è il vettore *divergenza*
- $l \in \Bbb R^{|E|}$ è il vettore delle capacità minime sugli archi (solitamente è $0$)
- $u \in \Bbb R^{|E|}$ è il vettore delle capacità massime sugli archi

> [!important] Se $PFCM$ è ammissibile, allora $\sum_{i \in V} d_i = 0$.