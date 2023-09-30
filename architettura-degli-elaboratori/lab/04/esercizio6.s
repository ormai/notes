.section .rodata
true_str: .asciz "true\n"
false_str: .asciz "false\n"

.text
.type main, %function
.global main
main:
    stp x29, x30, [sp, #-16]!

    mov x0, #0
    mov x1, #1
    /*
        La seguente istruzione tst effettua un AND bit a bit tra 
        il contenuto del registro x0 e il contenuto del registro x1 
        impostando in base al risultato ottenuto i flag N e Z.
     */
    tst x0, x1
    beq true_case

    false_case:
        adr x0, false_str
        bl printf
        b endif
    true_case:
        adr x0, true_str
        bl printf
    endif:

    // return 0
    mov w0, #0
    ldp x29, x30, [sp], #16
    ret
    .size main, (. - main)
