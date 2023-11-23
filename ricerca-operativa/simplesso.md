
# Algoritmo del simplesso

Risolve problemi di [[programmazione-lineare|programmazione lineare]] in forma standard.

1. *se non è data*, determina una [[#Soluzione di base|soluzione ammissibile di base]] iniziale per $P_s$ $$\bar x = \left[\begin{array}{cc|r} \bar x_B = B^{-1} b \\ \bar x_N = 0 \end{array}\right]\geq 0$$ 
2. calcola il [[#Il vettore dei costi ridotti fuori base|vettore dei costi ridotti fuori base]] $\hat c_N^T$
    - se $\hat c^T_N \geq 0$ l'algoritmo termina poiché $\bar x = x^*$
3. calcola $d = B^{-1} N e_j$, con $j \in \{1,\ \ldots,\ n-m\}$ tale che $\hat c_{{\cal N}(j) < 0}$
    - se $d \leq 0$ l'algoritmo termina poiché $P_s$ è illimitato
4. [[#Calcolare una nuova soluzione di base ammissibile|calcola una nuova soluzione ammissibile]] $x$
5. pone $\bar x = x$ e si va al passo 2

La prima fase del simplesso è tralasciata qui. Si assume che la soluzione ammissibile iniziale sia data[^3].

## Soluzione di base

$B \in \Bbb R^{m \times m}$ è una sotto matrice quadrata di $A$ invertibile ed è una **base** per $P_s$.
Un punto[^1] $\bar x \in \Bbb R^n$ è una **soluzione di base** per $P_s$ se si può scrivere come $$\bar x = \left[\begin{array}{} \bar x_B = B^{-1} b \\ \bar x_N = 0\end{array}\right]$$ dove $\bar x_B$ contiene le componenti *in base* di $\bar x$, mentre $\bar x_N$ contiene le componenti *fuori base* di $\bar x$. Una soluzione di base soddisfa sempre il sistema di vincoli $Ax = b$.[^2]

$$\bar x\ è\ una\ soluzione\ di\ base\ per\ P_s \implies \bar x\ contiene\ al\ massimo\ m\ componenti\ non\ nulle$$

Una soluzione di base $\bar x$ è **ammissibile** se $\bar x_B \geq 0$.

$$\bar x\ è\ una\ soluzione\ ammissibile\ per\ P_s \iff \bar x\ è\ un\ punto\ estremo\ di\ X$$


> [!note] Teorema fondamentale della programmazione lineare
> 1.  Se esiste una soluzione ammissibile per $P_s$, allora esiste almeno una soluzione ammissibile di base per $P_s$;
> 2. Se esiste una soluzione ottima per $P_s$, allora esiste almeno una soluzione ottima di base per $P_s$.

Una soluzione di base $\bar x$ è **ottima** se

$$\underbrace{c^T \bar x}_{\bar z} \leq \underbrace{c^T x}_z \quad \forall x \in X$$

ovvero, se il valore di funzione obiettivo calcolato sostituendo la soluzione attuale $\bar x$ alle variabili decisionali è minore di ogni altra soluzione di base $x$ esistente nella regione ammissibile $X$.


## Il vettore dei costi ridotti fuori base

Il vettore dei costi $c$ si può scomporre tra le componenti in base e quelle fuori base

$$c^T=\left[\begin{array}{} c_B^T & c_N^T \end{array}\right]$$

Le quali vengono usate per calcolare il vettore dei costi ridotti fuori base

$$\hat c^T_N = c^T_N - c_B^T \cdot B^{-1} \cdot N$$

Il vettore dei costi ridotti in base $\hat c^T_B = c^T_B - c_B^T \cdot B^{-1} \cdot B$ e quindi

$$c^T_B = 0^T$$

$\bar x = \left[\begin{array}{} \bar x_B = B^{-1} b \\ \bar x_N = 0 \end{array}\right] \geq 0$ è **ottima** se $\hat c_N^T \geq 0$.

## Calcolare una nuova soluzione di base ammissibile

A partire da $\bar x$ una soluzione ammissibile di base non ottima per $P_s$, che già si ha, si vuole determinare nuova soluzione di base ammissibile per $P_s$ che sia migliore della precedente $x$.

$$\large x = \left[\begin{array}{cc|r} x_B \\ x_N \end{array}\right] = \left[\begin{array}{cc|r} \bar x_B - \bar \delta_j d \\ e_j \bar \delta_j \end{array}\right]$$

dove $\bar \delta_j = \underset{i : d_i > 0} \min \cfrac{\bar x_{\beta (i)}}{d_i}$,
$d=B^{-1} \cdot N \cdot e$

$x_N = e_j \delta_j$ dove $e_j \in \Bbb R^{n - m}$ è un vettore con componenti nulle tranne la $j$-esima che è $1$. $\delta_j$ è uno scalare positivo.

$\cal \beta$ è l'insieme degli indici delle componenti in base di $\bar x$.
$\cal N$ è l'insieme degli indici delle componenti fuori base di $\bar x$.

se $\bar x$ non è ottime esiste $j \in \{1,\ \ldots,\ n - m\}$ per cui $c_{{\cal N} (j) < 0}$.

$x_{{\cal N} (j)}$ che in $\bar x$ era fuori base in $x$ entra in base con valore $\bar \delta_j$. 

## Soluzioni degeneri

Una soluzione di base $\bar x = \left[\begin{array}{} \bar x_B = B^{-1} b \\ \bar x_N = 0 \end{array}\right]$ è **degenere** se ha almeno una componente nulla.

Avendo una soluzione ottima per $P_s$ $x^* = \left[\begin{array}{} \bar x^*_B = B^{-1} b \\ \bar x^*_N = 0 \end{array}\right]$ non degenere è certo che $\hat c^T_N \geq 0$.

Se $P_s$ ammette soluzione ottima e l'algoritmo non incontra soluzioni degeneri, questo termina fornendo una soluzione ottima.

> [!important] Regola di Bland
> Se invece l'algoritmo incontra una soluzione degenere, si individuano
> - la colonna $j$-esima, con $j$ più piccolo possibile tale che $\hat c_{{\cal N}(j) < 0}$
> - la la riga $i$-esima, con $i$ più piccolo possibile tale che
> $$\hat \delta_j = \cfrac{\hat x_{\beta(i)}}{d_i} = \underset {i:d_i > 0} \min \cfrac{\hat x_{\beta(i)}}{d_i}$$
> e si va **pivot** sull'elemento $i,j$, procedendo così verso una nuova soluzione di base ammissibile per $P_s$ (passo 4).

## Tableau

Il passo 4 dell'algoritmo si fa tramite l'operazione di **pivot** sul sistema $Ax = b$. L'elemento su cui si fa pivot deve essere $\neq 0$. La procedura di pivot è simile ad un iterazione dell'algoritmo di [[sistema|Gauss-Jordan]].

| $I \qquad B^{-1} N$     | $\bar x_B$ |
| ----------------------- | ---------- |
| $0^T \qquad \hat c^T_N$ | $-\bar z$  |

Le colonne che corrispondono alle variabili decisionali in base hanno come colonne le colonne della matrice identità, e sotto zeri ($0^T$).

[^1]: punto, vettore e soluzione sono sinonimi
[^2]: Definizione alternativa: $\bar x \in \Bbb R^n$ è soluzione di base per $P_s$ se $A\bar x = b$ e se le colonne di $A$ in corrispondenza delle componenti non nulle di $\bar x$ sono linearmente indipendenti.
[^3]: A. Fuduli, Appunti di ricerca operativa, Lezione 5 - La Prima Fase del Simplesso, p. 27
