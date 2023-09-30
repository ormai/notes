            .section    .rodata
fmt:        .string     "Max is: %d\n"
prompt:     .string     "Type an integer: "
fmt_scan:   .string     "%d"

            .data
a:          .word       0
b:          .word       0

            .macro      read dest
            adr         x0, prompt
            bl          printf
            adr         x0, fmt_scan
            adr         x1, \dest
            bl          scanf
            .endm

            .text
            .type       max, %function
            .global     max
max:        stp         x29, x30, [sp, #-16]!

if:         cmp         w0, w1 // if (w0 > w1) { do_nothing(); }
            bgt         endif
            mov         w0, w1
endif:
            ldp         x29, x30, [sp], #16
            ret
            .size        max, (. - max)

            .type       main, %function
            .global     main
main:       stp         x29, x30, [sp, #-16]!

            read        a
            read        b

            adr         x0, a
            adr         x1, b
            ldr         x0, [x0]
            ldr         x1, [x1]

            bl          max
            mov         w1, w0
            adr         x0, fmt
            bl          printf

            mov         w0, #0
            ldp         x29, x30, [sp], #16
            ret
            .size        main, (. - main)
