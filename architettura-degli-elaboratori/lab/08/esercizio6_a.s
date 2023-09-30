            .section    .rodata
pmt_arr_1:  .string     "arr_1[%d]: "
pmt_arr_2:  .string     "arr_2[%d]: "
fmt_result: .string     "La somma degli elementi dei due array è %d\n"
scan_int:   .string     "%d"
            .align      2

            .equ        size, 5

            .text

            // ----- MAIN ---- / 

            .type       main, %function
            .global     main

            // una variabile automatica esiste solo al momento dell'esecuzione
            // nello stack
main:
            stp         x29, x30, [sp, #-16]!
            stp         x19, x20, [sp, #-16]!

            // x19 è usato per indici
            // x20 contiene la somma

            sub         sp, sp, #48 // alloca 48 byte nello stack

            // ---- leggi gli array uno dopo l'altro

            mov         w19, wzr // int i = 0;
read_loop:  
            cmp         w19, (size * 2)
            beq         end_read_l

            // seleziona quale dei due prompt
if:         cmp         w19, size
            bge         else

            adr         x0, pmt_arr_1
            mov         w1, w19
            b           endif
else:
            adr         x0, pmt_arr_2
            sub         w2, w19, size
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
            mov         w20, wzr // somma = 0
sum_loop:   cmp         w19, (size * 2)
            beq         end_sum_l

            ldr         w1, [sp, x19, lsl #2] // carica gli elementi dallo stack
            add         w20, w20, w1 // aggiungi w1 alla somma

            add         w19, w19, #1
            b           sum_loop
end_sum_l:

            add         sp, sp, #48 // libera 48 byte nello stack

            // stampa il risultato
            mov         w1, w20
            adr         x0, fmt_result
            bl          printf

            // return 0
            mov         w0, #0
            ldp         x19, x20, [sp], #16
            ldp         x29, x30, [sp], #16
            ret
            .size        main, (. - main)
