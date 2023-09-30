.section .rodata
fmt: .asciz "%d\n"
.align 2

.data
A: .word 1, 5, 4, 12
B: .word -4, 5, 10, 6

.macro print i
    adr x0, fmt
    ldr x2, =A
    ldr w1, [x2, #\i * 4]
    bl printf
.endm

.text
.type main, %function
.global main
main:
    stp x29, x30, [sp, #-16]!

    ldr x1, =A
    ldr x2, =B
    ldr w3, [x1, #12]!
    ldr w4, [x2, #12]

    cmp w3, w4
    cset w3, gt
    str w3, [x1]

    print 0
    print 1
    print 2
    print 3

    mov w0, #0
    ldp x29, x30, [sp], #16
    ret
    .size main, (. - main)
    
