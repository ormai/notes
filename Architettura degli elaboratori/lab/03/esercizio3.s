
        .section .rodata
fmt: 
        .asciz "%d\n"

        .macro print n      // Dichiarazione macro
            adr x0, fmt
            mov w1, \n
            bl printf
        .endm               // Dichiarazione macro

        .text
        .type main, %function
        .global main
main:
        stp x29, x30, [sp, #-16]!
        print 15

        mov w0, #0
        ldp x29, x30, [sp], #16
        ret
        .size main, (. - main)

