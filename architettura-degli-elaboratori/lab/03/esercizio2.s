.section .rodata
fmt: 
    .asciz "%d\n"

.equ CONSTANT, 10

.macro print n
    adr x0, fmt
    mov w1, \n
    bl printf
.endm

.text
.type main, %function
.global main

main:
    stp x29, x30, [sp, #-16]!

    .ifndef CONSTANT // se CONSTANT è definito
        print 1
    .else
        print 0
    .endif

    // return 0
    mov w0, #0
    ldp x29, x30, [sp], #16
    ret
    .size main, (. - main)

