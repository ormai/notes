            .section    .rodata4.4.s
fmt_result: .string     "%d\n"
fmt_scan:   .string     "%d"
prompt:     .string     "Type an integer: "
            .align      2

            .data
num1:       .skip       4
num2:       .skip       4
numsum:     .skip       4

            .macro      read d
            adr         x0, prompt
            bl          printf

            adr         x0, fmt_scan
            adr         x1, \d
            bl          scanf
            .endm

            .text
            .type       main, %function
            .global     main
main:
            stp         x29, x30, [sp, #-16]!

            read        num1
            read        num2

            // with ldr for the addresses
            ldr         x0, =num1
            ldr         x0, [x0]
            ldr         x1, =num2
            ldr         x1, [x1]

            add         x0, x0, x1
            ldr         x1, =numsum
            str         x0, [x1]

            ldr         x0, =fmt_result
            ldr         x1, =numsum
            ldr         x1, [x1]
            bl          printf

            // with adr for the addresses
            adr         x0, num1
            ldr         x0, [x0]
            adr         x1, num2
            ldr         x1, [x1]

            add         x0, x0, x1
            adr         x1, numsum
            str         x0, [x1]

            adr         x0, fmt_result
            adr         x1, numsum
            ldr         x1, [x1]
            bl          printf

            mov         w0, #0
            ldp         x29, x30, [sp], #16
            ret
            .size       main, (. - main)
