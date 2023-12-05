// Questo programma è strutturato in funzioni.
// Ogni funzione svolge un punto della traccia (Lab 06, esercizio 5).
// Consiglio di saltare direttamente alla funzione main e poi guardare le altre
// ==> riga 147
            .section    .rodata
fmt:        .string     "Risultato: %d\n"
            .align      2

            .data
A:          .word       13, 4, 5, 4, 1, 0, -3, 10
            .equ        A_size, (. - A)

            .macro      print
            adr         x0, fmt
            bl          printf
            .endm

            .text

            // 1. --- TROVA IL MINIMO DI A ---

            /* trova_min è una funzione che accetta come argomento (in x0)
               l'indirizzo dell'inizio di un array di word.
               Il valore minore vien restituito (in x0). */
            .type       trova_min, %function
            .global     trova_min
trova_min:  stp         x29, x30, [sp, #-16]!  // Salva FP and LR nello Stack

            // variabile per il minimo, inizializzata al primo elemento di A
            ldr         w2, [x0] // int w2 = A[0];
            // indice
            mov         w3, #0   // int w3 = 0;
            // lunghezza dell'array. Non è divisa per 4 così da avere l'offset
            // pronto per iterare poi attraverso A
            ldr         w4, =A_size // int w4 = sizeof(A)
            // notare che si carica direttamente il valore del simbolo

loop_min:  // se l'indice raggiunge la lunghezza dell'array termina il loop
            cmp         w3, w4
            beq         endl_min
            // mettendo il controllo qui si evita di effettuare operazioni
            // sull'array con un indice pari alla sua lunghezza, ciò causerebbe
            // un segmentation fault

            // carica l'intero successivo nell'array usando un offset pari
            // all'indice contenuto in w3
            // Qui il registro w3 viene esteso (uxtw) così da poterne poi
            // sommare il contenuto all'indirizzo contenuto in x0
            // Questo perché non si può fare x0 + w3 :)
            ldr         w6, [x0, w3, uxtw]
            // NB: si poteva anche evitare di usare questa addressing mode e
            // quindi lasciare A_size diviso per quattro. In questo modo si
            // sarebbe usato il post-index immediate offset.
            // Ormai ho fatto così e mi secca cambiare.

            // Assegna a w2 il minore tra w2 e w6
            cmp         w2, w6
            csel        w2, w2, w6, lt

            add         w3, w3, #4 // Incrementa l'indice (i++)
            b           loop_min // ripeti
endl_min:
            mov         w0, w2 // return w2

            ldp         x29, x30, [sp], #16 // Ripristina FP e LR
            ret
            .size       trova_min, (. - trova_min)

            // 2. --- TROVA IL MASSIMO DI A ---

            /* trova_min trova il minimo di un array di word
               Args: indirizzo di un array in x0
               Ret: un numero reale in x0 */
            .type       trova_max, %function
            .global     trova_max
trova_max:  stp         x29, x30, [sp, #-16]!
            ldr         w2, [x0]      // int w2 = A[0];
            mov         w3, #0        // int w3 = 0;
            ldr         w4, =A_size   // int w4 = sizeof(A)

loop_max:   cmp         w3, w4
            beq         endl_max
            ldr         w6, [x0, w3, uxtw]

            // Assegna a w2 il maggiore tra w2 e w6
            cmp         w2, w6
            csel        w2, w2, w6, gt // come per trova_min ma cambia questo

            add         w3, w3, #4     // Incrementa l'indice (i++)
            b           loop_max       // ripeti
endl_max:   mov         w0, w2         // return w2

            ldp         x29, x30, [sp], #16
            ret
            .size       trova_max, (. - trova_max)

            // 3. --- SOMMA DI A ---

            /* somma_arr calcola la somma di un array di word
               Args: indirizzo di un array in x0
               Ret: un numero reale in x0 */
            .type       somma_arr, %function
            .global     somma_arr
somma_arr:  stp         x29, x30, [sp, #-16]!
            ldr         w2, [x0]      // primo elemento dell'array
            mov         w3, #0        // indice
            ldr         w4, =A_size   // lunghezza dell'array
            mov         w5, #0        // somma = 0

loop_sum:   cmp         w3, w4        // se indice == lungheza dell'array
            beq         endl_sum      // esci dal loop

            ldr         w6, [x0, w3, uxtw]

            add         w5, w5, w6    // somma += w6

            add         w3, w3, #4    // Incrementa l'indice (indice += 1)
            b           loop_sum      // ripeti
endl_sum:   mov         w0, w5        // return w5

            ldp         x29, x30, [sp], #16
            ret
            .size       somma_arr, (. - somma_arr)

            // 3. --- MEDIA DI A ---

            /* media_arr calcola la media di un array di word
               Args: indirizzo di un array in x0
               Ret: un numero reale in x0 */
            .type       media_arr, %function
            .global     media_arr
media_arr:  stp         x29, x30, [sp, #-16]!
            // usa somma_arr per la somma
            // in x0 si trova l'indirizzo di A
            bl          somma_arr // la somma finisce in w0
            mov         w1, w0
            ldr         w2, =A_size

            // dividi la lunghezza dell'array per 4, dato che contiene word
            mov         w3, #4
            udiv        w2, w2, w3

            // calcola la media
            sdiv        w0, w1, w2 // w0 = w1 // w2 (//: divisione intera)

            ldp         x29, x30, [sp], #16
            ret
            .size       media_arr, (. - media_arr)

            // --------- INIZIA IL PROGRAMMA --------- 

            .type       main, %function
            .global     main
main:       stp         x29, x30, [sp, #-16]!

            // chiama una funzione tra
            // - trova_min
            // - trova_max
            // - somma_arr
            // - media_arr
            ldr         x0, =A       // preara l'argomento da passare a funzione
            bl          somma_arr    // <-- Cambiare qui

            mov         w1, w0       // copia in w1 il valore restituito dalla funzione
            print                    // stampa w1

            // return 0
            mov         w0, #0
            ldp         x29, x30, [sp], #16
            ret
            .size       main, (. - main)

