            .section    .rodata
fmt_result: .string     "Greatest: %d\n"
prompt:     .string     "Type an integer: "
fmt_scan:   .string     "%d"
            .align      2

            .data
num1:       .skip       4
num2:       .skip       4

            // read an integer from input and put it in label
            .macro      read label 
            adr         x0, prompt
            bl          printf
            adr         x0, fmt_scan
            adr         x1, \label
            bl          scanf
            .endm

            .text
            .type       main, %function
            .global     main
main:
            stp         x29, x30, [sp, #-16]!

            read        num1
            read        num2

            adr         x4, num1
            ldr         w2, [x4]
            adr         x5, num2
            ldr         w3, [x5]

            cmp         w2, w3
            csel        w1, w2, w3, ge

            // print w1
            adr         x0, fmt_result
            bl          printf

            mov         w0, #0
            ldp         x29, x30, [sp], #16
            ret
            .size        main, (. - main)
