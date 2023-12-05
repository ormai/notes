# Supponendo che la bolletta del telefono venga calcolata nel seguente modo:
# - Un valore fisso di 5€ per le prime 80 Chiamate;
# - 0.10€ per ciascuna delle 60 Chiamate successive;
# - 0.07€ per ciascuna delle ulteriori 50 Chiamate (oltre le 140 fino alle 190);
# - 0.05€ per ciascuna delle ulteriori Chiamate (oltre le 190).

# Scrivere un programma che, letto da input il numero di Chiamate effettuate,
# visualizzi l'importo da pagare arrotondato a tre cifre decimali (si usi a tal
# proposito, la funzione round). 

# ATTENZIONE: Si noti che affinché il programma possa essere gestito dal
# valutatore automatico, deve essere inviata in stampa solo ed esclusivamente
# il valore dell’importo da pagare, senza andare a capo e senza aggiungere
# spaziature o altre stampe (neppure quelle che possono precedere l’istruzione
# input per comunicare a chi esegue il programma che dati inserire).

Chiamate = int(input())

if Chiamate <= 80:
    print(round(5, 3), end="")
elif Chiamate > 80 and Chiamate <= 140:
    print(round(5 + (Chiamate - 80) * 0.1, 3), end="")
elif Chiamate > 140 and Chiamate <= 190:
    print(round((5 + 60 * 0.1)+((Chiamate - 140) * 0.07), 3), end="")
elif Chiamate > 190:
    print(round((5 + 60 * 0.1 + 50 * 0.07) +
                ((Chiamate - 190) * 0.05), 3), end="")
