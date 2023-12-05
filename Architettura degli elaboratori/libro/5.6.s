
            .section    .rodata
str:        .string     "Hi\n"
            .align      2

            .macro      print
            // print modifica il contenuto di x1
            stp         x0, x1, [sp, #-16]!
            adr         x0, str
            bl          printf
            ldp         x0, x1, [sp], #16
            .endm

            .text
            .type       main, %function
            .global     main
main:       stp         x29, x30, [sp, #-16]!

            mov         w1, #0

loop:       print

            add         w1, w1, #1
            cmp         w1, #10
            blt         loop

            mov         w0, #0
            ldp         x29, x30, [sp], #16
            ret
            .size       main, (. - main)

