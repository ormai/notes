## Forma standard

Un problema di PL in forma standard
  - è un problema di minimizzazione
  - i vincoli di $A$ sono vincoli di eguaglianza
  - tutte le variabili sono vincolate ad essere $\geq 0$

$$P
\begin{cases}
    \underset{x}{\min} & z = c^Tx \\
    & Ax=b \\
    & x \geq 0
\end{cases}
$$

con $A\in\Bbb R^{m\times n}, b\in\Bbb R^m, x\in\Bbb R^n$ e $c\in\Bbb R^n$

Ogni problema di PL può essere scritto in forma standard.

---

(*punto* $\equiv$ *vettore* $\equiv$ *soluzione*)

La **regione ammissibile** di $P_s$ è $X=\{x\in\Bbb R^n:Ax = b, x\geq 0\}$

> [!tip] la regione ammissibile di un problema di PL è un [poliedro](03-geometria-convessa)

$P_s$ è **inammissibile** se $X=\varnothing$

$\overline x \in \Bbb R^n$ è ammissibile per $P_s$ se $\overline x \in X$

$x^* \in \Bbb R^n$ è una **soluzione ottima** per $P_s$ se $x^*\in X$ e $$\large \underbrace{c^Tx^*}_{z^*} \leq \underbrace{c^Tx}_z \qquad \forall x\in X$$
$P_s$ è **illimitato** se per ogni $k\in\Bbb R$ esiste $\overline x\in X$ tale che $c^T\overline x < k$

## Riduzione a forma standard di un problema di PL

1. $\underset{x}{\max}c^T x \iff -\underset{x}{\min}-c^T x$

2. $a_i^T x\geq b_i$ diventa $a_i^T x - x_{n+1}=b_i$. Si aggiunge una variabile ausiliaria ($x_{n+1} \geq 0$) detta *variabile di surplus*.

3. $a_i^T x \leq b_i$ diventa $a_i^T x + x_{n+1} = b_i$. Si aggiunge una variabile ausiliaria ($x_{n+1} \geq 0$) detta *variabile di slack*.
4. se $x_j$ non è vincolata si pone $x_j=x_j^+-x_j^-$ e si sostituisce nella funzione obiettivo e nei vincoli ($x_j^+ \geq 0$ e $x_j^- \geq 0$)