---
aliases:
    - matrix
    - matrici
---

# Matrice

Array rettangolare di numeri.

$$A=\left[ \begin{array}{cccc} a_{11} & a_{12} & a_{13} & a_{14} \\ a_{21} & a_{22} & a_{23} & a_{24} \\ a_{31} & a_{32} & a_{33} & a_{34} \end{array} \right]$$

In una matrice con $i$ righe e $j$ colonne, l'elemento $a_{ij}$ si trova all'incrociarsi della riga $i$esima con la colonna $j$esima.

Due matrici sono [[uguaglianza|uguali]] se hanno uguale numero di righe e di colonne e se gli elementi nelle rispettive posizioni sono uguali $$a_{ij} = b_{ij}$$

Se il numero di righe e di colonne sono uguali, la matrice è detta _quadrata_. La _diagonale principale_ comincia in alto a sinistra e finisce in basso a destra. L'altra diagonale è la _diagonale secondaria_.

Una matrice è _diagonale_ se gli elementi sopra e sotto la diagonale principali sono zero: $$a_{ij} = 0 : i\neq j$$

Una matrice è _triangolare superiore_ se tutti gli elementi sopra la diagonale principale sono zero $a_{ij} = 0 : i > j$. Similmente per matrici _triangolari inferiori_.

Una matrice contente solo zero è detta _matrice zero_ e si denota con $0$ a prescindere dalla sua dimensione.

Una matrice con una sola colonna è una _colonna vettore_ o anche solo [[Vettore]]. Una matrice con una sola riga è una _riga vettore_.