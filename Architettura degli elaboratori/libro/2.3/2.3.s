            .section    .rodata
fmt_int:    .string     "%lld\n"

            .text
            .type       main, %function
            .global     main
main:       stp         x29, x30, [sp, #-16]!
            str         x19, [sp, #-16]!

            mov         w19, wzr                 // i = 0
loop:
            mov         x0, x19
            bl          f
            mov         x1, x0
            adr         x0, fmt_int
            bl          printf

            add         w19, w19, #1             // i += 1
            cmp         w19, #50                 // termina quando i = 50
            blt         loop

            mov         w0, #0
            ldr         x19, [sp], #16
            ldp         x29, x30, [sp], #16
            ret
            .size        main, (. - main)

            .type       f, %function
f:          stp         x29, x30, [sp, #-16]!
            stp         x19, x20, [sp, #-16]!

casoBase1:  cmp         x0, #0
            bne         casoBase2
            mov         x0, #0
            b           return

casoBase2:  cmp         x0, #1
            bne         casoRicorivo
            mov         x0, #1
            b           return

casoRicorivo:
            mov         x19, x0     // metti al sicuro n originale

            // 2 * f(n - 1)
            sub         x0, x0, #1
            bl          f
            mov         x5, #2
            mul         x0, x0, x5
            mov         x20, x0     // n dopo 2*f(n-1)

            // f(n - 2) / 2
            sub         x0, x19, #2
            bl          f
            udiv        x0, x0, x5

            sub         x0, x20, x0

return:     ldp         x19, x20, [sp], #16
            ldp         x29, x30, [sp], #16
            ret
            .size        f, (. - f)
