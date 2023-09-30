.section .rodata
fmt: .asciz "%d\n"

.data
A: .byte 0b00100011, 0b00011011, 0b00001001, 0b11111111
B: .byte 0b00101011, 0b10010011, 0b00000001, 0b10000001

.macro print i
    adr x0, fmt
    ldr x2, =A
    ldrsb w1, [x2, #\i * 1]
    bl printf
.endm

        .text
        .type main, %function
        .global main
main:
    stp x29, x30, [sp, #-16]!

    //da completare
    ldr x1, =A
    ldr x2, =B
    ldrsb w3, [x1, #3]!
    ldrsb w4, [x2, #3]!

    // cmp w3, w4 // w3 - w4
    // csinc w3, w3, w4, lt // if (w3 < w4) { w3 = w3; } else { w3 = w4 + 1; }

    // cmp w4, w3
    // csinc w3, w3, w4, gt

    // cmp w3, w4
    // cinc w3, w4, gt

    // strb w3, [x1]

    and w5, w3, w4

    // abs
    tst w5, 0x80
    csneg w2, w5, w5, eq
    strb w2, [x1]

    print 0
    print 1
    print 2
    print 3

    mov w0, #0
    ldp x29, x30, [sp], #16
    ret
    .size main, (. - main)
