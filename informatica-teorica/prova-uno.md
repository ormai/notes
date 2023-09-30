# Prova del 24-02-2023

## ES.1

Sia dato il linguaggio:

$$L_1=\{s^tc^+(c|a)^*l^+s^+(a\vert c\vert l)^+ c^m\vert m \geq 0, t \geq 1\}$$
---

1. Determinare il tipo secondo la classificazione di Chomsky.
2. Fornire una grammatica generatrice.
3. Fornire un automa (possibilmente deterministico) che lo riconosca.

---

$$L_1=\{s^+c^+(c|a)^*l^+s^+(a\vert c\vert l)^+\}$$

1. $L_1$ è un linguaggio di tipo 3, quindi è generato da una grammatica lineare destra ed è riconosciuto da un'automa a stati finiti (deterministico).

2. $$G(L_1)=\langle\{a,c,l,s\},\{A,B,C,D,E\},S,P\rangle$$

con produzioni:
1. $S\to sS|sA$
2. $A\to cA|cB$
3. $B\to cB|aB|C$
4. $C\to lC|lD$
5. $D\to sD|sE$
6. $E\to aE|cE|lE|a|c|l$

---

3. $$AFD_1=\langle \{q_0,q_1,q_2,q_3,q_4,q_5,q_6\},\{a,c,l,s\},\delta,q_0,\{q_6\}\rangle$$

con $\delta$ definito dalla seguente matrice di transizione

|       |        $a$        |        $c$        |        $l$        |        $s$        |
|:-----:|:-----------------:|:-----------------:|:-----------------:|:-----------------:|
| $q_0$ | $\{\varnothing\}$ | $\{\varnothing\}$ | $\{\varnothing\}$ |     $\{q_1\}$     |
| $q_1$ | $\{\varnothing\}$ |     $\{q_2\}$     | $\{\varnothing\}$ |     $\{q_1\}$     |
| $q_2$ |     $\{q_3\}$     |     $\{q_2\}$     |     $\{q_4\}$     | $\{\varnothing\}$ |
| $q_3$ |     $\{q_3\}$     |     $\{q_3\}$     |     $\{q_4\}$     | $\{\varnothing\}$ |
| $q_4$ | $\{\varnothing\}$ | $\{\varnothing\}$ |     $\{q_4\}$     |     $\{q_5\}$     |
| $q_5$ |     $\{q_6\}$     |     $\{q_6\}$     |     $\{q_6\}$     |     $\{q_5\}$     | 
| $q_6$ |     $\{q_6\}$     |     $\{q_6\}$     |     $\{q_6\}$     | $\{\varnothing\}$ |

![[prova-uno-afd.svg|1000]]

dove $\delta$ è definita dalla seguente matrice di transizione:


## ES.2

Dato il linguaggio:

$$L_2=\{(a\vert b)^n f^* d^p e^* a^t (b\vert e)^* d^m\vert (n>m>0), (p,t\geq 0)\}$$

1. Determinare il tipo secondo la classificazione di Chomsky.
2. Fornire una grammatica generatrice.
3. Fornire un automa che lo riconosca.

---

Riscrivo il linguaggio semplificandolo:

$$\Huge L_2=\{(a|b)^n c^* d^* e^* a^* (b|e)^* d^m:n>m>0\}$$

1. $L_2$ è un linguaggio di tipo 2, quindi è generato da una grammatica _non contestuale_ ed è riconosciuto da un _automa a pila_.

2. $$G(L_2)=\langle\{a,b,c,d,e\},\{A,B,C,D,E,F\},S,P\rangle$$

Con produzioni:

$S\to aSd|bSd|aAd|bAd$ (stesso numero di $a|b$ e $d$)
$A\to aA|bA|aB|bB$ (almeno un $a|b$ in più delle $d$)
$B\to cB|C$
$C \to dC|D$
$D\to eD|E$
$E\to aE|F$
$F\to bF|eF|\varepsilon$

3. $$AP_2=\langle \{\},\{\},\{\},\delta,q_0,\{\} \rangle$$



---

## ES.3

Data la seguente formula della logica proposizionale

$$(A \iff B) \implies (A \implies B)$$

verificare, mediante il metodo dei tableaux **e** mediante il metodo delle tabelle di verità, se è soddisfacibile, tautologica o contraddittoria. Nel caso in cui sia soddisfacibile fornire almeno un modello.

![[esercizio]]