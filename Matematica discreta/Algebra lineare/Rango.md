# Rango

È il massimo numero di righe o di colonne [[Dipendenza lineare|linearmente indipendenti]].

$$rank(A)\leq\min(m,n)$$

Il rango di una [[matrice]] $A$ è il numero di $1$ iniziali in $rref(A)$^[[[Sistema lineare#Eliminazione di Gauss-Jordan|matrice in forma ridotta a gradini]]] e si denota con $rank(A)$.

Si consideri un [[sistema lineare]] di $n$ [[equazione|equazioni lineari]] con $m$ variabili che abbia una matrice dei coefficienti $A$ di dimensione $n\times m$, allora
- $rank(A)\leq n$ e $rank(A) \leq m$ ^928b4c
- se il sistema è inconsistente $rank(A) < n$
- se il sistema ha una sola soluzione $rank(A)=m$
- se il sistema ha infinite soluzioni $rank(A)<m$

Ne deriva che
- se $rank(A)=n$ il sistema è consistente
- se $rank(A) < m$ il sistema non ha soluzioni o ne ha infinite
- se $rank(A) = m$ il sistema non ha soluzioni o ne ha esattamente una