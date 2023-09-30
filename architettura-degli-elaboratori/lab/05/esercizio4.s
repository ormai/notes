        .section .rodata
fmt:    .asciz  "%d\n"
        .align  2

        .data
A:      .word   0, 1, 2, 3

        .macro print i
        adr     x0, fmt
        ldr     x2, =A
        ldr     w1, [x2, #\i * 4]
        bl      printf
        .endm

        .text
        .type   main, %function
        .global main
main:
        stp     x29, x30, [sp, #-16]!
    
        adr     x3, A
        ldp     w4, w5, [x3]
        ldp     w6, w7, [x3, #8]
        eor     w9, w4, w5
        eor     w9, w9, w6
        eor     w9, w9, w7
        str     w9, [x3]
        // se si usasse l'or inclusivo si avrebbe
        // A = [3, 1, 2, 3]

        print 0
        print 1
        print 2
        print 3


        mov     w0, #0
        ldp     x29, x30, [sp], #16
        ret
        .size   main, (. - main)
