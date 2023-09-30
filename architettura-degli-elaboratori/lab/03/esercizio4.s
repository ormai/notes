.section .rodata
fmt:
    .asciz "N = %d\tZ = %d\tC = %d\tV = %d\tn = %d\n"

.data
n:
    .byte 0b11001000


.macro print
    adr x0, fmt // n
    cset w1, mi // 
    cset w2, eq
    cset w3, cs
    cset w4, vs
    ldr w5, n
    bl printf
.endm

.macro add_to_n value
    ldr x8, =n
    ldrb w9, [x8]
    .if \value >= 0
        adds w9, w9, #\value
    .else
        subs w9, w9, #-\value
    .endif
    strb w9, [x8]
.endm

.text
.type main, %function
.global main
main:
    stp x29, x30, [sp, #-16]!

    add_to_n 0xFFF1
    print

    // return 0
    mov w0, #0
    ldp x29, x30, [sp], #16
    ret
    .size main, (. - main)

