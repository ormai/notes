            .section    .rodata
fmt_read:   .asciz      "Inserisci un numero: "
fmt_scan:   .asciz      "%d"
fmt_print:  .asciz      "%d\n"
fmt_ok:     .asciz      "OK\n"
            .align      2

            .bss
a:          .word       0
b:          .word       0
c:          .word       0

            .macro      print fmt
            adr         x0, \fmt
            bl          printf
            .endm

            .macro      print_value
            adr         x0, fmt_print
            bl          printf
            .endm

            .macro      scan fmt var
            adr         x0, \fmt
            bl          printf
            adr         x0, fmt_scan
            ldr         x1, =\var
            bl          scanf
            .endm

            .text
            .type       main, %function
            .global     main
main:       stp x29, x30, [sp, #-16]!

            scan        fmt_read, a //a contiene il primo numero letto da input
            scan        fmt_read, b //b contiene il secondo numero letto da input
            scan        fmt_read, c //c contiene il terzo numero letto da input

            // Da continuare a partire da qui 

            ldr         w5, a
            ldr         w6, b
            ldr         w7, c

            // b           if // scommentare per andare ad etichette e salti
            // istruzioni utili solo per usare csel:
            adr         x2, fmt_ok
            adr         x3, fmt_print

            // CON CSEL
            mov         w1, #0 // inizializza w1 a zero
            // if ((a == b) || (a == c)) { printf("%d", a); }
            cmp         w5, w6
            csel        w1, w5, w1, eq
            cmp         w5, w7
            csel        w1, w5, w1, eq
            cmp         w6, w7
            csel        w1, w6, w1, eq
            // se w1 è rimasto zero vuol dire che a != b != c
            cmp         w1, #0          // if (w1 == 0) {
            csel        x0, x2, x3, eq  //     x0 = x2; // x2 punta a "OK\n"
                                        // } else {
                                        //     x0 = x3; // x3 punta a "%d\n"
                                        // }
            bl          printf

            // salta ad endif invece di farmi commentare tutto
            b           endif
            // CON ETICHETTE E SALTI
if:         cmp         w5, w6
            beq         elif1

            cmp         w6, w7
            beq         elif2

            cmp         w5, w7
            beq         elif3

            b           else

elif1:      // w5 == w6
            mov         w1, w5
            print_value
            b           endif

elif2:      // w6 == w7
            mov         w1, w6
            print_value
            b           endif

elif3:      // w5 == w7
            mov         w1, w5
            print_value
            b           endif

else:       print       fmt_ok
endif:
            mov         w0, #0
            ldp         x29, x30, [sp], #16
            ret
            .size       main, (. - main)
