.section .rodata
fmt: .asciz "%d\n" //fomattazione per stampare numeri a 32 bit

.text
.type main, %function
.global main
main:
    stp x29, x30, [sp, #-16]!
    stp x20, x21, [sp, #-16]!

    mov w20, #20 // w20 = 20 
    mov w21, #10 // w21 = 10

    cmp w20, w21 // w20 - 21; N = 0 and Z = 0
    csel w1, w20, w21, lt // w1 = 10
    // print w1
    adr x0, fmt
    bl printf

    sub w20, w20, w21 // w20 = 10
    cmp w20, w21
    cset w1, eq // w1 = 1
    adr x0, fmt
    bl printf

    mov w0, #0
    ldp x20, x21, [sp], #16
    ldp x29, x30, [sp], #16
    ret
    .size main, (. - main)
