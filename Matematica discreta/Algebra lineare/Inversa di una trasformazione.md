---
aliases: 
    - "trasformazione inversa"
    - "trasformazioni inverse"

---

# Inversa di una trasformazione

Una [[Trasformazione lineare]] $\vec y=T(\vec x)=A\vec x$, con $A$ [[Matrice]] $n\times n$ è invertibile se il [[Sistema lineare]] $$A\vec x=\vec y$$ ha un'unica soluzione $\vec x\in\Bbb R^n$ per ogni $\vec y\in\Bbb R^n$. Questo può succedere sse $rank(A)=n$ o se 

$$rref(A)=\left[\begin{array}{ccccc} 1 & 0 & 0 & \ldots & 0 \\ 0 & 1 & 0 & \ldots & 0 \\ 0 & 0 & 1 & \ldots & 0 \\ \vdots & \vdots & \vdots & \ddots & \vdots \\ 0 & 0 & 0 & \ldots & 1 \end{array}\right]=I_n$$

La trasformazione inversa sarà $$\huge \vec x=T^{-1}(\vec y)=A^{-1}\vec y$$

Per trovare l'inversa di una matrice $n\times n$ si calcoli $rref \left[\begin{array}{c|c} A & I_n \end{array}\right]$
- se il risultato ha forma $\left[\begin{array}{c|c} I_n & B \end{array}\right]$, allora $A$ è invertibile e $A^{-1}=B$
- se la parte sinistra del risultato non è $I_n$ allora $A$ non è invertibile

> [!tip] Per una matrice $A$ $n\times n$
> $$A^{-1}A=I_n$$ $$AA^{-1}=I_n$$

> [!info] Criterio di invertibilità
> Siano $A$ e $B$ due matrici $n\times n$ tale che $$BA=I_n$$
> Allora
> - $A$ e $B$ sono entrambe invertibili
> - $A^{-1}=B$ e $B^{-1}=A$
> - $A=I_n$

> [!tldr] Caratterizzazioni di matrici invertibili
> Sia $A$ una matrice $n\times n$ le seguenti affermazioni sono equivalenti, quindi sono tutte vere o tutte false
> 1. $A$ è invertibile
> 2. il sistema lineare $A\vec x=\vec b$ ha un'unica soluzione $\vec x,\forall\ \vec b\in\Bbb R^n$
> 3. $rref(A)=I_n$
> 4. $rank(A)=n$
> 5. $im(A)=\Bbb R^n$
> 6. $ker(A)=\{\vec 0\}$