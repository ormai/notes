.section .rodata
fmt: .asciz "%d\n" //fomattazione per stampare numeri a 32 bit
fmt_long: .asciz "%ld\n" //fomattazione per stampare numeri "long" ovvero a 64 bit 

.macro print_x20
    adr x0, fmt_long
    mov x1, x20
    bl printf
.endm

.macro print_w21
    adr x0, fmt_long
    mov w1, w21
    bl printf
.endm

.macro print_x22
    adr x0, fmt_long
    mov x1, x22
    bl printf
.endm


.text
.type main, %function
.global main
main:
    stp x29, x30, [sp, #-16]!
    stp x20, x21, [sp, #-16]!
    str x22, [sp, #-16]!

    mov x20, #5 
    print_x20 // x20 = 5

    ror w21, w20, #2
    // 00000000 00000000 00000000 00000101
    // 01000000 00000000 00000000 00000100

    print_x20 // x20 = 5
    print_w21 // w21 = 1073741825 

    umnegl x22, w20, w21
    print_x20 // x20 = 5
    print_w21 // w21 = 1073741825 
    print_x22 // x22 = -5368709125

    neg x20, x20
    print_x20 // x20 = -5
    print_w21 // w21 = 1073741825 
    print_x22 // x22 = -5368709125
    
    sdiv x22, x22, x20 
    print_x20 // x20 = -5
    print_w21 // w21 = 1073741825
    print_x22 // x22 = 1073741825

    mov w0, #0
    ldr x22, [sp], #16
    ldp x20, x21, [sp], #16
    ldp x29, x30, [sp], #16
    ret
    .size main, (. - main)

