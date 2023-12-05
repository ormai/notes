            .section    .rodata
fmt_read:   .asciz      "Inserisci un numero positivo: "
fmt_scan:   .asciz      "%d"
fmt:        .asciz      "%d\n"
            .align      2

            .data
n:          .word       0

            .macro      scan fmt var
            adr         x0, \fmt
            bl          printf

            adr         x0, fmt_scan
            ldr         x1, =\var
            bl          scanf
            .endm

            .text
            .type       main, %function
            .global     main
main:
            stp         x29, x30, [sp, #-16]!
            stp         x19, x20, [sp, #-16]! // salva registri persistenti

            // leggi e carica n
            scan        fmt_read n
            ldr         w19, n

            mov         w20, #2 // inizializza w20 a 2

main_loop:  cmp         w19, w20 // se (n < i) termina il loop
            blt        main_endl

            mov         w0, w20 // argomento per la funzione primo
            bl          primo   // primo(n);

            cmp         w0, wzr // se primo restituisce zero allora non stampare
            beq         dontprint
print:
            mov         w1, w0
            adr         x0, fmt
            bl          printf

dontprint:

            add         w20, w20, #1 // w20++
            b           main_loop

main_endl:

            ldp         x19, x20, [sp], #16
            ldp         x29, x30, [sp], #16
            ret
            .size       main, (. - main)

            .type       primo, %function
primo:      stp         x29, x30, [sp, #-16]!
            /* primo è una funzione che richiede un numero intero in w0
               e restituisce lo stesso numero se è primo, altrimenti 0 */

            // per verificare che n sia primo bisogna verificare che sia
            // divisibile per ogni intero i in [2, n-1]

            cmp         w0, #1 // 1 non è primo
            beq         no

            mov         w1, #2 // int i = 2;
loop:
            cmp         w0, w1 // se (n == i) n è primo, quindi termina il loop
            beq         endloop

            // calcola il resto della divisione tra w0 e w1
            udiv        w2, w0, w1     // w2 = w0 // w1
            msub        w3, w2, w1, w0 // w3 = w0 (w2 * w1)
            cmp         w3, wzr // se il resto in w3 è diverso da zero
            beq         no      // allora w0 non è primo

            add         w1, w1, #1 // incrementa w1
            b           loop // ripeti

no:         mov         w0, wzr // w0 non è primo, restituisci 0

endloop:
            ldp         x29, x30, [sp], #16
            ret
            .size       primo, (. - primo)
