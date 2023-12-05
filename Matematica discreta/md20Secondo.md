# Esercizio 1

$$A=\left[\begin{array}{ccccc} 1 & -2 & 5 & 0 & -1 \\ 1 & -1 & 3 & 3 & 0 \\ -1 & 0 & -1 & -2 & 1 \\ 0 & 2 & -4 & 4 & 1 \\ \end{array}\right]$$

$$rref(A)=\left[\begin{array}{cccc} 1 & 0 & 1 & 0 & -2 \\ 0 & 1 & -2 & 0 & -\cfrac 12 \\ 0 & 0 & 0 & 1 & \cfrac 12 \\ 0 & 0 & 0 & 0 & 0 \end{array}\right]$$

$$A\vec x=0$$

$$\vec x=\left[\begin{array}{c} x_1 \\ x_2 \\ x_3 \\ x_4 \\ x_5 \end{array}\right]=\left[\begin{array}{c} -r & + & 2s \\ 2r & + & \cfrac 12 s \\ r  & & \\ & & -\cfrac 12 s \\ & & s \end{array}\right]=r\left[\begin{array}{c} -1 \\ 2 \\ 1 \\ 0 \\ 0 \end{array}\right]+s\left[\begin{array}{c} 2 \\ \cfrac 12 \\ 0 \\ -\cfrac 12 \\ 1 \end{array}\right]$$

Una base di $ker(A)$ è $$( \left[\begin{array}{c} -1 \\ 2 \\ 1 \\ 0 \\ 0 \end{array}\right],\left[\begin{array}{c} 2 \\ \cfrac 12 \\ 0 \\ -\cfrac 12 \\ 1 \end{array}\right])$$ Verifica: $dim(ker(A))+dim(im(A))=2+3=5=m$

# Esercizio 2

$e=(\vec e_1,\vec e_2,\vec e_3)$

$b=(\left[\begin{array}{c} 2 \\ 2 \\ 0 \end{array}\right],\left[\begin{array}{c} 1 \\ 1 \\ -1 \end{array}\right], \left[\begin{array}{c} 0 \\ 1 \\ -2 \end{array}\right])$
$[F]_e^e=\left[\begin{array}{ccc} 1 & 2 & 1 \\ -1 & 5 & 2 \\ 0 & -2 & 0 \end{array}\right]$

$$[I]^b_e=\left[\begin{array}{ccc} 2 & 1 & 0 \\ 2 & 1 & 1 \\ 0 & -1 & -2 \end{array}\right]$$

$$[I]_b^e=([I]_e^b)^{-1}$$

$$\left[\begin{array}{ccc|ccc} 2 & 1 & 0 & 1 & 0 & 0 \\ 2 & 1 & 1 & 0 & 1 & 0 \\ 0 & -1 & -2 & 0 & 0 & 1 \end{array}\right]=\left[\begin{array}{ccc|rrr} 1 & 0 & 0 & -\cfrac 12 & 1 & \cfrac 12 \\ 0 & 1 & 0 & 2 & -2 & -1 \\ 0 & 0 & 1 & -1 & 1 & 0 \end{array}\right]$$

Verifica:

$$\left[\begin{array}{ccc} 2 & 1 & 0 \\ 2 & 1 & 1 \\ 0 & -1 & -2 \end{array}\right]\left[\begin{array}{ccc} -\cfrac 12 & 1 & \cfrac 12 \\ 2 & -2 & -1 \\ -1 & 1 & 0 \end{array}\right]=\left[\begin{array}{ccc} 1 & 0 & 0 \\ 0 & 1 & 0 \\ 0 & 0 & 1  \end{array}\right]\qquad (ok)$$

$$[I]_b^e=\left[\begin{array}{ccc} -\cfrac 12 & 1 & \cfrac 12 \\ 2 & -2 & -1 \\ -1 & 1 & 0\end{array}\right]$$
$[F]_b^b=[I]_b^e[F]^e_e[I]^b_e$

$$[F]_b^b=\left[\begin{array}{ccc} -\cfrac 12 & 1 & \cfrac 12 \\ 2 & -2 & -1 \\ -1 & 1 & 0\end{array}\right]\left[\begin{array}{ccc} 1 & 2 & 1 \\ -1 & 5 & 2 \\ 0 & -2 & 0 \end{array}\right]\left[\begin{array}{ccc} 2 & 1 & 0 \\ 2 & 1 & 1 \\ 0 & -1 & -2 \end{array}\right]$$

$$=\left[\begin{array}{ccc} -\cfrac 32 & 3 & \cfrac 32 \\ 4 & -4 & -2 \\ -2 & 3 & 1 \end{array}\right]\left[\begin{array}{ccc} 2 & 1 & 0 \\ 2 & 1 & 1 \\ 0 & -1 & -2 \end{array}\right]=\left[\begin{array}{ccc} 3 & 0 & 0 \\ 0 & 2 & 0 \\ 2 & 0 & 1 \end{array}\right]$$

# Esercizio 5

$$\left\{\begin{array}{rcl}
x \equiv -909\quad (mod\ 83) \\
x \equiv 821\quad(mod\ 89) \\
29x \equiv 702\quad (mod\ 94)
\end{array} \right.$$