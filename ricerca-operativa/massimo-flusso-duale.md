# Duale del problema di massimo flusso

$$\large P \begin{cases}
\underset{f,v}{\max} z = & v \\
& Af + dv = 0\quad & |\ \pi' \\
& f \leq b \quad &|\ \gamma \\
& f \geq 0
\end{cases}$$

$$\large D \begin{cases}
\underset{\pi, \gamma} w = & \sum_{(i,j) \in E} b_{i,j} \gamma_{i,j} \\
& \pi_i - \pi_j - \gamma_{i,j} \leq 0 & (i,j) \in E \\
& \pi_s - \pi_t = 1 \\
& \gamma_{i,j} \geq 0 & (i,j) \in E
\end{cases}$$

Avendo un taglio $(W, \bar W)$ è *sempre* possibile associarvi una soluzione ammissibile per $D\left[\begin{array}{cc|r} \hat\pi & \hat\gamma \end{array}\right]^T$ dove 

$$\hat \pi_i = \begin{cases} 1 & i \in W \\ 0 & \in \bar W \end{cases}$$

$$\hat \gamma_{i, j} = \begin{cases} 1 & (i,j) \in E, & i \in W, & j \in \bar W \\ 0 & altrimenti \end{cases}$$

Usando questa soluzione per calcolare la funzione obiettivo $\hat w$ si ha

$$\hat w = \sum_{(i,j) \in E} b_{i,j} \hat \gamma_{i,j} = \sum_{\begin{array}{}(i,j) \in E \\ i \in W \\ j \in \bar W\end{array}} b_{i,j} = C(W, \bar W)$$

$D$ di $PMF$ si ottiene con il calcolo di un taglio a capacità minima.