.section .rodata
fmt_32bit: .asciz "0x%08x\n"
.align 2

.data
n: .word 1, 2, 3, 4, 5

.macro print i
    adr x0, fmt_32bit
    ldr x2, =n
    ldr w1, [x2, #\i * 4]
    bl printf
.endm

.macro print_all
    print 0
    print 1
    print 2
    print 3
    print 4
.endm

.text
.type main, %function
.global main
main:
    stp x29, x30, [sp, #-16]!

    ldr x2, =n
    // Il registro X3 (64 bit) contiene il valore 
    // ffff ffff ffff ffff in esadecimale
    mov x3, #0xffffffffffffffff
    
    //Esempio 1
    //str x3, [x2]
    //print_all

    //Esempio 2
    //str w3, [x2]
    //print_all

    //Esempio 3
    //str w3, [x2, #4]
    //print_all

    //Esempio 4
    //mov x4, #8 // Il registro X4 contiene il valore 8
    //str x3, [x2, x4]
    //print_all

    //Esempio 5
    //mov x4, #2 // Il registro X4 contiene il valore 2
    //str w3, [x2, x4, lsl #2]
    //print_all

    //Esempio 6
    //str w3, [x2, #16]!
    //print_all

    //Esempio 7
    //str w3, [x2], #4
    //print_all

    //Esempio 8
    //str w3, =n
    //print_all
    
    mov w0, #0
    ldp x29, x30, [sp], #16
    ret
    .size main, (. - main)
