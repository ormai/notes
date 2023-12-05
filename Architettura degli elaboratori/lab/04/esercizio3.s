.section .rodata
fmt: .asciz "%x\n"
.align 2

.data
    n: .word 0, 1, 2, 3, 4

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

    //w0 contiene il valore 0
    mov w0, #0
    /* Aggiungere di seguito istruzioni ldr/str oppurtune 
       per risolvere prima il punto a) e poi il punto b) */

    print 0
    print 1
    print 2
    print 3
    print 4

    mov w0, #0
    ldp x29, x30, [sp], #16
    ret
    .size main, (. - main)
