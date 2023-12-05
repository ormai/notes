# 16 novembre 2023

<?xml version="1.0" standalone="no"?>
<!DOCTYPE svg PUBLIC "-//W3C//DTD SVG 1.1//EN" "https://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd">

<svg width="540" height="320" version="1.1" xmlns="http://www.w3.org/2000/svg">
	<ellipse stroke="black" stroke-width="1" fill="none" cx="52.5" cy="165.5" rx="30" ry="30"/>
	<text x="48.5" y="171.5" font-family="Times New Roman" font-size="20">s</text>
	<ellipse stroke="black" stroke-width="1" fill="none" cx="166.5" cy="46.5" rx="30" ry="30"/>
	<text x="163.5" y="52.5" font-family="Times New Roman" font-size="20">1</text>
	<ellipse stroke="black" stroke-width="1" fill="none" cx="166.5" cy="282.5" rx="30" ry="30"/>
	<text x="161.5" y="288.5" font-family="Times New Roman" font-size="20">2</text>
	<ellipse stroke="black" stroke-width="1" fill="none" cx="394.5" cy="282.5" rx="30" ry="30"/>
	<text x="389.5" y="288.5" font-family="Times New Roman" font-size="20">4</text>
	<ellipse stroke="black" stroke-width="1" fill="none" cx="394.5" cy="46.5" rx="30" ry="30"/>
	<text x="389.5" y="52.5" font-family="Times New Roman" font-size="20">3</text>
	<ellipse stroke="black" stroke-width="1" fill="none" cx="506.5" cy="165.5" rx="30" ry="30"/>
	<text x="503.5" y="171.5" font-family="Times New Roman" font-size="20">t</text>
	<polygon stroke="black" stroke-width="1" points="73.253,143.837 145.747,68.163"/>
	<polygon fill="black" stroke-width="1" points="145.747,68.163 136.602,70.481 143.823,77.399"/>
	<text x="81.5" y="97.5" font-family="Times New Roman" font-size="20">7,2</text>
	<polygon stroke="black" stroke-width="1" points="73.436,186.987 145.564,261.013"/>
	<polygon fill="black" stroke-width="1" points="145.564,261.013 143.562,251.794 136.4,258.773"/>
	<text x="83.5" y="244.5" font-family="Times New Roman" font-size="20">3,1</text>
	<polygon stroke="black" stroke-width="1" points="196.5,282.5 364.5,282.5"/>
	<polygon fill="black" stroke-width="1" points="364.5,282.5 356.5,277.5 356.5,287.5"/>
	<text x="269.5" y="303.5" font-family="Times New Roman" font-size="20">8,1</text>
	<polygon stroke="black" stroke-width="1" points="415.245,260.829 485.755,187.171"/>
	<polygon fill="black" stroke-width="1" points="485.755,187.171 476.611,189.493 483.835,196.408"/>
	<text x="455.5" y="244.5" font-family="Times New Roman" font-size="20">6,1</text>
	<polygon stroke="black" stroke-width="1" points="415.061,68.346 485.939,143.654"/>
	<polygon fill="black" stroke-width="1" points="485.939,143.654 484.097,134.402 476.815,141.255"/>
	<text x="455.5" y="97.5" font-family="Times New Roman" font-size="20">2,2</text>
	<polygon stroke="black" stroke-width="1" points="196.5,46.5 364.5,46.5"/>
	<polygon fill="black" stroke-width="1" points="364.5,46.5 356.5,41.5 356.5,51.5"/>
	<text x="268.5" y="67.5" font-family="Times New Roman" font-size="20">6,3</text>
	<polygon stroke="black" stroke-width="1" points="166.5,252.5 166.5,76.5"/>
	<polygon fill="black" stroke-width="1" points="166.5,76.5 161.5,84.5 171.5,84.5"/>
	<text x="171.5" y="170.5" font-family="Times New Roman" font-size="20">4,1</text>
	<polygon stroke="black" stroke-width="1" points="194.867,272.738 478.133,175.262"/>
	<polygon fill="black" stroke-width="1" points="478.133,175.262 468.941,173.137 472.195,182.593"/>
	<text x="339.5" y="245.5" font-family="Times New Roman" font-size="20">4,0</text>
	<polygon stroke="black" stroke-width="1" points="394.5,252.5 394.5,76.5"/>
	<polygon fill="black" stroke-width="1" points="394.5,76.5 389.5,84.5 399.5,84.5"/>
	<text x="399.5" y="170.5" font-family="Times New Roman" font-size="20">2,0</text>
	<polygon stroke="black" stroke-width="1" points="373.656,68.076 187.344,260.924"/>
	<polygon fill="black" stroke-width="1" points="187.344,260.924 196.499,258.645 189.307,251.697"/>
	<text x="285.5" y="185.5" font-family="Times New Roman" font-size="20">3,1</text>
</svg>

Le coppie di numeri sugli archi indicano $capacità,\ flusso\ corrente$.

## I iterazione

Inizializzazione $\boxed{\bar v = 2 + 0 + 1 = 3}$ (somma dei flussi correnti degli archi entranti in $t$)

| Propaga |   $1$    |   $2$    |   $3$    |   $4$    |   $t$    | Lista           | Commento                           |
|:-------:|:--------:|:--------:|:--------:|:--------:|:--------:| --------------- | ---------------------------------- |
|   $s$   | $[+s,5]$ | $[+s,2]$ |          |          |          | $\bcancel 1, 2$ | $1$ viene estratto, strategia FIFO |
|   $1$   |          |          | $[+1,3]$ |          |          | $\bcancel 2, 3$ | esce $2$, entra $3$                |
|   $2$   |          |          |          | $[+2,2]$ | $[+2,2]$ | $3,4,t$           | $t$ etichettato, quindi STOP       | 

$\varepsilon = incr(t) = 2$

$\bar v = \bar v + \varepsilon = 3 + 2 = 5$

> [!note] Come etichettare
> $2$ è etichettato a partire da $s$ con un arco *in avanti* (quindi $pred(i)=+s$). L'incremento è il minimo tra l'incremento di s e il flusso disponibile, ovvero $\min\{+\infty, 3-1=2\}$. Allora si ha $$[+s,2]$$

Ricostruzione del cammino: $s,2,t$
Il flusso degli archi che fanno parte del cammino sono incrementati di $\varepsilon$.

![](prima-iterazione.png)
$(s,2)$ è ora saturo.
## II iterazione

| Propaga |   $1$    |   $2$    |   $3$    |   $4$    |   $t$    | Lista           | Commento                           |
|:-------:|:--------:|:--------:|:--------:|:--------:|:--------:| --------------- | ---------------------------------- |
|   $s$   | $[+s,5]$ |          |          |          |          | $\bcancel 1$    | $1$ viene estratto, strategia FIFO |
|   $1$   |          | $[-1,1]$ | $[+1,3]$ |          |          | $\bcancel 2, 3$ | entrano $2$ e $3$                  |
|   $2$   |          |          |          | $[+2,1]$ | $[+2,1]$ | $3,4,t$         | $t$ etichettato, quindi STOP       | 

$\bar v = \bar v + incr(t) = 5 + 1 = 6$

Cammino incrementale: $s,1,2,t$

![](seconda-iterazione.png)

## III iterazione

| Propaga |   $1$    |   $2$   |   $3$    |   $4$    |   $t$    | Lista        |
|:-------:|:--------:|:-------:|:--------:|:--------:|:--------:| ------------ |
|   $s$   | $[+s,4]$ | saturo  |          |          |          | $1$ |
|   $1$   |          | scarico | $[+1,3]$ |          |          | $3$          | 
|   $3$   |          |  $[+3,1]$       |          | scarico | saturo | $2$      |
|   $2$   |          |         |          | $[+2,1]$ | $[+2,1]$ | $4,t$      |

$\bar v = 7$

Percorso incrementale: $s,1,3,2,t$

![](terza-iterazione.png)

## IV iterazione

| Propaga |   $1$    |   $2$    |   $3$    |   $4$    |   $t$    | Lista |
|:-------:|:--------:|:--------:|:--------:|:--------:|:--------:| ----- |
|   $s$   | $[+s,3]$ |  saturo  |          |          |          | $1$   |
|   $1$   |          | scarico  | $[+1,2]$ |          |          | $3$   |
|   $3$   |          | $[+3,1]$ |          | scarico  |  saturo  | $2$   |
|   $2$   |          |          |          | $[+2,1]$ |  saturo  | $4$   |
|   $4$   |          |          |          |          | $[+4,1]$ | $t$   | 

$\bar v = 8$

Cammino incrementale: $s,1,3,2,4,t$

![](static/quarta-iterazione.png)

## V iterazione

| Propaga |   $1$    |   $2$   |   $3$    |   $4$   |  $t$   | Lista |
|:-------:|:--------:|:-------:|:--------:|:-------:|:------:| ----- |
|   $s$   | $[+s,2]$ | saturo  |          |         |        | $1$   |
|   $1$   |          | scarico | $[+1,1]$ |         |        | $3$   |
|   $3$   |          | saturo  |          | scarico | saturo |       |

Arrivati al nodo $3$ non si può incrementare il flusso di nessun arco poiché gli archi entranti e uscenti da $3$ sono tutti scarichi o saturi. 

$$v^* = 8$$

![](quinta-iterazione.png)

$$(W^*, \bar W^*);\qquad C(W^*,\bar W^*) = 3 + 3 + 2 = 8$$
$$W^* = \{s, 1, 3\};\qquad \bar W^* = \{2, 4, 5\}$$

La capacità del taglio è la somma dei $flussi=capacità$ degli archi *in avanti* che attraversano il taglio.

Gli archi attraversati dal *minimo taglio* costituiscono il **collo di bottiglia** della rete. Questi archi hanno bisogno di più capacità.

## Formulazione come problema di programmazione lineare

$$PMF \begin{cases} \underset{f,v}\max z = & v \\
\\
& f_{s,1} + f_{s, 2} = v \\
& -f_{3,t} - f_{2,t} - f_{4,t} = -v \\
\\
& I\ flussi\ entranti\ e\ i\ flussi\ uscenti\ si\ equivalgono \\
& f_{1,3} - f_{s,1} - f_{2,1} = 0 \\
& f_{2,1} + f_{2,4} + f_{2,t} - f_{s,2} + f_{3,2} = 0 \\
& f_{3,2} + f_{3,5} - f_{1,3} - f_{4,3} = 0 \\
& f_{4,3} + f_{4,t} - f_{2,4} = 0 \\
\\
& Capacità\ minima\ e\ massima\ sugli\ archi \\
& 0 \leq f_{s,1} \leq 7 \\
& 0 \leq f_{s,2} \leq 3 \\
& 0 \leq f_{1,3} \leq 6 \\
& 0 \leq f_{2,1} \leq 4 \\
& 0 \leq f_{3,2} \leq 3 \\
& 0 \leq f_{2,4} \leq 8 \\
& 0 \leq f_{2,t} \leq 4 \\
& 0 \leq f_{4,3} \leq 2 \\
& 0 \leq f_{3,t} \leq 2 \\
& 0 \leq f_{4,t} \leq 6 \\



\end{cases}$$