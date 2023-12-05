# Immagine di una trasformazione lineare

Data una 

L'immagine di una [[Trasformazione lineare]] $T(\vec x)=A\vec x$ è lo [[Span]] di $A$.

L'immagine di $T$ si denota con $im(T)$ o $im(A)$.

$$T(\vec x)=A\vec x=\left[\begin{array}{ccc} | & & | \\ \vec v_1 & \ldots & \vec v_m \\ | & & | \end{array}\right]=\left[\begin{array}{c} x_1 \\ \vdots \\ x_m \end{array}\right] = x_1\vec v_1+\ldots+x_2\vec v_2$$

$$Im(A)=Im(T)=span(\vec v_1,\ldots,\vec v_n)$$

$im(T)=im(A)$ è un [[Sottospazio]] di $\Bbb R^m$.

L'immagine di $T:\Bbb R^m\to\Bbb R^n$ ha le seguenti proprietà
- il [[Vettore]] zero $\vec 0$ di $\Bbb R^n$ è nell'immagine di $T$ $$\vec 0=A\vec 0=T(\vec 0)$$
- l'immagine di $T$ è chiusa sotto addizione $$\vec v_1=t(\vec w_1);\qquad\vec v_2=T(\vec w_2)$$ $$\vec v_1+\vec v_2=T(\vec w_1)+T(\vec w_2)=T(\vec w_1+\vec w_2)$$
- l'immagine di $T$ è chiusa sotto moltiplicazione [[reali|scalare]] $$\vec v=T(\vec w)\implies k\vec v=kT(\vec w)=T(k\vec w)$$

Dalle ultime due si trae che l'immagine di $T$ è chiusa sotto [[Combinazione lineare|combinazione lineare]].

> [!tip] Base di un'immagine
> Per costruire la [[Base]] dell'immagine di una [[Matrice]] $A$ si elencano le colonne vettore di $A$ e si rimuovono i [[Vettore ridondante|vettori ridondanti]].