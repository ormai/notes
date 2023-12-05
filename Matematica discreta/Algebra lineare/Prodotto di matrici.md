---
aliases: 
    - "prodotto di matrici"
    - "moltiplicazione tra matrici"
    - "matrix multiplication"
    - "matrix product"
---

# Prodotto di matrici

Composizione di [[Trasformazione lineare|trasformazioni lineari]].

> [!danger] Sia $B$ una matrice $n\times p$ e $A$ una matrice $q\times m$ il prodotto $BA$ è definito [[connectives|sse]] $p=q$.

Se $B$ è una [[Matrice]] $n\times p$ e se $A$ è una matrice $p\times m$, allora il prodotto $BA$ è definito come la matrice della trasformazione lineare $T(\vec x)=B(A\vec x)=(BA)\vec x$ per tutti gli $\vec x$ nello [[Spazio lineare|spazio vettoriale]] $\Bbb R^m$. Il prodotto $BA$ è una matrice $n\times m$.

Se le colonne di $A$ sono $\vec v_1,\vec v_2,\ldots,\vec v_m$ allora

$$BA=B\left[\begin{array}{cccc} | & | & & | & & | \\ \vec v_1 & \vec v_2 & \ldots & \vec v_i & \ldots & \vec v_m \\ | & | & & | & & | \end{array}\right]=\left[\begin{array}{cccc} | & | & & | & & | \\ B\vec v_1 & B\vec v_2 & \ldots & B\vec v_j & \ldots & B\vec v_m \\ | & | & & | & & | \end{array}\right]$$

$$BA=\left[\begin{array}{cccc} b_{11} & b_{12} & \ldots & b_{1p} \\ b_{21} & b_{22} & \ldots & b_{2p} \\ \vdots & \vdots & & \vdots \\ b_{i1} & b_{i2} & \ldots & b_{ip} \\ \vdots & \vdots & & \vdots \\ b_{n1} & b_{n2} & \ldots & b_{np} \end{array}\right]\left[\begin{array}{ccccc} a_{11} & a_{12} & \ldots & a_{1j} & \ldots & a_{1m} \\ a_{21} & a_{22} & \ldots & a_{2j} & \ldots & a_{2m} \\ \vdots & \vdots & & \vdots & & \vdots \\ a_{p1} & a_{p2} & \ldots & a_{pj} & \ldots & a_{pm} \end{array}\right]$$

$$=b_{i1}a_{1j}+b_{i2}a_{2j}+\ldots+b_{ip}a_{pj}=\sum_{k=1}^p b_{ik}a_{kj}$$

quindi si fa il prodotto delle righe di $B$ per le colonne di $A$.

Il prodotto tra matrici non è commutativo in generale $AB\neq BA$. Capita qualche volta che _commuta_ e quindi $AB=BA$.

> [!tip] Comporre una [[Trasformazione lineare|trasformazione lineare]] con la [[trasformazione-identità|matrice identità]] lascia la trasformazione inalterata
> $$AI_m=I_nA=A$$

Il prodotto di matrici è associativo

$$(AB)C=A(BC)=ABC$$

e gode della proprietà distributiva per cui

$$A(C+D)=AC+AD$$

$$(A+B)C=AC+BC$$

Data una matrice $A$ è uno scalare $k$ $$(kA)B=A(kB)=k(AB)$$

Se $A$ e $B$ sono matrici $n\times n$ [[Inversa di una trasformazione|invertibili]], allora $BA$ è anche invertibile e $$(BA)^{-1}=A^{-1}B^{-1}$$

> [!tip] $BAA^{-1}B^{-1}=I_n$