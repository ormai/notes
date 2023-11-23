# Programmazione lineare

Problema di programmazione lineare in forma generale

$$P \begin{cases}
\underset{x_1,\ldots,x_n} \max z = & c_1 x_1 + c_2 x_2 + \ldots + c_n x_n \\
& a_{1,1} x_1 + a_{1,2} x_2 + \ldots + a_{1,n} x_n \leq b_1 \\
& a_{2,1} x_1 + a_{2,2} x_2 + \ldots + a_{2,n} x_n \leq b_2 \\
& \ldots \\
& a_{m,1} x_1 + a_{m,2} x_2 + \ldots + a_{m,n} x_n \leq b_m \\
& x_1, x_2, \ldots, x_n \geq 0
\end{cases}$$

## Forma standard

Un problema di programmazione lineare in **forma standard** è sempre di *minimo*, i vincoli sono di uguaglianza e le variabili sono tutte $\geq 0$.

$$P_s
\begin{cases}
    \underset{x}{\min} z = & c^Tx \\
    & Ax=b \\
    & x \geq 0
\end{cases}
$$

$c\in\Bbb R^n = \left[\begin{array}{c} c_1 \\ c_2 \\ \vdots \\ c_n \end{array}\right]$ è il **vettore dei costi**

$x\in\Bbb R^n = \left[\begin{array}{c} x_1 \\ x_2 \\ \vdots \\ x_n \end{array}\right]$ è il **vettore delle variabili decisionali**

$A\in\Bbb R^{m\times n} = \left[\begin{array}{} a_{1,1} & a_{1,2} & \ldots & a_{1,n} \\ a_{2,1} & a_{2,2} & \ldots & a_{2,n} \\ \ldots & \ldots & \ldots & \ldots \\ a_{m,1} & a_{m,2} & \ldots & a_{m,n} \end{array}\right]$ è la **matrice dei coefficienti tecnologici**

$b\in\Bbb R^m = \left[\begin{array}{c} b_1 \\ b_2 \\ \vdots \\ b_n \end{array}\right]$ è il **vettore delle risorse**

> [!important] $n$ è il numero di variabili decisionali, $m$ è il numero di vincoli.

Ogni problema di programmazione lineare può essere scritto in forma standard.

La **regione ammissibile** di $P_s$ è $X=\{x \in \Bbb R^n : Ax = b, x\geq 0\}$ ed è un [[geometria-convessa|poliedro]]. Se la regione ammissibile è vuota $X = \varnothing$ allora $P_s$ è **inammissibile**.

$\overline x \in \Bbb R^n$ è ammissibile per $P_s$ se $\overline x \in X$

$x^* \in \Bbb R^n$ è una **soluzione ottima** per $P_s$ se $x^*\in X$ e $$\large \underbrace{c^Tx^*}_{z^*} \leq \underbrace{c^Tx}_z \qquad \forall x\in X$$
$P_s$ è **illimitato** se per ogni $k\in\Bbb R$ esiste $\overline x\in X$ tale che $c^T\overline x < k$

## Da forma generale a forma standard

1. $\underset{x}{\max}c^T x \iff -\underset{x}{\min}-c^T x$

2. $a_i^T x\geq b_i$ diventa $a_i^T x - x_{n+1}=b_i$. Si aggiunge una variabile ausiliaria ($x_{n+1} \geq 0$) detta *variabile di surplus*.

3. $a_i^T x \leq b_i$ diventa $a_i^T x + x_{n+1} = b_i$. Si aggiunge una variabile ausiliaria ($x_{n+1} \geq 0$) detta *variabile di slack*.
4. se $x_j$ non è vincolata si pone $x_j=x_j^+-x_j^-$ e si sostituisce nella funzione obiettivo e nei vincoli ($x_j^+ \geq 0$ e $x_j^- \geq 0$)