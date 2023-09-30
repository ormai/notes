            .section    .rodata
a:          .word       10
b:          .word       100
c:          .word       575
d:          .word       123
prompt:     .string     "Type an integer: "
fmt_scan:   .string     "%d"
fmt_result: .string     "%d * %d = %d\n"

            .data
input:      .skip       4

            .macro      read dest
            adr         x0, prompt
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

            read        input

            // w0 = w2 * w3

            adr         x1, input // load the input in x3
            ldr         w1, [x1]

            adr         x2, a
            ldr         w2, [x2] // constant

            mov         w3, #0 // counter
            mov         w0, #0 // result
loop:
            cmp         w2, w3
            beq         endloop

            add         w0, w0, w1
            add         w3, w3, #1
            b           loop

endloop:
            // printf(fmt_result, a, input, w0);
            mov         w3, w0
            adr         x0, fmt_result
            bl          printf

            mov         w0, #0
            ldp         x29, x30, [sp], #16
            ret
            .size        main, (. - main)
