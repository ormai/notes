# Programmazione lineare intera

[[Programmazione lineare]] ma $x \in \Bbb Z^n$.

$$PLI \begin{cases}
z^*_{PLI} = \underset x \min & c^T x \\
& Ax \geq b, & A \in \Bbb R^{m \times n}\\
& x \geq 0 \\
& x\ \rm intero
\end{cases}$$

Il **rilassato continuo** continuo di $PLI$ è

$$PL \begin{cases}
z^*_{PL} = \underset x \min & c^T x \\
& Ax \geq b, & A \in \Bbb R^{m \times n}\\
& x \geq 0 \\
\end{cases}$$

Si ottiene rimuovendo il vincolo di interezza, passando così dal [[interi|discreto]] al [[reali|reale]].

Il valore ottimo di funzione obiettivo del rilassato continuo è **limite inferiore** per il valore ottimo di funzione obiettivo per $PLI$$

$$\large z^*_{PL} \leq z^*_{PLI}$$

Se una $x^*_{PL}$ è un ha tutte le componenti intere, allora è soluzione ottima anche per $PLI$.

---

> [!info]
> La **copertura convessa** $conv(S)$ di un [[Insiemi|insieme]] $S \subseteq \Bbb R^n$ è il più piccolo insieme convesso che contiene $S$. Se $S$ è convesso $conv(S) = S$

> La formulazione di $PLI$ è **ideale** se $X_{PL} = conv(X)$. Determinare la formulazione ideale di $PLI$ è molto difficile.



## Algoritmo Branch and Bound

Risolve $PLI$, con $X_{PL} \neq \varnothing$.

Partiziona $X$ in $X_1$ e $X_2$ generando due sotto problemi $PLI_1$ e $PLI_2$ che mantengono la stessa funzione obiettivo di $PLI$. Da ciò deriva che

$$z^*_{PLI} = \min \{z^*_{PLI_1},\ z^*_{PLI_2}\}$$

1. Si risolve il rilassato continuo $PL$ di $PLI$ ottenendo $x^*_{PLI}$
    - se $x^*_{PL} \in X$, l'algoritmo termina poiché $x^*_{PLI} = x^*_{PL}$
2. [[#Branching]]. Si generano $PLI_1$ e $PLI_2$ partendo da una componente non intera $x^*_{PL_h}$ di $x^*_{PL}$
3. Si risolvono i rilassati continui di $PLI_1$ e $PLI_2$

Quale tra $PLI_1$ e $PLI_2$?
- approccio *depth-first*: sempre quello a sinistra
- nodo più mettente: quello con il valore ottimo di funzione obiettivo più basso

Iterando questi tre passi si genera un albero di sotto problemi. Non tutti i sotto problemi generano a loro volta sotto problemi. Quando un nodo non genera sotto problemi questo si dice *chiuso*, l'algoritmo termina quando tutti i nodi foglia dell'albero sono chiusi. La soluzione ottima di $PLI$ è il miglior punto intero generato.

Dato che $x_{PL}$ è un politopo l'algoritmo termina sicuramente. Nel caso peggiore l'algoritmo ha complessità esponenziale.

All'inizio $\bar z$ si pone a $+\infty$, ovvero il caso peggiore per un problema di minimizzazione. Al termine dell'algoritmo $\bar x$ è la soluzione ottima di $PLI$.

### Branching

Dopo aver calcolato $x^*_{PL}$ si considera una qualsiasi sua componente non intera $x^*_{PL_h}$ e si calcolano

$$\large X_1 = X \cap \{x \in \Bbb R^n : x_h \leq \lfloor x^*_{PL_h} \rfloor \}$$
$$\large X_2 = X \cap \{x \in \Bbb R^n : x_h \geq \lfloor x^*_{PL_h} \rfloor + 1 \}$$

$$PLI_1 \begin{cases}
z^*_{PLI} = \underset x \min & c^T x \\
& Ax \geq b \\
& x_h \leq \lfloor x^*_{PL_h} \rfloor \\
& x \geq 0 \\
& x \ \rm intero
\end{cases}$$

$$PLI_2 \begin{cases}
z^*_{PLI} = \underset x \min & c^T x \\
& Ax \geq b \\
& x_h \geq \lfloor x^*_{PL_h} \rfloor + 1 \\
& x \geq 0 \\
& x \ \rm intero
\end{cases}$$

dove $x_h$ è la *variabile di branching*.

### Chiudere un nodo

Siano 
- $PLI_t$ un qualsiasi sotto problema
- $\bar x$ la migliore soluzione intera corrente
- $\bar z$ il valore di funzione obiettivo in $\bar x$
- $x^*_{PLI_t}$ una soluzione ottima per $PLI_t$
- $z^*_{PLI_t}$ il valore di funzione obiettivo in $x^*_{PLI_t}$
- $x^*_{PL_t}$ una soluzione ottima del rilassato continuo di $PLI_t$
- $z^*_{PL_t}$ il valore di funzione obiettivo in $x^*_{PL_t}$


$PLI_t$ è chiuso se
- $x^*_{PL_t} \in X$, ovvero è intero. Da cui segue che $x^*_{PL_t} = x^*_{PLI_t}$ e $z^*_{PL_t} = x^*_{PLI_t}$.
    - se $z^*_{PL_t} < \bar z$ è stato trovato una soluzione a componenti intere migliore della corrente, quindi si pone $\bar x = x^*_{PL_t}$ e $\bar z = z^*_{PL_t}$
- $PL_t$ è inammissibile. Visto che $X \subset X_{PL}$.
- $x^*_{PL_t}* \notin X$ e $z^*_{PL_t} \geq z$. È inutile continuare a cercare avendo già una soluzione a coordinate intere non peggiore di quello che potrebbe fornire il sotto problema di $PLI_t$