            .section    .rodata
fmt_sup:    .string     "SUPERATO\n"
fmt_nsup:   .string     "NON SUPERATO\n"
fmt_nval:   .string     "NON VALIDO\n"
prompt:     .string     "Scrivi un voto: "
fmt_scan:   .string     "%d"

            .bss
voto:       .word       0

            .macro      read dest
            adr         x0, prompt
            bl          printf
            adr         x0, fmt_scan
            adr         x1, \dest
            bl          scanf // scanf("%d", &voto)
            .endm

            .text
            .type       main, %function
            .global     main
main:       stp         x29, x30, [sp, #-16]!

            read        voto

            ldr         x1, =voto
            ldr         w1, [x1]

if:         cmp         w1, #0
            blt         else

            cmp         w1, #31
            bgt         else
elif:
            cmp         w1, #18
            bge         elif2

            adr         x0, fmt_nsup
            bl          printf
            b           endif
elif2:
            adr         x0, fmt_sup
            bl          printf
            b           endif

else:
            adr         x0, fmt_nval
            bl          printf
endif:
            mov         w0, #0
            ldp         x29, x30, [sp], #16
            ret
            .size        main, (. - main)
