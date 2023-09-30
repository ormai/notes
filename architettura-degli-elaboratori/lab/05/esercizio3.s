
.section .rodata

fmt: .asciz "%d\n"
fmt_pstate: .asciz "N = %d\tZ = %d\tC = %d\tV = %d\n"

.macro print
    adr x0, fmt_pstate
    cset w1, mi
    cset w2, eq
    cset w3, cs
    cset w4, vs
    bl printf
.endm

.macro print_x20
    adr x0, fmt
    mov w1, w20
    bl printf
.endm

.text
.type main, %function
.global main
main:
    stp x29, x30, [sp, #-16]!
    str w20, [sp, #-16]!

    mov w0, #0b00000000 // 75
    mov w1, #0xffffffff // -15

    // punto a)
    //adds x20, x1, x0
    // x2 = 0b01011010 ~ 90_10
    // NZCV = 0, 0, 0, 0
    // punto b) 
    subs w20, w0, w1
    // x2 = 0b00111100 ~ -60_10
    // NZCV = 1, 0, 0, 0
    print
    print_x20

    mov w0, #0
    ldr x20, [sp], #16
    ldp x29, x30, [sp], #16
    ret
    .size main, (. - main)
