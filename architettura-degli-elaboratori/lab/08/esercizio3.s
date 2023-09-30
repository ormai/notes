            .section    .rodata
fmt_prompt: .asciz      "Inserisci tre numeri maggiori di 1 (attento che non lo controllo!): "
fmt_scan:   .asciz      "%d"
fmt_si:     .asciz      "SI\n"
fmt_no:     .asciz      "NO\n"

            .data
a:          .word       0
b:          .word       0
c:          .word       0


            .macro      legginumero dest
            adr         x0, fmt_prompt
            bl          printf
            adr         x0, fmt_scan
            adr         x1, \dest
            bl          scanf
            .endm

            .text
            .type       main, %function
            .global     main
main:
            stp         x29, x30, [sp, #-16]!

            //Main da realizzare

            legginumero a
            legginumero b
            legginumero c

            ldr         w0, a
            ldr         w1, c
            bl          divisibili
            cmp         w0,#0
            beq         no

            ldr         w0, b
            ldr         w1, c
            bl          divisibili
            cmp         w0,#0
            beq         no

si:
            adr         x0, fmt_si
            bl          printf
            b           return
no:
            adr         x0,fmt_no
            bl          printf

return:

            mov         w0, #0
            ldp         x29, x30, [sp], #16
            ret
            .size       main, (. - main)


            .type       divisibili, %function
divisibili:
            // args: due interi in w1 e w1
            // se w0 è divisibile per w1 restituisci 1
            // altrimenti restituisci 0

            // controlla se w0 è divisibile per w1
            udiv        w2, w0, w1
            msub        w3, w2, w1, w0
            cmp         w3, wzr

            cset        w0, eq // 'setta' il valore di ritorno

            ret
            .size       divisibili, (. - divisibili)
