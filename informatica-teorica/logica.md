# Logica proposizionale

 - **connettivi** proposizionali, $\neg$ (not), $\land$ (and), $\lor$ (or), $\implies$ (implica), $\iff$ (se e solo se, doppia implicazione)
 - **costanti** proposizionali, $\top$ (vero), $\bot$ (falso)
 - simboli proposizionali o **atomi** $\{A, B, \ldots, P, Q, \ldots\}$
 - simboli separatori "$($" e "$)$"

> [!info] I connettivi hanno una precedenza:
$$\Huge\neg\quad\prec\quad\land\quad\prec\quad\lor\quad\prec\quad\implies\quad\prec\quad\iff$$
Quando ci sono più connettivi con la stessa precedenza si associa a destra.


Una formula può essere:
- una sola costante o simbolo proposizionale ($A$ è una formula)
- la negazione ($\neg$) deve avere un atomo a destra
- un connettivo binario ($\land,\lor,\implies,\iff$) deve avere un atomo a destra e uno a sinistra

Tutte le componenti di una formula sono **sottoformule**.

---

Un albero sintattico è un albero binario che serve a scomporre una formula proposizionale.

I nodi intermedi sono connettivi, i nodi finali (foglie) sono atomi

Albero sintattico di $(A\iff B) \lor \neg C$:

![](albero-sintattico.excalidraw|600|center)

## Tavole di verità

$$\top=1=\rm vero$$
$$\bot=0=\rm falso$$

| $A$ | $\neg A$ |
| --- |:--------:|
| $0$ |   $1$    |
| $1$ |   $0$    | 

| $A$ | $B$ | $A\land B$ | $A\lor B$ | $A\implies B$ | $A\iff B$ | 
| --- | --- |:----------:|:---------:|:-------------:|:---------:|
| $0$ | $0$ |    $0$     |    $0$    |      $1$      |    $1$    |
| $0$ | $1$ |    $0$     |    $1$    |      $1$      |    $0$    |
| $1$ | $0$ |    $0$     |    $1$    |      $0$      |    $0$    |
| $1$ | $1$ |    $1$     |    $1$    |      $1$      |    $1$    |

Per costruire la tavola di verità di una formula si devono analizzare tutte le sue sottoformule.

Il numero delle righe della tavola di verità è $2^n$ dove $n$ è il numero di simboli proposizionali. ([[2_logica.pdf#page=47|Esempio]])

Usando la tabella di verità per una formula questa è:
- **soddisfacibile** sse l'ultima colonna contiene *almeno una volta* $1$
- **tautologica** sse l'ultima colonna contiene *solo* $1$
- **contraddittoria** sse l'ultima colonna contiene soli $0$

Per verificare che una formula sia tautologica si deve verificare che la sua negazione è una contraddizione (intuitivamente, se la proposizione è vera ad ogni valutazione la sua negazione deve essere falsa ad ogni valutazione).

> [!tip]- Due formule sono _logicamente equivalenti_ sse hanno lo stesso valore per ogni valutazione booleana (stesso valore per ogni riga della tabella)
> Idempotenza:
> $$\alpha\land\alpha\equiv\alpha\qquad\alpha\lor\alpha\equiv\alpha$$
> Associatività:
> $$\alpha\land(\beta\land\gamma)\equiv(\alpha\land\beta)\land\gamma$$
> $$\alpha\lor(\beta\lor\gamma)\equiv(\alpha\lor\beta)\land\gamma$$
> $$\alpha\iff(\beta\iff\gamma)\equiv(\alpha\iff\beta)\iff\gamma$$
> Commutatività:
> $$\alpha\land\beta\equiv\beta\land\alpha$$
> $$\alpha\lor\beta\equiv\beta\lor\alpha$$
> $$\alpha\iff\beta\equiv\beta\iff\alpha$$
> Distributività:
> $$\alpha\land(\beta\lor\gamma)\equiv(\alpha\land\beta)\lor(\alpha\land\gamma)$$
> $$\alpha\lor(\beta\land\gamma)\equiv(\alpha\lor\beta)\land(\alpha\lor\gamma)$$
> Assorbimento:
> $$\alpha\land(\alpha\lor\beta)\equiv\alpha$$
> $$\alpha\lor(\alpha\land\beta)\equiv\alpha$$
> Doppia negazione:
> $$\neg\neg\alpha\equiv\alpha$$
> [[leggi-de-morgan|Leggi di De Morgan]]:
> $$\neg(\alpha\land\beta)\equiv\neg\alpha\lor\neg\beta$$
> $$\neg(\alpha\lor\beta)\equiv\neg\alpha\land\neg\beta$$
> Terzo escluso:
> $$\alpha\lor\neg\alpha\equiv\top$$
> Contrapposizione
> $$\alpha\implies\beta\equiv\neg\beta\implies\neg\alpha$$
> $$\alpha\land\neg\alpha\equiv\bot$$

> [!tip]- Riduzione di connettivi
> $$A\land B\equiv\neg(\neg A\lor\neg B)$$
> $$A\implies B\equiv\neg A\lor B\qquad A\lor B\equiv\neg A\implies B$$
> $$A\lor B\equiv\neg(\neg A\land\neg B)\qquad A\land B\equiv\neg(\neg A\lor\neg B)$$
> $$A\iff B\equiv (A\implies B)\land(B\implies A)$$

## Modelli

Sia $M$ un insieme di simboli proposizionali (detto *interpretazione*) e sia $\alpha$ una formula proposizionale. Si dice che $M$ è un **modello** di $\alpha$ se $\alpha$ è vera in $M$, e si indica

$$M\vDash\alpha\qquad (M\ è\ modello\ di\ \alpha)$$

e vuol dire che $M$ rende vera $A$^[Aiello, Pirri. “Strutture, logica, linguaggi” 5.3.4 Modelli, Pearson, 2005, pp. 125-126.]

---

Nelle tavole di verità si prendono solo le righe che hanno $1$ nell'ultima colonna. I modelli di ciascuna di queste righe contengono i simboli proposizionali che hanno $1$ in corrispondenza di quella riga.

Esempio: $(A\implies B)\land (C\lor A)$

| $A$ | $B$ | $C$ | $A\implies B$ | $C\lor A$ | $(A\implies B)\land (C\lor A)$ |
|:---:|:--- |:---:|:-------------:|:---------:|:------------------------------:|
|  0  | 0   |  0  |       1       |     0     |               0                |
|  0  | 0   |  1  |       1       |     1     |               1                |
|  0  | 1   |  0  |       1       |     0     |               0                |
|  0  | 1   |  1  |       1       |     1     |               1                |
|  1  | 0   |  0  |       0       |     1     |               0                |
|  1  | 0   |  1  |       0       |     1     |               0                |
|  1  | 1   |  0  |       1       |     1     |               1                |
|  1  | 1   |  1  |       1       |     1     |               1                |

I modelli di questa formula sono $\{C\}$, $\{B, C\}$, $\{A, B\}$, $\{A,B,C\}$

## Tableaux

Permettono di verificare se una proposizione è soddisfacibile tautologica o contraddittoria tramite la costruzione di un albero.

Un tableaux di $\gamma$ (nodo radice) è un **albero binario** in cui i nodi sono sottoformule di $\gamma$. Si cerca un modello, se lo si trova $\gamma$ è soddisfacibile.

Due sottoformule congiunte si trovano sullo stesso ramo una dopo l'altra. Due formule disgiunte creano due rami distinti.

![](Pasted image 20230530155745.png)

Dato che il tableaux si espande solo se la formula si disgiunge o congiunge le formule che usano connettivi binari come $\iff$ e $\implies$ vanno convertite in formule che usano solo $\land$ oppure $\lor$.

In base alla riduzione dei connettivi si ha:
$$A\implies B\equiv\neg A\lor B$$
$$A\iff B \equiv ((A\implies B)\land(B\implies A))\equiv((\neg A\lor B)\land(\neg B\lor A))$$

Un ramo è soddisfacibile se la congiunzione delle formule sui sui suoi è soddisfacibile.
Un tableaux è **soddisfacibile** se almeno uno dei suoi rami è soddisfacibile.

Il ramo di un tableaux è **chiuso** se, per qualche proposizione di $\alpha$, entrambe $\alpha$ e $\neg\alpha$ sono presenti sullo stesso ramo, altrimenti è aperto. Ai rami chiusi si mette **٭**.
Un tableaux è chiuse se tutti i suoi rami sono chiusi.

Ogni ramo aperto rappresenta un insieme di modelli per $\alpha$.

Per ogni ramo del tableaux, quali sono i simboli proposizionali che rendono soddisfacibile il ramo?.

![](talbeaux.png)
