            .section    .rodata
scanInt:    .asciz      "%d"
fmtInt:     .asciz      "%d\n"
            .align      2

            .data
n:          .word       0           // numero letto volta per volta

            .macro      read dest
            // Legge un intero da input e lo salva all'etichetta `dest`
            adr         x0, fmtInt
            adr         x1, \dest
            bl          scanf
            .endm

            .macro      printInt
            // Stampa l'intero contenuto in w0
            mov         w1, w0
            adr         x0, fmtInt
            bl          printf
            .endm

            .text
            .type       main, %function
            .global     main
main:       stp         x29, x30, [sp, #-16]!
            stp         x19, x20, [sp, #-16]!

            // --------------------------------------------------
            mov         w19, wzr    // contatore
            mov         w20, wzr    // somma

loop:       read        n           // leggi n da input
            ldr         w0, n       // carica n in w1

            // ----- CORPO -----


            // RIPETI LOOP, se il n non è negativo
            add         w19, w19, #1            // Incrementa il contatore.
            cmp         w0, wzr                 // Controlla che (n >= 0), così
            bge         loop                    // da ripetere il loop.

return:     mov         w0, wzr                 // return 0
            ldp         x19, x20, [sp], #16
            ldp         x29, x30, [sp], #16
            ret                                 // Termina la funzione.
            .size       main, (. - main)
