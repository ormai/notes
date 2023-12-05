.section .rodata
fmt: .asciz "%d\n"
.align 2

.data
x: .word 43
n: .word 3, 13, 23, 33

.macro print i
    adr x0, fmt
    ldr x2, =n
    ldr w1, [x2, #\i * 4]
    bl printf
.endm

.text
.type main, %function
.global main
main:
    stp x29, x30, [sp, #-16]!

    /* Aggiungere di seguito istruzioni ldr/str oppurtune 
       per risolvere prima il punto a) poi il punto b) e poi il punto c) */

    print 0
    print 1
    print 2
    print 3

    mov w0, #0
    ldp x29, x30, [sp], #16
    ret
    .size main, (. - main)
    