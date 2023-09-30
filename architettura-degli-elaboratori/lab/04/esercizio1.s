.section .rodata
fmt_32bit: .asciz "0x%08x\n"
fmt_64bit: .asciz "0x%016llx\n"
.align 2

.data
n: .word 1, 2, 3, 4, 5

.macro print_32
    adr x0, fmt_32bit
    bl printf
.endm

.macro print_64
    adr x0, fmt_64bit
    bl printf
.endm

.text
.type main, %function
.global main
main:
    stp x29, x30, [sp, #-16]!

    ldr x2, =n
    
    //Esempio 1
    //ldr w1, [x2]
    //print_32

    //Esempio 2
    //ldr x1, [x2]
    //print_64

    //Esempio 3
    //ldr w1, [x2, #8]
    //print_32

    //Esempio 4
    //mov x3, #4 // Il registro X3 contiene il valore 4
    //ldr w1, [x2, x3]
    //print_32

    //Esempio 5
    //mov x3, #1 // Il registro X3 contiene il valore 1
    //ldr w1, [x2, x3, lsl #2]
    //print_32

    //Esempio 6
    //ldr w1, [x2, #0xffff]
    //print_32

    //Esempio 7
    //ldr w1, [x2, #12]!
    //print_32

    //Esempio 8
    //ldr x1, [x2], #4
    //print_64
    
    mov w0, #0
    ldp x29, x30, [sp], #16
    ret
    .size main, (. - main)
