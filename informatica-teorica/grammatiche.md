# Grammatiche

Le grammatiche servono a generare linguaggi.

Una grammatica formale $G$ è una **quadrupla** $\langle V_T, V_N, S, P\rangle$.

1. $V_T$ è l'**alfabeto terminale**, cioè $\Sigma$
2. $V_N$ è l'**alfabeto non terminale**
3. $S$ è il simbolo iniziale o assioma
4. $P$ è l'insieme finito delle **regole di produzione**

Una regola di produzione è del tipo $S\to aSb$, la $S$ è sostituita da $aSb$.

L'alfabeto terminale non conterrà $S$, oppure $A, B, C, \ldots$. L'alfabeto terminale contiene solo simboli terminali, $a, b, c, \ldots, t, \ldots, p, \ldots$.