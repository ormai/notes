            .section    .rodata
fmt_div:    .asciz      "Il numero %d e' divisibile per %d, il resto e' %d\n"
fmt_no_div: .asciz      "Il numero %d non e' divisibile per %d, il resto e' %d\n"
            .align      2

a:          .word       12
b:          .word       4

            .text
            .type       main, %function
            .global     main
main:       stp         x29, x30, [sp, #-16]!

            // carica a e b dalla memoria
            ldr         w1, a
            ldr         w2, b

            // calcola il resto di (a // b) a partire dal loro quoziente
            udiv        w4, w1, w2
            msub        w3, w4, w2, w1

            // se il resto è zero i due numeri sono divisibili
            cmp         w3, #0
            bgt         no
            adr         x0, fmt_div
            bl          printf
            b           endif

            // esempio. Verificare che 13 e 4 sono divisibili
            // udiv: w4 = (13 // 4) == 3
            // msub: w3 = (13 - (3 * 4)) = 1 <-- resto

no:
            adr         x0, fmt_no_div
            bl          printf

endif:      mov         w0, #0
            ldp         x29, x30, [sp], #16
            ret
            .size       main, (. - main)
