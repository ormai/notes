            .section    .rodata
fmt_n:      .asciz      "Insert a non-negative number (negative to terminate): "
fmt_scan:   .asciz      "%d"
fmt_count:  .asciz      "%d\n"
            .align      2

            .data
n:          .word       0 // numero corrente della sequenza

            .text
            .type       main, %function
            .global     main
main:       stp         x29, x30, [sp, #-16]!
            stp         x19, x20, [sp, #-16]! // registro persistente

            // --------------------------------------------------
            mov         w19, wzr // inizializza il contatore a zero
            mov         w20, wzr // somma

loop:       // leggi intero da input e caricalo in w1
            adr         x0, fmt_scan
            adr         x1, n
            bl          scanf
            ldr         w1, n

            add         w20, w20, w1            // somma += n
            add         w19, w19, #1            // i += 1

            // se il numero letto è maggiore o uguale a zero: ripeti
            cmp         w1, wzr
            bge         loop

            cmp         w19, wzr                // se non sono stati letti
            ble         return                  // numeri: termina

            udiv        w1, w20, w19            // calcola la media
            adr         x0, fmt_count           // stampa
            bl          printf
            // ----------------------------------------------------

            // return 0;
return:     mov         w0, #0
            ldp         x19, x20, [sp], #16
            ldp         x29, x30, [sp], #16
            ret
            .size       main, (. - main)
