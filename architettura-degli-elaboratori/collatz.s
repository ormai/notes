            .section    .rodata
fmt:        .asciz      "%d\n"

            .text
            .type       main, %function
            .global     main
main:
            stp         x29, x30, [sp, #-16]!
            stp         x19, x20, [sp, #-16]!

            // chiama collatz(n) e stampane il valore
            mov         w0, #5
            bl          collatz
            mov         w1, w0
            adr         x0, fmt
            bl          printf

            mov         w0, wzr // return 0;
            ldp         x19, x20, [sp], #16
            ldp         x29, x30, [sp], #16
            ret
            .size       main, (. - main)

/*****************************************************************************/

            .type       collatz, %function
collatz:    stp         x29, x30, [sp, #-16]!

            // ----------------------------------------------------------------

base_case:  cmp         w0, #1
            beq         return                  // if (w0 = 1) return 1

if:         tst         w0, #1                  // if w0 is odd goto else
            bne         else

            // collatz(n // 2) + 1
            mov         w1, #2
            udiv        w0, w0, w1
            bl          collatz                 // <-- chiamata ricorsiva
            add         w0, w0, #1

            b           return

else:       // collatz(n * 3 - 1) + 2
            mov         w1, #3
            mov         w2, #1
            madd        w0, w0, w1, w2 // w0 = w2 + (w0 * w1) = 1 + (n * 3)
            bl          collatz                 // <-- chiamata ricorsiva
            add         w0, w0, #1

            // -----------------------------------------------------------------

return:     ldp         x29, x30, [sp], #16
            ret
            .size       collatz, (. - collatz)
