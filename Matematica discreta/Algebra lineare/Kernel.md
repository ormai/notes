# Kernel

Il kernel di una [[Trasformazione lineare|trasformazione lineare]] $T(\vec x)=A\vec x$ da $\Bbb R^m\to\Bbb R^n$ consiste in tutti gli [[zeri]] della trasformazioni, ovvero le soluzioni dell'[[equazione]] $T(\vec x)=A\vec x=\vec 0$.

Quindi il kernel è l'[[Insiemi|insieme]] delle soluzioni del [[Sistema lineare|sistema lineare]] $$A\vec x=\vec 0$$
e si denota con $ker(T)$ or $ker(A)$.

Il kernel è un sottoinsieme del [[dominio]] di $T$ e talvolta è detto _spazio nullo_ della trasformazione.

$ker(T)=ker(A)$ è un [[Sottospazio]] di $\Bbb R^m$.

Proprietà del kernel:
- il [[Vettore]] zero $\vec 0\in\Bbb R^m$ è nel kernel di $T$
- il kernel è chiuso sotto addizione
- il kernel è chiuso sotto moltiplicazione [[reali|scalare]]

---

- per una [[Matrice]] $n\times m$, $ker(a)=\{\vec 0\}\iff rank(A)=m$
- per una matrice $n\times m$, se $ker(A)=\{\vec 0\}$, allora $m\leq n$. Di conseguenza se $m>n$ nel kernel ci sono vettori diversi da $\vec 0$
- per una matrice quadrata $A$, $ker(A)=\{\vec 0\}$ sse $A$ è [[Inversa di una trasformazione|invertibile]]
