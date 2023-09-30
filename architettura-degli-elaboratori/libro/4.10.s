            .section    .rodata
file_name:  .string     "input.txt"
flag:       .string     "O_RDONLY"

            .text
            .type       main, %function
            .global     main
main:
            stp         x29, x30, [sp, #-16]!

            mov         x0, #-100
            adr         x1, file_name
            ldr         x1, [x1]
            adr         x2, flag
            ldr         x2, [x2]
            bl          openat

            mov         w0, #0
            ldp         x29, x30, [sp], #16
            ret
            .size        main, (. - main)
