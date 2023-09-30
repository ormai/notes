            .section    .rodata
fmt_n:      .asciz      "Insert a non-negative number (negative to terminate): "
fmt_x:      .asciz      "Insert the number X: "
fmt_scan:   .asciz      "%d"
fmt_count:  .asciz      "The count is: %d.\n"
            .align      2

            .bss
n:          .word       0 // elemento della sequenza
x:          .word       0 // numero X

            .macro      scan fmt var //da utilizzare per leggere un numero
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
            // salva x19, x20 (caller saved registers) poiché ci servono due
            // registri persistenti
            stp         x19, x20, [sp, #-16]!
            mov         w19, wzr

            // leggi x e caricalo in w2
            scan        fmt_x, x
            ldr         w20, x

            // pre-test loop
loop:
            // leggi n da input
            scan        fmt_n n
            ldr         w5, n

            // controlla se (n > 0)
            cmp         w5, wzr
            blt         endloop // se non lo è termina il loop

            udiv        w4, w5, w20 // calcola (n // x)
            msub        w3, w4, w20, w5 // calcola il resto (n % x)
            cmp         w3, wzr
            // se il resto è uguale a zero, incrementa il contatore
            cinc        w19, w19, eq
            b           loop // ripeti
endloop:
            // stampa il contatore
            adr         x0, fmt_count
            mov         w1, w19
            bl          printf

            // return 0;
            mov         w0, #0
            ldp         x19, x20, [sp], #16
            ldp         x29, x30, [sp], #16
            ret
            .size       main, (. - main)
