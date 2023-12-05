# Matrice di cambiamento di base

Sia $b=(\vec v_1,\ldots,\vec v_n)$ una [[Base]] di $\Bbb R^n$.

Sia $e=(\vec e_1,\ldots,\vec e_n)$ la base naturale di $\Bbb R^n$

Sia $\vec v\in\Bbb R^n$.

$[I]_e^b$ è una [[Matrice]] di cambiamento di base, dalla base $b$ alla base $e$. Le colonne sono le [[Coordinate]] rispetto alla base $e$ dei [[Vettore|vettori]] della base $b$.

$$[I]_e^b=\left[\begin{array}{cccc} | & | & & | \\ [\vec v_1]_e & [\vec v_2]_e & \ldots & [\vec v_n]_e \\ | & | & & |\end{array}\right]$$

$$[\vec v]_e=[I]_e^b[\vec v]_b$$

$[I]_b^e$ è la matrice di cambiamento di base, dalla base $e$ alla base $b$. Le colonne sono le coordinate rispetto alla base $b$ dei vettori della base $e$.

$$[I]_b^e=\left[\begin{array}{cccc} | & | & & | \\ [\vec e_1]_b & [\vec e_2]_b & \ldots & [\vec e_n]_b \\ | & | & & |\end{array}\right]$$

$$[\vec v]_b=[I]^e_b[\vec v]_e$$

$$\huge [I]^e_b=([I_e^b])^{-1}$$