# Problemi decisionali

La ricerca operativa si occupa di risolvere **problemi decisionali**.

Un problema decisionale è un problema in cui uno o più *decisori* si trovano a dover scegliere fra diverse alternative, rispetto a determinati *obiettivi*. Le scelte devono tener conto delle risorse limitate (vincoli del problema).

I problemi decisionali si classificano in base al numero di decisori e obiettivi.
Un tipo di problema decisionale sono i **problemi di ottimizzazione**, che hanno come obiettivo massimizzare (profitti, ricavi, ...) o minimizzare (costi, tempi, ...) qualcosa.

## Problemi di ottimizzazione con un solo decisore e un solo obiettivo

1. studio del problema reale
    - obiettivo
    - risorse disponibili
    - dati disponibili
2. costruzione di un modello matematico del problema
    - orizzonte temporale (giornaliero, settimanale, ...)
    - le decisioni sono espresse in forma di **variabili decisionali** ($x_a$, $x_b$, ...)
    - funzione-obiettivo
    - vincoli (eliminano soluzioni non ammissibili)
4. studio del modello
    - costruzione di un algoritmo risolutivo
    - implementazione dell'algoritmo
    - determinazione di *una* soluzione ottima (la migliore soluzione possibile tra le alternative, rispetto all'obiettivo)

I valori delle variabili decisionali che risolvono un modello costituiscono una soluzione ottima e si indicano con $x_a^*$, $x_b^*$, ...
