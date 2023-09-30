            .section    .rodata
fmt_saldo:  .asciz      "SALDO: %d\n"
tmp:        .string     "%d\n"
            .align      2

            .data
saldo:      .word       500
canone:     .word       5
interesse:  .word       2

            .macro      print
            adr         x0, fmt_saldo
            ldr         w1, saldo
            bl          printf
            .endm

            .text
            .type       main, %function
            .global     main
main:       stp         x29, x30, [sp, #-16]!

            // da completare

            // mese uno
            ldr         w1, saldo
            ldr         w2, canone
            ldr         w3, interesse

            // secondo mese

            // si parte da x1 = 500, x2 = 5, x3 = 2
            sub         w1, w1, w2  // x1 = 500 - 5 = 495
            // mov         x4, #(2/100)      // x4 = 2
            mov         w5, #100    // x5 = 100
            mul         w4, w1, w3  // x0 = 495 * 2 = 990
            udiv        w4, w4, w5  // x0 = 495 * 2 // 100 = 9.9
            add         w1, w1, w4
            ldr         x6, =saldo
            str         w1, [x6]

            sub         w1, w1, w2  // x1 = 500 - 5 = 495
            // mov         x4, #(2/100)      // x4 = 2
            mov         w5, #100    // x5 = 100
            mul         w4, w1, w3  // x0 = 495 * 2 = 990
            udiv        w4, w4, w5  // x0 = 495 * 2 // 100 = 9.9
            add         w1, w1, w4
            ldr         x6, =saldo
            str         w1, [x6]
            // adr         x0, tmp
            // bl          printf
            print

            mov         w0, #0
            ldp         x29, x30, [sp], #16
            ret
            .size       main, (. - main)

