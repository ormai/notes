            .section    .rodata
fmt_n:      .asciz      "Insert a non-negative number (negative to terminate): "
fmt_scan:   .asciz      "%d"
fmt_count:  .asciz      "The count is: %d.\n"
            .align      2

            .bss
n:          .word       0 // numero corrente della sequenza

            .macro      scan fmt var //da utilizzare per leggere un numero
            adr         x0, \fmt
            bl          printf

            adr         x0, fmt_scan
            ldr         x1, =\var
            bl          scanf
            .endm

            .text
            .type       main, %function
            .global     main
main:
            stp         x29, x30, [sp, #-16]!
            str         x19, [sp, #-16]! // registro persistente

            // da completare
            mov         w19, wzr // inizializza il contatore a zero
loop:       // leggi n da input e caricalo in w5
            scan        fmt_n n
            ldr         w5, n

            // se (n < 0) termina il loop
            cmp         w5, wzr
            blt         endloop // <-- unico punto d'uscita dal loop

            /* Come controllare se un numero è pari o dispari.

            Tutti i numeri interi dispari hanno il bit meno significativo
            impostato ad 1:
            ·  9 = 0b00001001
            · 35 = 0b00100011

            Di conseguenza i numeri pari avranno il bit meno significativo
            impostato a 0:
            · 58 = 0b00111010

            tst è un alias per ands, quindi imposta pstate, e in più non
            salva il risultato

            L'operazione di and tra un qualsiasi numero pari e 1 darà come
            risultato zero e quindi attiverà la flag Z in pstate che può
            essere sfruttata con il condition modifier eq (pag. 59 del libro)

            In questo caso si usa l'opposto di 'eq', ovvero 'ne', per potere
            uscire dal loop quando l'opposto di eq si verifica.
            */

            tst         w5, #1 // and bit-a-bit tra l'intero in w5 e 0b1
            cinc        w19, w19, eq // se il risultato è zero incrementa
            b           loop // quindi incrementa il loop e ripeti

endloop:    // stampa il contatore
            adr         x0, fmt_count
            mov         w1, w19
            bl          printf

            // return 0;
            mov         w0, #0
            ldr         x19, [sp], #16
            ldp         x29, x30, [sp], #16
            ret
            .size       main, (. - main)
