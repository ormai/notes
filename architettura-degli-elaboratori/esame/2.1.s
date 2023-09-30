/*  Completare il codice fornito modificando l'array A in modo che ogni elemento
 *  in posizione i nell'array A sia il risultato della somma tra l'intero in
 *  posizione i nell'array A e l'intero in posizione i nell'array B, ovvero
 *  A[i] = A[i] + B[i].
 *
 *  Caricare il codice completo, assemblabile ed eseguibile senza errori. Non
 *  aggiungere stampe e non modificare quelle già presenti.
 *  Work with your favorite editor and tools, then copy-and-paste your answer
 *  here.
 */

            .section    .rodata
fmt:        .asciz      "%d\n"
            .align      2

            .data
A:          .word       1, 5, -3, 2
B:          .word       -4, 5, 34, 6

            .macro      print i
            adr         x0, fmt
            ldr         x2, =A
            ldr         w1, [x2, #\i * 4]
            bl          printf
            .endm

            .text
            .type       main, %function
            .global     main
main:       stp         x29, x30, [sp, #-16]!

            // Da completare --------------------------------------------------

            mov         w0, #0                  // indice
            ldr         x1, =A
            ldr         x2, =B
loop:
            mov         w3, #4                  // dimensione elementi
            mul         w4, w0, w3              // calcola offset
            ldr         w5, [x1, x4]            // w2 = A[w0]
            ldr         w6, [x2, x4]            // w6 = B[w0]

            // A[w0] = A[w0] + B[w0]
            add         w5, w5, w6
            str         w5, [x1, x4]

            // RIPETI LOOP
            add         w0, w0, #1              // i += 1
            cmp         w0, #4
            blt         loop

            // ----------------------------------------------------------------

            print       0
            print       1
            print       2
            print       3

            mov         w0, #0                  // return 0
            ldp         x29, x30, [sp], #16
            ret
            .size       main, (. - main)
