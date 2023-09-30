# Inferenze logiche

Tipi di inferenze logiche: deduzione, induzione, abduzione.

Charles Sander Pierce, filosofo statunitense, ha espresso tre tipi di inferenze logiche in base all'ordine in cui si susseguono: **caso** (ipotesi), **risultato** (o fatto), la **regola** (o legge generale).

Già Aristotele parlava di induzione e deduzione, negli Analitici secondi. Vuole capire come si formano concetti e ragionamenti nella mente umana. Secondo lui si impara per induzione (sillogismo) o per deduzione. La deduzione è collegata a proposizioni universali, mentre l'induzione parte da affermazioni particolare.

## Deduzione

È un inferenza che conduce dall'universale al particolare. Il termine **deduzione** vole dire "condurre da" o "condurre giù", *da fuori a dentro la mente*, o anche *vedere dentro*.

> [!tip] Sacco di fagioli di Pierce:
> Si ha un sacco di fagioli al cui interno ci sono solo fagioli bianchi. Prendendo una manciata di fagioli dal sacchetto questi saranno bianchi. 
> Sapere che tutti i fagioli nel sacco sono bianchi è un **affermazione universale** e porta a sapere che i fagioli della manciata sono anche bianchi (affermazione particolare).

> [!tip] Sillogismo di Aristotele
> premessa universale: tutti gli uomini sono mortali
> conoscenza singolare: Socrate è un uomo
> conoscenza singolare: Socrate è mortale

A partire da alcune premesse porta a conseguenze necessarie.
La deduzione non è ampliativa ma necessaria, non aggiunge niente. 

> [!tip] Sillogismo aristotelico bArbArA [[logica-dei-predicati]] tre affermazioni universali positive
> Premessa maggiore (universale): Tutti gli animali sono mortali
> Premessa minore (universale): Tutti gli uomini sono animali
> Conseguenza (universale): Tutti gli uomini sono mortali

Regole di inferenza proposizionali classiche intuitive (banali):
- Se A allora B, ma A: dunque B (modus ponendo ponens)
- Se A allora B, ma non B: dunque non A (modus tollendo tollens)
- Non insieme A e B, ma A: dunque non B (modus ponendo tollens 1°)
- O A o B, ma A: dunque non B (modus ponendo tollens 2°)
- O A o B, ma non B: dunque A (modus tollendo ponens)

## Induzione

Indurre vuole dire *tirare dentro*, dal particolare all'universale. La regola generale è tratta dal particolare.

Nel caso del sacco di fagioli: 
1. I fagioli sono presi da questo sacchetto,
2. questi fagioli sono bianchi;
3. **tutti i fagioli nel sacchetto sono bianchi**.

A differenza della deduzione, l'induzione non è un'inferenza necessaria, ma soltanto probabile e ampliativa (si aggiunge qualcosa alle premesse).

Esempio di errore induttivo: Tacchino induttivista di Bertrand Russel.

L'[[induzione]] in matematica è in realtà un'inferenza deduttiva, è infatti universale.

Dimostrazione per induzione completa della divisione

Siano $n$ e $m$ due interi con $m>0$ e $n\geq 0$. Esistono due interi $q$ ed $r$ con $0\leq r<m$, tali che $n=m\times q+r$. 

$A(n)=(n=m\cdot q+r$ con $0\leq r<m)$
1. $n=0$, si sceglie $q=0$ ed $r=0$, quindi $n=m·0+0=0$
2. Si deve dimostrare che $A(n)$ è vero sapendo che $A(k)$ è vero per $k=0,\ldots,n-1$

$A(n-m)=(n-m=m\cdot q'+r'$ con $0\leq r' < m)$

$n=m\cdot q' +m + r'$ con $0\leq r < m$
$n=\underbrace{m(q'+1)}_{=q}+\underbrace={r'}_=r$

