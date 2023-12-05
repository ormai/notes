.global main

.section .rodata
mesg1:
    .asciz "********************************\n"
mesg2:
    .asciz "*Architettura degli Elaboratori*\n"

.text
main:
    stp     x29, x30, [sp, #-16]!
    
    /* 
    * load e print mesg1
    * load e print mesg2
    * load e print mesg1
    */
    adr     x0, mesg1
    bl      printf
    adr     x0, mesg2
    bl      printf
    adr     x0, mesg1
    bl      printf

    // return 0
    mov w0, #0
    ldp x29, x30, [sp], #16
    ret
    .size main, (. - main)
