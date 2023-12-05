// This program counts how many 1 bits there are in a register
            .section    .rodata
fmt:        .string     "Number of 1 bits: %d\n"
prompt:     .string     "Type an integer: "
fmt_scan:   .string     "%ld"
            .align      2

            .data
store:      .skip      8

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
main:       stp         x29, x30, [sp, #-16]!

            read        store

            // load the input
            ldr         x2, =store
            ldr         x2, [x2]

            mov         x3, #1 // setup the index
            mov         w4, #0 // setup the counter
loop:
            tst         x3, x2 // if the result of the 'and' comparison is
            cinc        w4, w4, ne // not zero increment the cou nter

            // If the index reached the most significant bit terminate the loop

            cmp         x3, 0x8000000000000000
            beq         endloop

            lsl         x3, x3, #1 // move the bit to check to the left

            b           loop
endloop:
            mov         w1, w4
            adr         x0, fmt
            bl          printf

            // return 0
            mov         w0, #0
            ldp         x29, x30, [sp], #16
            ret
            .size        main, (. - main)
