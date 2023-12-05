            .section    .rodata
fmt_x:      .asciz      "Inserisci un numero tra 1 e 10: "
fmt_scan:   .asciz      "%d"
fmt_ottimo: .asciz      "OTTIMO\n"
fmt_distinto: .asciz    "DISTINTO\n"
fmt_buono: .asciz       "BUONO\n"
fmt_discreto: .asciz    "DISCRETO\n"
fmt_sufficiente: .asciz "SUFFICIENTE\n"
fmt_insufficiente: .asciz "INSUFFICIENTE\n"
fmt_non_valido: .asciz "NON VALIDO\n"
            .align      2

.bss
            x:          .word 0

.macro      print fmt
            adr         x0, \fmt
            bl          printf
.endm

.macro scan fmt var
            adr x0, \fmt
            bl          printf

            adr         x0, fmt_scan
            ldr         x1, =\var
            bl          scanf
.endm

            .text
            .type       main, %function
            .global     main
main:       stp x29, x30, [sp, #-16]!

            scan        fmt_x, x

            ldr         w0, x
            mov         w1, #10
            mov         w2, #9
            mov         w3, #8
            mov         w4, #7
            mov         w5, #6
            mov         w6, #1

            cmp         w0, w1
            bgt         else
            blt         elseif1
            print       fmt_ottimo
            b           endif

elseif1:
            cmp         w0, w2
            blt         elseif2
            print       fmt_distinto
            b           endif
elseif2:
            cmp         w0, w3
            blt         elseif3
            print       fmt_buono
            b           endif
elseif3:
            cmp w0, w4
            blt         elseif4
            print       fmt_discreto
            b           endif
elseif4:
            cmp         w0, w5 // if (w0 < w5) { goto elseif5; }
            blt         elseif5
            print       fmt_sufficiente
            b           endif
elseif5:
            cmp         w0, w6
            blt         else
            print       fmt_insufficiente
            b           endif
else:
            print       fmt_non_valido
endif:

            mov         w0, #0
            ldp         x29, x30, [sp], #16
            ret
            .size       main, (. - main)
