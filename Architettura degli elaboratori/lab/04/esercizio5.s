.section .rodata
fmt: .asciz "%d\n"
.align 2

.data
n: .word 10, 20, 30, 40, 50

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

    print 0
    print 1
    print 2
    print 3
    print 4

    // print the sum using register offset addressing: begin
    mov w1, #0
    ldr x2, =n

    mov x3, #0
    ldr w4, [x2, x3]
    add w1, w1, w4
    
    add x3, x3, #1
    // Modificare la seguente istruzione ldr per caricare in w4 l'elemento in posizione 1 nell'array n
    // ldr w4, [x2, x3]
    add w1, w1, w4
    
    add x3, x3, #1
    // Modificare la seguente istruzione ldr per caricare in w4 l'elemento in posizione 2 nell'array n
    // ldr w4, [x2, x3]
    add w1, w1, w4
    
    add x3, x3, #1
    // Modificare la seguente istruzione ldr per caricare in w4 l'elemento in posizione 3 nell'array n
    // ldr w4, [x2, x3]
    add w1, w1, w4
    
    add x3, x3, #1
    // Modificare la seguente istruzione ldr per caricare in w4 l'elemento in posizione 4 nell'array n
    // ldr w4, [x2, x3]
    add w1, w1, w4

    adr x0, fmt
    bl printf
    // print the sum using register offset addressing: end
    
    mov w0, #0
    ldp x29, x30, [sp], #16
    ret
    .size main, (. - main)
