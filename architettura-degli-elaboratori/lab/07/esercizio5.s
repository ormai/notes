            .section    .rodata
fmt_x:      .asciz      "Inserisci un numero: "
fmt_scan:   .asciz      "%d"
fmt_pari:   .asciz      "PARI\n"
fmt_dispari: .asciz     "DISPARI\n"
            .align      2

            .bss
x:          .word       0

            .macro      print fmt
            adr         x0, \fmt
            bl          printf
            .endm

            .macro      scan fmt var
            adr         x0, \fmt
            bl          printf

            adr         x0, fmt_scan
            ldr         x1, =\var
            bl          scanf
            .endm

            .text
            .type       main, %function
            .global     main
main:       stp x29, x30, [sp, #-16]!

            scan        fmt_x, x //x contiene il numero letto da input


            //Da continuare a partire da qui


            // fatto con csel
            ldr         w1, x
            adr         x2, fmt_pari
            adr         x3, fmt_dispari

            cmp         w1, #1
            csel        x0, x2, x3, eq
            bl          printf

            // fatto con etichette e salti
// if:         tst         w1, 1
//             beq         else
//
//             print       fmt_dispari
//             b           endif
// else:
//             print       fmt_pari
//
// endif:
            mov         w0, #0
            ldp         x29, x30, [sp], #16
            ret
            .size       main, (. - main)
