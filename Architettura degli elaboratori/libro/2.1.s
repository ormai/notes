            .section    .rodata
fmtScan:   .string     "%d"
fmtInt:    .string     "%lld\n"

            .data
n:          .dword      0

            .text
            .type       main, %function
            .global     main
main:       stp         x29, x30, [sp, #-16]!

            ldr         x0, =fmtScan
            ldr         x1, =n
            bl          scanf

            ldr         x0, n
            bl          q

            mov         x1, x0
            ldr         x0, =fmtInt
            bl          printf

            mov         x0, xzr
            ldp         x29, x30, [sp], #16
            ret
            .size        main, (. - main)



            .type       q, %function
q:          stp         x29, x30, [sp, #-16]!

// -----------------------------------------------------------------------------

            // f(0) = 0
            cmp         x0, xzr
            bne         ifOdd
            b           return

            // f(n) = q(n - 1) * 7
ifOdd:      tst         x0, 0b1
            beq         elifEven

            sub         x0, x0, #1
            bl          q
            mov         x6, #7
            mul         x0, x0, x6

            b           return

            // f(n) = q(n - 1) / 2
elifEven:   sub         x0, x0, #1
            bl          q
            mov         x7, #2
            udiv        x0, x0, x7

// ----------------------------------------------------------------------------

return:     ldp         x29, x30, [sp], #16
            ret
            .size       q, (. - q)
