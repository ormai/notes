            .section    .rodata
fmt_str_dx: .asciz      "|%10s| allineamento a destra\n"
fmt_str_sx: .asciz      "|%-10s| allineamento a sinistra\n"
fmt_int_32_dx: .asciz   "|%10d| allineamento a destra\n"
fmt_int_32_sx: .asciz   "|%-10d| allineamento a sinistra\n"
fmt_int_32_dx_padding: .asciz "|%010d| allineamento a destra con riempimento\n"
fmt_int_64_dx: .asciz   "|%20ld| allineamento a destra\n"
fmt_int_64_sx: .asciz   "|%-20ld| allineamento a sinistra\n"
fmt_int_64_dx_padding: .asciz "|%020ld| allineamento a destra con riempimento\n"
fmt_str:    .ascii      "|%10s| allineamento a destra\n"
            .asciz      "|%-10s| allineamento a sinistra\n"
fmt_int_32: .ascii      "|%10d| allineamento a destra\n"
            .ascii      "|%-10d| allineamento a sinistra\n"
            .asciz      "|%010d| allineamento a destra con riempimento\n"
fmt_int_64: .ascii      "|%20ld| allineamento a destra\n"
            .ascii      "|%-20ld| allineamento a sinistra\n"
            .asciz      "|%020ld| allineamento a destra con riempimento\n"
stringa1:   .asciz      "stringa1"
stringa2:   .asciz      "stringa2"

ciao:       .string     "ciao"
hello:      .string     "hello"
fmt_str_centered: .string "|          %s          |\n" // unico modo

            .text
            .type       main, %function
            .global     main
main:       stp         x29, x30, [sp, #-16]!

            // adr         x0, fmt_str_sx
            // adr         x1, stringa1
            // bl          printf
            //
            // adr         x0, fmt_int_32_sx
            // mov         x1, #1000
            // bl          printf
            //
            // adr         x0, fmt_int_64_sx
            // mov         x1, #1
            // bl          printf
            //
            // adr         x0, fmt_str_dx
            // adr         x1, stringa1
            // bl          printf
            //
            // adr         x0, fmt_int_32_dx
            // mov         x1, #1
            // bl          printf
            //
            // adr         x0, fmt_int_64_dx
            // mov         x1, #1
            // bl          printf
            //
            // adr         x0, fmt_int_32_dx_padding
            // mov         x1, #1
            // bl          printf
            //
            // adr         x0, fmt_int_64_dx_padding
            // mov         x1, #1
            // bl          printf
            //
            // adr         x0, fmt_str
            // adr         x1, stringa1
            // adr         x2, stringa2
            // bl          printf
            //
            // adr         x0, fmt_int_32
            // mov         x1, #1
            // mov         x2, #2
            // mov         x3, #3
            // bl          printf
            //
            // adr         x0, fmt_int_64
            // mov         x1, #4
            // mov         x2, #5
            // mov         x3, #6
            // bl          printf

            adr         x0, fmt_int_32_dx
            mov         w1, #123
            bl          printf

            adr         x0, fmt_int_64_sx
            mov         x1, #1000
            bl          printf

            adr         x0, fmt_int_64_dx_padding
            mov         x1, #1999
            bl          printf

            adr         x0, fmt_str
            adr         x1, ciao
            adr         x2, hello
            bl          printf

            // stampa "ciao" centrato
            adr         x0, fmt_str_centered
            adr         x1, ciao
            bl          printf

            mov         w0, #0
            ldp         x29, x30, [sp], #16
            ret
            .size       main, (. - main)
