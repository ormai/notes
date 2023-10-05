# Geometria convessa

Dati due [vettori](vettore) $x\in\Bbb R^n$ e $y\in\Bbb R^n$ il vettore $$w=\lambda x+(1-\lambda)y,\quad \lambda\in[0,1]$$ è detto **combinazione convessa** di $x$ e $y$ (caso particolare di [combinazione lineare](combinazione-lineare).

---

Un [insieme](insiemi) $E\subseteq\Bbb R^n$  è **convesso** se per ogni coppia di punti $x\in E$ e $y\in E$ il vettore $$w=\lambda x+(1-\lambda) y$$ appartiene ad $E$ per ogni $\lambda\in [0,1]$.

> [!tip] L'[interseizione](intersezione-di-insiemi) di due insiemi convessi è un insieme convesso.

> [!tip] L'[unione](unione-insiemi) di insiemi convessi può non essere un insieme convesso.

---

Dato un insieme convesso $E\subset\Bbb R^n$ un punto $w\in E$ è un **punto estremo** di $E$ se non esiste nessuna coppia di punti $x\in E$ e $y\in E$, con $x\neq y$ tale che $$w=\lambda x + (1-\lambda)y$$ per qualche $\lambda\in\ ]0,1[$.

---

Dati $\alpha\in\Bbb R^n$ e $\beta\in\Bbb R$ con $\alpha\neq 0$. $$H=\{x\in\Bbb R^n:\alpha^Tx=\beta\}$$ è l'**iperpiano** in corrispondenza di $\alpha$ e $\beta$.

> [!tip] Un iperpiano è un insieme convesso.

In corrispondenza di $H$ si possono definire due semispazi $$H^+=\{x\in\Bbb R^n:\alpha^Tx\geq\beta\}$$ e $$ H^-=\{x\in\Bbb R^n:\alpha^Tx\leq\beta\}$$

> [!tip] $H^+$ e $H^-$ sono insiemi convessi

---

Un **poliedro** è l'intersezione di un finito numero di iperpiani e semispazi affini.

Un poliedro è un insieme convesso (essendo l'intersezione di insiemi convessi).

Un **politopo** è un poliedro limitato.
