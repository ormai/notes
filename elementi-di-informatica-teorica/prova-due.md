# Prova del 08-07-2022

## ES.1

Sia dato il linguaggio:

$$L_1=\{a^n b^*(c|a)^+f^m a^+ (d\vert b)^+ \vert m \geq 0, n > 0\}$$

1. Determinare il tipo secondo la classificazione di Chomsky.
2. Fornire una grammatica generatrice.
3. Fornire un automa (possibilmente deterministico) che lo riconosca.

---

Riscriviamo il linguaggio rimuovendo gli esponenti. $a$ ci deve essere uno o più volte quindi si può sostituire $a^n:n>0$ con $a^+$. Similmente $f$ ci deve essere zero o più volte, quindi si può sostituire $f^m:m\geq 0$ con $f^*$.
$$L_1=\{a^+ b^*(c|a)^+f^* a^+ (d\vert b)^+\}$$

1. Questo è un linguaggio di tipo 3, generato da una grammatica lineare destra e riconosciuto da un automa a stati finiti.

2. $$G(L_1)=\langle\{a,b,c,d,f\}, \{A,B,C,D,E\},S,P\rangle$$

con produzioni:
1. $S\to aS|aA$
2. $A\to bA|B$
3. $B\to cB|aB|cC|aC$
4. $C\to fC|D$
5. $D\to aD|aE$
6. $E\to dE|bE|d|b$

---

3. $$AFD_1=\langle \{q_0,q_1,q_2,q_3,q_4,q_5,q_6\},\{a,b,c,d,f\},\delta,q_0,\{q_6\}\rangle$$
dove $\delta$ è definita dalla seguente matrice di transizione

|       |      $a$      |      $b$      |      $c$      |      $d$      |      $f$      |
|:-----:|:-------------:|:-------------:|:-------------:|:-------------:|:-------------:|
| $q_0$ |   $\{q_1\}$   | $\varnothing$ | $\varnothing$ | $\varnothing$ | $\varnothing$ |
| $q_1$ |   $\{q_1\}$   |   $\{q_2\}$   |   $\{q_3\}$   | $\varnothing$ | $\varnothing$ |
| $q_2$ |   $\{q_3\}$   |   $\{q_2\}$   |   $\{q_3\}$   | $\varnothing$ | $\varnothing$ |
| $q_3$ |   $\{q_3\}$   |   $\{q_6\}$   |   $\{q_3\}$   |   $\{q_6\}$   |   $\{q_4\}$   |
| $q_4$ |   $\{q_5\}$   | $\varnothing$ | $\varnothing$ | $\varnothing$ |   $\{q_4\}$   |
| $q_5$ |   $\{q_5\}$   |   $\{q_6\}$   | $\varnothing$ |   $\{q_6\}$   | $\varnothing$ |
| $q_6$ | $\varnothing$ |   $\{q_5\}$   | $\varnothing$ |   $\{q_5\}$   | $\varnothing$ |

![[prova-due-afd.svg|1000]]


## ES.2

Dato il linguaggio:

$$L_2=\{f^n(f\vert e)^*d^+(b\vert e)^*d^m\vert n>m>0\}$$

1. Determinare il tipo secondo la classificazione di Chomsky.
2. Fornire una grammatica generatrice.
3. Fornire un automa che lo riconosca.

---

1. $L_2$ è un linguaggio di tipo 2, è generato da una grammatica non contestuale e riconosciuto da un automa a pila.

2. $$G_{L_2}=\langle \{\},\{\},S,P\rangle$$
con produzioni:
- $S\to fSd|fAd$
- $A\to fA|fB$
- $B\to fB|eB|C$
- $C\to dC|dD$
- $D\to bD|eD|\varepsilon$

---

$L_2$ è un linguaggio di tipo 2, quindi è generato da una grammatica non contestuale ed è riconosciuto da un automa a pila.

## ES.3

Data la seguente formula della logica proposizionale

$$(\neg x \implies y)\lor\neg(((\neg x\land y)\lor(z\implies y)) \land (\neg y \implies x))$$

verificare, mediante il metodo dei tableaux **e** mediante il metodo delle tabelle di verità, se è soddisfacibile, tautologica o contraddittoria. Nel caso in cui sia soddisfacibile fornire almeno un modello.
