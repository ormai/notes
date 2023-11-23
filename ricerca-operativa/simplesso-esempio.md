---
aliases:
---
# Esempio algoritmo del simplesso

$\overline x = \left[\begin{array}{cc} \overline x_B = B^{-1} b \\ \overline x_N = 0 \end{array}\right] \geq 0$

nuovo punto $x=\left[\begin{array}{cc} x_B \\ x_N \end{array}\right] = \left[\begin{array}{c} \overline x_B -\alpha d \\ \alpha e_j \end{array}\right]$ 

1. $j : \hat c_N(j) < 0$
2. $d = B^{-1} N ej$
3. $\alpha = \underset{i\ :\ d_i\ >\ 0}{\min} \cfrac{\overline x_{\beta(i)}}{d_i}$

Esempio

$P\begin{cases} \underset{x}{\max} & z = -x_1 +3x_2 \\ & x_2 \geq 1 \\ & x_1 + x_2 \leq 4 \\ & x_1, x_2 \geq 0 \end{cases}$

![[Drawing 2023-10-09 11.44.25.excalidraw]]

$\overline x =\left[\begin{array}{c} 0 \\ 1 \end{array}\right]$

$P\begin{cases} \underset{x}{\min} & z = x_1 - 3x_2 \\ & x_2 - x_3 = 1 \\ & x_1 + x_2 + x_4 = 4 \\ & x\geq 0 \end{cases}$

controllare che $\overline x$ è sia soluzione di base

$\overline x_3 = \overline x_2 - 1 = 1- 1 = 0$

$\overline x_4 = 4 - \overline x_1 -\overline x_2 = 4 - 0 - 1 = 3$

$\overline x^T = \left[\begin{array}{cccc} 0 & 1 & 0 & 3 \end{array}\right]$

$\beta = \{2,4\}\qquad N = \{1,3\}$

$\hat c_N^T = c_N^T - c_B^T B^{-1} N$

$C_N^T=\left[\begin{array}{cc} 1 & 0 \end{array}\right]\qquad c_B^T = \left[\begin{array}{cc} -3 & 0 \end{array}\right]\qquad B=\left[\begin{array}{cc|r}  1 & 0 \\ 1 & 1 \end{array}\right]$ prima riga è $A_2$, seconda $A_4$

$N=\left[\begin{array}{cc} 0 & -1 \\ 1 & 0 \end{array}\right]$ prima riga è $A_1$, seconda è $A_3$

$B^{-1}=\left[\begin{array}{cc|r}  1 & 0 \\ -1 & 1\end{array}\right]$

$\hat c_N^T=\underbrace{\left[\begin{array}{cc} 1 & 0 \end{array}\right]}_{c_N^T} - \underbrace{\left[\begin{array}{cc|r} -3 & 0  \end{array}\right]}_{C_B^T} \underbrace{\left[\begin{array}{cc} 1 & 0 \\ -1 & 1 \end{array}\right]}_{B^{-1}}\underbrace{\left[\begin{array}{cc} 0 & -1 \\ 1 & 0 \end{array}\right]}_{N} = \left[\begin{array}{cc|r} 1 & -3 \end{array}\right]$

$\hat c_N^T=\left[\begin{array}{cc|r}  1 & -3 \end{array}\right] =\left[\begin{array}{cc|r} \hat c_{N(1)} & \hat c_{N(2)} \end{array}\right]$

$d=B^{-1} N_{e_j}=B^{-1} N_{e_2}=\underbrace{\left[\begin{array}{cc|r} 0 & -1 \\ 1 & 1 \end{array}\right]}_{B^{-1}N} \underbrace{\left[\begin{array}{cc|r} 0 \\ 1\end{array}\right]}_{e_2} = \left[\begin{array}{cc|r} -1 \\ 1 \end{array}\right]$

$\alpha = \underset{i\ :\ d_i\ >\ 0}{\min} \cfrac{\overline x_{\beta_{(i)}}}{d_i}$      $\overline x_B=B^{-1}b=B^{-1}\left[\begin{array}{cc|r} 1 \\ 4   \end{array}\right]= \left[\begin{array}{cc|r} 1 \\ 3 \end{array}\right]$
$\min \left\{\cfrac 31\right\}=3$             $d=\left[\begin{array}{cc|r} -1 \\ 1 \end{array}\right]$

$\hat c_{N(j)} = \hat c_{N(2)}=-3=\hat c_3\implies x_3$ entra in base con valore di $\alpha$ 

$\implies x_3 = 3$

$\overline x_3$ entra in base

$\overline x_4$ esce fuori base

$x_N=\left[\begin{array}{cc|r} x_{N(1)} \\ x_{N(2)} \end{array}\right]=\left[\begin{array}{cc|r} x_1 \\ x_3 \end{array}\right]=\alpha e_j=3\left[\begin{array}{cc|r} 0 \\ 1 \end{array}\right]=\left[\begin{array}{cc|r} 0 \\ 3 \end{array}\right]$


$x_B=\left[\begin{array}{cc|r} x_{\beta(1)} \\ x_{\beta(2)}\end{array}\right]=\left[\begin{array}{cc|r} x_2 \\ x_4  \end{array}\right] = \overline x_B - \alpha d = \left[\begin{array}{cc|r} 1 \\ 3 \end{array}\right]-3\left[\begin{array}{cc|r} -1 \\ 1 \end{array}\right]=\left[\begin{array}{cc|r} 4 \\ 0 \end{array}\right]$


nuovo punto $x=\left[\begin{array}{cc|r} x_1 \\ x_2 \\ x_3 \\ x_4 \end{array}\right]=\left[\begin{array}{cc|r} 0 \\ 4 \\ 3 \\ 0 \end{array}\right]$
