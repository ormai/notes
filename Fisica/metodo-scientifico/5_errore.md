---
aliases: 
  - "errori di misura"
  - "incertezze nelle misure"
---

# Incertezza di misura

La misura è intrinsecamente incerta perché affetta da
- limitazioni dello strumento
- problemi di calibrazione
- inadeguata definizione della misura da fare
- effetti che alternato l'entità da misurare

L'**incertezza** è la stima della larghezza dell'intervallo^[L'intervallo di tutte le misure effettuate] in cui si trova il *valore vero*.

La **migliore stima** della misura è in generale il valore centrale all'intervallo delle misure, pertanto la misura si denoterà

$$\rm (migliore\ stima\pm incertezza)\ unità\ di\ misura$$

La misura non può prescindere dall'errore. Perciò il risultato della misura deve essere dato come intervallo tra due valori della grandezza.

> [!tip] Incertezza relativa
> Consiste nel rapporto tra l'incertezza ed il valore centrale dell'intervallo.
> $$\left\vert\cfrac{\Delta u_1}{u_1}\right\vert$$
> Dà un'idea dell'incertezza relativa ad una certa misura. Permette di fare il confronto tra incertezze di misure diverse:
> $$\rm\cfrac{1 \mu m}{100\mu m}=0.01=1\%,\qquad\cfrac{10^{-6} m}{1 m}=10^{-6}$$
> Qui si vede l'effetto della stessa incertezza ($\rm 1\mu m$) su due misure diverse.

Gli errori di misura sono dovuti a varie cause a sono di diversi tipi:
- gli **errori grossolani** sono causati da letture sbagliate degli strumenti oppure dal loro uso improprio. Possono e devono essere evitati;
- gli **errori sistematici** sono presenti ad ogni ripetizione della misura e sono probabilmente causati da un problema con lo strumento;
- gli **errori casuali** sono l'effetto di variazioni casuali e imprevedibili delle condizioni in cui si fa la misura.

## Istogramma delle misure

Per rimediare agli errori casuali si ripete la misura più volte e si fa la [[media|media aritmetica]] dei risultati. Così si ottiene il valore più rappresentativo della misura.

La *distribuzione* delle misure può essere rappresentata in un istogramma.

Dato un campione di $n$ misure di una grandezza $x$, per costruire l'istogramma:
1. si ordinano le misure in ordine crescente
2. si determina l'**intervallo di dispersion** dato da $x_{\max}-x_{\min}$
3. si suddivide l'intervallo di dispersione in intervalli detti **classi**. Le classi hanno la stessa ampiezza e il numero di classi è $\sqrt{n}$
4. si determina la frequenza, ovvero il numero di misure in ogni classe^[Se una misura cade sul confine tra due classi si applica una convenzione prestabilita, che può essere di sommare mezza unità ad ognuna delle due classi; oppure sommare l'unità alla classe precedente o ancora a quella seguente.]
5. si costruisce l'istogramma costituito da rettangoli aventi sulle ascisse le basi di ampiezza pari all'intervallo della classe e sulle ordinate le altezze proporzionali alle frequenze.

Il valore più attendibile della grandezza si troverà al centro dell'istogramma.

![[istogramma-misure-fisica.webp|center]]

## Media

Da un campione $n$ di misure $\{x_1,x_2,\ldots,x_n\}$ il valore medio è $$\overline{x}=\langle x\rangle=\cfrac 1n \sum_{i=1}^n x_i=\cfrac{x_1+x_2+\ldots+x_n}n$$

La media non è sempre il *valore centrale* o *più probabile* della distribuzione, lo è soltanto nel caso di istogrammi simmetrici.

La **moda** è il picco più alto dell'istogramma.

## Scarto

Per ogni misura $x_i$ si definisce lo **scarto** $r_i$ come la differenza tra la misura e il valore medio $$\xi_i=r_i=x_i-\langle x\rangle,\qquad i=1,2,\ldots,n$$

Più gli scarti saranno mediamente maggiori più sarà grande l'incertezza e viceversa.

Per definire la stima della dispersione si fa la media degli *scarti dalla media*. Facendo così però si ha zero. Si fa allora la media degli scarti al quadrato.

> [!tip] Scarto quadratico medio
> $$\sigma^2=\cfrac 1n \sum_{i=1}^n(x_i-\overline{x})^2$$


> [!tip] Deviazione standard
> La radice quadrata di $\sigma^2$ restituisce la **deviazione standard**, ovvero la misura di quanto il campione di misure $\{x_1,x_2,\ldots,x_n\}$ è disperso intorno al valore medio.
> $$\sigma=\sqrt{\cfrac 1n \sum_{i=1}^n(x_i-\overline{x})^2}$$

## Propagazione delle incertezze

Per le misure indirette l'incertezza è propagata da ciascuna misura da cui essa deriva.

| Oprazione                | Incertezza                                            |
| ------------------------ | ----------------------------------------------------- |
| Somma $G=x+y$            | $\Delta G = (\Delta x + \Delta y)$                    |
| Differenza $G=x-y$       | $\Delta G = (\Delta x + \Delta y)$                    |
| Prodotto  $G=xy$         | $\Delta G = y\Delta x + x\Delta y$                    |
| Quoziente  $G=\cfrac xy$ | $\Delta G \approx \cfrac{y\Delta x + x\Delta y}{y^2}$ |
| Potenza $G=x^n$          | $\Delta G = nx^{n-1}\Delta x$                         | 

L'incertezza relativa di $G$ sarà^[Per la potenza sarà $$\cfrac{\Delta G}{G}=n\cfrac{\Delta x}{x}$$]

$$\cfrac{\Delta G}G = \cfrac{\Delta x}x+\cfrac{\Delta y}{y}$$

Spesso una grandezza indiretta è espressa come il prodotto di più grandezze dirette elevate ad un esponente (positivo/negativo/frazionario). L'errore relativo di una grandezza indiretta è la somma delle grandezze dirette da cui deriva, ciascuna moltiplicata per il [[modulo|valore assoluto]] del suo esponente.

$$\left\vert\cfrac{\Delta x}{x}\right\vert=\vert\alpha\vert\cdot\left\vert\cfrac{\Delta u_1}{u_1}\right\vert+\vert\beta\vert\cdot\left\vert\cfrac{\Delta u_2}{u_2}\right\vert+\ldots+\vert\gamma\vert\cdot\left\vert\cfrac{\Delta u_n}{u_n}\right\vert$$