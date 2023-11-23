# Teoria della dualità

Ad un problema di [[programmazione-lineare|programmazione lineare]], il **primale** $P$, si può sempre associare un altro problema di programmazione programmazione lineare, il **duale** $D$. Da uno si possono dedurre proprietà dell'altro e similmente si può dedurre la soluzione ottima.

$$P = \begin{cases}
\underset x \min z = & c^T x \\
& Ax = b, \quad A \in \Bbb R^{m \times n} \\
& x \geq 0
\end{cases}$$

$$D = \begin{cases}
\underset \pi \max w = & b^T \pi \\
& A^T \pi \leq c \\
& \pi \lesseqgtr0
\end{cases}$$

$x$ sono le variabili primali, $\pi$ sono le variabili duali. Da $P$ a $D$ $b$ e $C$ si scambiano, $A$ diventa trasposta quindi si scambiano il numero di vincoli $m$ e il numero di variabili $n$. In $D$ i vincoli di uguaglianza diventano di disuguaglianza e le variabili diventano libere in segno.

Se il primale è di minimizzazione il duale è di massimizzazione.

Il duale del duale è il primale.

> [!important] Dualità debole
> Sia $x$ una qualsiasi soluzione ammissibile per $P$ e sia $\pi$ una qualsiasi soluzione ammissibile per $D$. Allora:
> $$\large \underbrace{b^T \pi}_w \leq \underbrace{c^T x}_z$$
> La funzione obiettivo del del duale è **limite inferiore** per la funzione obiettivo del primale.
> 
> > [!important] Corollario
> >  Se
> > $$b^T \pi = c^T x$$
> > $x$ è una soluzione ottima per $P$ e $\pi$ è una soluzione ottima per $D$
>
> > [!info] Corollario
> > Se il primale è illimitato, il duale è inammissibile.

L'obiettivo del problema duale è trovare il migliore limite inferiore per la funzione obiettivo del primale.

> [!important] Dualità forte
> Se $P$ ammette soluzione ottima $x^*$, allora anche $D$ ammette soluzione ottima $\pi^*$ e si ha
> $$\large \underbrace{b^T \pi^*}_{w^*} = \underbrace{c^T x^*}_{z^*}$$
>
> Se $P$ è inammissibile $D$ non ha soluzione ottima quindi o è illimitato o è inammissibile.

## Relazioni di complementarietà

Siano

$$P = \begin{cases}
\underset x \min z = & c^T x \\
& Ax = b, & A \in \Bbb R^{m \times n} \\
& x \geq 0
\end{cases}$$

$$D = \begin{cases}
\underset \pi \max w = & b^T \pi \\
& A^T \pi \leq c \\
& \pi \geq 0
\end{cases}$$

$x$ soluzione qualsiasi per $P$, $\pi$ soluzione qualsiasi per $D$.

$x$ è soluzione ottima per $P$ e $\pi$ è soluzione ottima per $D$ se e solo se

$$\begin{cases}
(a_i^T - b_i)\ \pi-i = 0, & i = 1,\ \ldots,\ m \\
(c_j - A_j^T \pi)\ x_j = 0, & j = 1,\ \ldots,\ n
\end{cases}$$

Quindi $\bar x \in \Bbb R^n$ è ottimo per $P$ e $\bar \pi \in \Bbb R^m$ è ottimo per $D$ se e solo se $\bar x$ è ammissibile per $P$, $\bar \pi$ è ammissibile per $D$ ed entrambe soddisfano le relazioni di complementarietà.

## Primale in forma generale

Se si ha un problema di programmazione lineare in forma generale

$$P \begin{cases}
\underset x \min z = & c^T x \\
& a_i^T x = b_i & i = 1,\ \ldots,\ m_1 \\
& a_i^T x \geq b_i & i = m_1 + 1,\ \ldots,\ m \\
& x_j \geq 0 & j = 1,\ \ldots,\ n_1 \\
& x_j \lesseqgtr 0 & j = n_1 + 1,\ \ldots, n
\end{cases}$$

il suo duale è 

$$P \begin{cases}
\underset \pi \max w = & b^T \pi \\
& A^T_i \pi \leq c_j & j = 1,\ \ldots,\ m \\
& A_j^T \pi = c_j & j = n_1 + 1,\ \ldots,\ n \\
& \pi_i \lesseqgtr 0 & i = 1,\ \ldots,\ m_1 \\
& \pi_i \geq 0 & i = m_1 + 1,\ \ldots,\ m
\end{cases}$$

dove $a_i^T$ è la riga $i$-esima di $A$, mentre $A_j$ è la $j$-esima colonna di $A$.