            .section    .rodata
pmt_arr_1:  .string     "arr_1[%d]: "
pmt_arr_2:  .string     "arr_2[%d]: "
pmt_length: .string     "Scrivi la lunghezza degli array: "
fmt_result: .string     "La somma degli elementi dei due array è %d\n"
scan_int:   .string     "%d"
            .align      2

            .text

            // ----- MAIN ---- / 

            .type       main, %function
            .global     main

            // anche la lunghezza degli array è una variabile automatica
main:
            stp         x29, x30, [sp, #-16]!
            stp         x19, x20, [sp, #-16]!
            stp         x21, x22, [sp, #-16]!

            // x19 è usato per indici
            // x20 contiene la dimensione allineata dell'array
            // x21 contiene la lunghezza degli array
            // x22 contiene il doppio di x21

            // leggi la lugnezza degli array da input e salvala nello stack
            sub         sp, sp, #16 // alloca 16 byte

            adr         x0, pmt_length
            bl          printf

            mov         x1, sp
            adr         x0, scan_int
            bl          scanf

            ldr         w21, [sp]

            add         sp, sp, #16 // dealloca 16 byte dallo stack

            // calcola quanti byte allocare
            mov         w0, w21, lsl #2 // res = size * 4
            add         w0, w0, #15 // res += 15 ~ 0b00001111
            and         w20, w0, #0xFFFFFFFFFFFFFFF0

            sub         sp, sp, w20

            // w2 = (w21 * 2) perché gli array sono 2
            mov         w2, #2
            mul         w22, w21, w2

            // ---- leggi gli array uno dopo l'altro

            mov         w19, wzr // int i = 0;
read_loop:
            cmp         w19, w22
            beq         end_read_l

            // seleziona quale dei due prompt
if:         cmp         w19, w21
            bge         else

            adr         x0, pmt_arr_1
            mov         w1, w19
            b           endif
else:
            adr         x0, pmt_arr_2
            sub         w2, w19, w21
            mov         w1, w2
endif:
            // stampa
            bl          printf

            // leggi l'intero e salvalo
            adr         x0, scan_int
            add         x1, sp, w19, lsl #2 // x1 = (sp + (i * 4))
            bl          scanf

            add         w19, w19, #1
            b           read_loop
end_read_l:

            // ---- somma gli elementi dei due array

            mov         w19, wzr
            mov         w0, wzr // somma = 0
sum_loop:   cmp         w19, w22
            beq         end_sum_l

            ldr         w1, [sp, x19, lsl #2] // carica gli elementi dallo stack
            add         w0, w0, w1 // aggiungi w1 alla somma

            add         w19, w19, #1
            b           sum_loop
end_sum_l:

            // stampa il risultato
            mov         w1, w0
            adr         x0, fmt_result
            bl          printf

            // libera lo stack
            add         sp, sp, w20

            // return 0
            mov         w0, wzr
            ldp         x21, x22, [sp], #16
            ldp         x19, x20, [sp], #16
            ldp         x29, x30, [sp], #16
            ret
            .size        main, (. - main)
