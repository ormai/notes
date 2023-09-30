        .section .rodata

nums:   .word   7, 3, 21, 10

fmt:    .string "%d, %d, %d, %d.\n"

        .macro  print_reg
        adr     x0, fmt
        bl      printf
        .endm

        .text
        .type   main, %function
        .global main
main:   stp     x29, x30, [sp, #-16]!

        adr     x6, nums
        ldp     w1, w2, [x6]
        ldp     w3, w4, [x6, #8]

        print_reg

        ldp     x29, x30, [sp], #16
        mov     x0, #0
        ret
        .size   main, (. - main)
