            .section    .rodata
fmt_arr:    .asciz      "arr[%d]: "
fmt_sum:    .asciz      "sum = %d\n"
fmt_scan:   .asciz      "%d"
            .align      2

            .equ        n, 3

            .text
            .type       main, %function
            .global     main
main:
            stp         x29, x30, [sp, #-16]!
            str         x19, [sp, #-16]!

            // alloca 16 byte sullo stack, anche se ne servono solo 12
            sub         sp, sp, #16 // int[3];

            mov         w19, wzr // int i = 0;

read_loop:  cmp         w19, n // se (i == n) terminal il loop
            beq         end_read_loop

            // stampa il prompt
            // printf("arr[%d]: ", i);
            adr         x0, fmt_arr
            mov         w1, w19
            bl          printf

            // leggi l'input dell'utente
            adr         x0, fmt_scan
            add         x1, sp, w19, lsl #2 // x1 = (sp + (i * 4))
            bl          scanf

            add         w19, w19, #1 // i++
            b           read_loop
end_read_loop:

            mov         w1, #0
            mov         w19, #0
sum_loop:
            cmp         w19, n
            bge         end_sum_loop

            ldr         w0, [sp, x19, lsl #2]
            add         w1, w1, w0

            add         w19, w19, #1
            b           sum_loop
end_sum_loop:

            // stampa la somma
            adr         x0, fmt_sum
            bl          printf

            // return 0;
            mov         w0, #0
            add         sp, sp, #16 // dealloca 16 byte dallo stack
            ldr         x19, [sp], #16
            ldp         x29, x30, [sp], #16
            ret
            .size       main, (. - main)
