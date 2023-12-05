---
aliases: 
    - reflection
    - reflections
    - riflessione
---

# Riflesso

Sia $L$ una [[retta]] nel [[piano cartesiano]] passante per l'origine e sia $\vec x=\vec x^\parallel + \vec x^\perp$ un [[vettore]] in $\Bbb R^2$.

![[ref.png|350]]

La [[tranformazione lineare]] $T(\vec x)=\vec x^\parallel -\vec x^\perp$ è il *riflesso di $\vec x$ intorno ad $L$*, spesso indicata come $ref_L(\vec x)$: $$ref_L(\vec x)=\vec x^\parallel-\vec x^\perp$$

C'è una relazione tra riflesso e [[proiezione ortogonale]]:

$$ref_L(\vec x)=2proj_L(\vec x)-\vec x=2(\vec x\cdot\vec u)\vec u-\vec x$$

La [[matrice]] di $T$ ha la forma $$\left[\begin{array}{cc} a & b \\ b & -a \end{array}\right]$$ dove $a^2+b^2=1$. Ogni matrice di questo tipo rappresenta una riflessione.