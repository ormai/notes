            .section    .rodata

fmt:        .asciz      "diff = %d\n"
            .align      2

            .macro      invoca_diff a b
            mov         x0, \a
            mov         x1, \b
            bl          diff

            mov         x1, x0
            adr         x0, fmt
            bl          printf
            .endm

            .text
            .type       main, %function
            .global     main
main:
            stp         x29, x30, [sp, #-16]!

            invoca_diff #10, #20
            invoca_diff #3, #2
            invoca_diff #10, #2

            mov         w0, #0
            ldp         x29, x30, [sp], #16
            ret
            .size       main, (. - main)

            .type diff, %function
            /* la funzione diff richiede come argomenti in x0, x1 due numeri
               interi e restituisce in x0 un numero intero */
diff:
            // Implementare di seguito la funzione diff 

            // in C sarebbe:
            // if (a > b) {
            //      return (a - b);
            // } else {
            //     return (b - a);
            // }

if:         // se (a <= b) salta ad else
            cmp         w0, w1
            ble         else

            // se l'esecuzione arriva qui vuol dire che a è maggiore di b
            sub         w0, w0, w1 // a - b
            b           endif // salto incondizionato a endif

else:
            sub         w0, w1, w0 // b - a
endif:
            ret
            .size       diff, (. - diff)
