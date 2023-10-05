# Metodo del simplesso

Serve a risolvere problemi di [programmazione lineare](02-programmazione-lineare.md) in [forma standard](04-forma-standard.md), cercando una soluzione ottima fra le *soluzioni ammissibili di base*.

> [!important] Una **matrice di base** per $P_s$ è una sottomatrice di $B \in \Bbb R^{m \times m}$ di $A$ invertibile.

> [!important] Un vettore $\overline x \in \Bbb R^n$ è una **soluzione di base** per $P_s$ se esiste una matrice di base $B$ tale che si possa scrivere $\overline x$ come $$\overline x = \left[\begin{array}{c} \overline x_B = B^{-1}b \\ \overline x_N = 0 \end{array}\right]$$
> Una soluzione di base è ammissibile per $P_s$ se $\overline x_B \geq 0$.

> [!note] Una soluzione di base $\overline x$ soddisfa sempre i vincoli di $Ax = b$

> [!note] 