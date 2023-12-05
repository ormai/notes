---
aliases: 
    - orthogonal projection
    - proj
---

# Proiezione ortogonale

Sia una [[retta]] $L$ nel [[piano cartesiano]] che passa per l'origine.

![[proj.png|300]] 

Qualsiasi [[vettore]] $\vec x$ in $\Bbb R^2$ si può scrivere univocamente come $$\vec x =\vec x^\parallel + \vec x^\perp$$ dove $\vec x^\parallel$ è [[parallelismo|parallelo]] ad $L$ mentre $\vec x^\perp$ è [[ortogonalità|perpendicolare]] ad $L$.


La [[trasformazione lineare]] $T(x)=\vec x^\parallel$ da $\Bbb R^2$ a $\Bbb R^2$ è la _proiezione ortogonale_ di $\vec x$ su $L$, solitamente denotata con $proj_L(\vec x)$.

$$(\vec x-k\vec w)\cdot\vec w=0;\qquad\vec x\cdot\vec w-k(\vec w\cdot\vec w)=0;\qquad k(\vec w\cdot\vec w)=\vec x\cdot\vec w$$

$$k=\cfrac{\vec x\cdot\vec w}{\vec w\cdot\vec w}$$

$$proj_L(\vec x)=\vec x^\parallel=k\vec w=\left(\cfrac{\vec x\cdot\vec w}{\vec w\cdot\vec w}\right)\cdot\vec w$$

> [!tip] Se invece di un qualsiasi $\vec w$ si ha un [[Versore]] $\vec u=\left[\begin{array}{c} u_1 \\ u_2 \end{array}\right]$ parallelo ad $L$, allora
> $$proj_L(\vec x)=(\vec x\cdot\vec u)\vec u$$

La trasformazione $T(\vec x)=proj_L(\vec x)$ è lineare con la matrice

$$P=\cfrac 1{w_1^2+w_2^2}\left[\begin{array}{cc} w_1^2 & w_1w_2 \\ w_2w_2 & w_2^2 \end{array}\right]=\left[\begin{array}{cc} u_1^2 & u_1u_2 \\ u_1u_2 & u_2^2 \end{array}\right]$$