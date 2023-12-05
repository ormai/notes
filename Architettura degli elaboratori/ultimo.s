            .section    .rodata
fmtPrint:   .string     "%s\n"
fmtScan:    .string     "%s"


            .bss
stringa:    .skip       1001                    // 100 caratteri più un 0x00

            .text
            .type       main, %function
            .global     main
main:
            stp         x29, x30, [sp, #-16]!

            // Leggi la stringa
            ldr         x0, =fmtScan
            ldr         x1, =stringa
            bl          scanf

            ldr         x0, =stringa
            mov         w1, wzr                 // indice

loop:       ldrb        w2, [x0]                // carica carattere

            cmp         w2, wzr                 // se il carattere è 0x00
            beq         endLoop                 // termina il loop

ifIsT:      cmp         w2, #116                // se il carattere è `t`
            bne         elifIsO

            mov         w3, #84
            strb        w3, [x0]                // scambia con `T`
            b           repeat

elifIsO:    cmp         w2, #111                // se il carattere è `o`
            bne         elifIsF

            mov         w3, #79
            strb        w3, [x0]
            b           repeat

elifIsF:    cmp         w2, #102                // se il carattere è `f`
            bne         elifIsQ

            mov         w3, #70
            strb        w3, [x0]                // scambia con `F`
            b           repeat

elifIsQ:    cmp         w2, #113                // se il carattere è `q`
            bne         repeat

            mov         w3, #81
            strb        w3, [x0]                // scambia con `Q`

repeat:     add         w1, w1, #1
            add         x0, x0, #1              // prossimo byte
            b           loop

endLoop:    ldr         x0, =fmtPrint            // stampa la stringa
            ldr         x1, =stringa
            bl          printf

            mov         w0, #0
            ldp         x29, x30, [sp], #16
            ret
            .size        main, (. - main)
