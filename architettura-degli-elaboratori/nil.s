            .section    .rodata
fmt_leggi: .asciz       "%d"
fmt_print:  .asciz      "%u\n"
            .align      2

            .data
n:          .word       0

            .text
            .type       main, %function
            .global     main
main:       stp         x29, x30, [sp, #-16]!
            stp         x19, x20, [sp, #-16]!

            mov         w19, wzr

loop:      
            adr         x0, fmt_leggi
            adr         x1, n
            bl          scanf

            ldr         w0, n

            cmp         w0, #-913
            beq         endLoop

            cmp         w0, #42
            bge         loop

            cmp         w0, w19
            ble         loop

            mov         w19, w0

            b           loop

endLoop:    mov         w1, w19
            adr         x0, fmt_print
            bl          printf

fine:       mov         w0, wzr
            ldp         x19, x20, [sp], #16
            ldp         x29, x30, [sp], #16
            ret
            .size       main, (. - main)
