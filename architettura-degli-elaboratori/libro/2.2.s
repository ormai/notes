            .section    .rodata
fmtInt:     .asciz      "%d"
frmPrint:   .asciz      "%u\n"
            .align      2

            .data
n:          .word       0           // numero letto volta per volta

            .macro      read dest
            // Legge un intero da input e lo salva all'etichetta `dest`
            adr         x0, fmtInt
            adr         x1, \dest
            bl          scanf
            .endm

            .text
            .type       main, %function
            .global     main
main:       stp         x29, x30, [sp, #-16]!
            stp         x19, x20, [sp, #-16]!

            // --------------------------------------------------
            mov         w19, wzr

loop:       read        n           // leggi n da input
            ldr         w0, n       // carica n in w1

            cmp         w0, #-913
            beq         endLoop

            // ----- CORPO -----

            cmp         w0, #42
            bge         loop

            cmp         w0, w19
            ble         loop

            mov         w19, w0

            b           loop

endLoop:    mov         w1, w19
            adr         x0, frmPrint
            bl          printf

return:     mov         w0, wzr                 // return 0
            ldp         x19, x20, [sp], #16
            ldp         x29, x30, [sp], #16
            ret                                 // Termina la funzione.
            .size       main, (. - main)
