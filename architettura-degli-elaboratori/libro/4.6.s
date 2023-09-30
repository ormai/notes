            .section    .rodata

fmt:        .string     "a = %d, b = %d\n"
fmt_scan:   .string     "%d"
prompt:     .string     "Type an integer: "
fmt_pstate: .asciz      "NZCV = %d%d%d%d\n"

            .data
a:          .skip       4
b:          .skip       4

            .macro      read dest
            adr         x0, prompt
            bl          printf
            adr         x0, fmt_scan
            adr         x1, \dest
            bl          scanf
            .endm

            .macro      print_pstate
            adr         x0, fmt_pstate
            cset        w1, mi // w1 viene settato se N = 1
            cset        w2, eq // w2 viene settato se Z = 1
            cset        w3, cs // unsigned overflow
            cset        w4, vs // signed overflow
            bl          printf
            .endm

            .text
            .type       main, %function
            .global     main
main:       stp         x29, x30, [sp, #-16]!

            read        a
            read        b

            // load in the reagisters a and b
            adr         x1, a
            ldr         w1, [x1]
            adr         x2, b
            ldr         w2, [x2]

            // check if the number in w3 is odd
            tst         w1, #1   // (w1 & 1)
            beq         even     // branch if (Z = 1). This is the case if w1's
                                 // last significant bit is 0, meanign that it
                                 // is and odd number

            // if (w1 & 1) evaluates to 1, so Z = 0
            cinv        w1, w1, ne // if (w1 & 1) { w1 = -w1; }
            add         w1, w1, #1 // it gives the number decreased by one (?)
            bl          finish

even:
            add         w2, w2, #7 // else { w2 += 7; }

finish:
            // print w1 and w2
            adr         x0, fmt
            bl          printf

            mov         w0, #0
            ldp         x29, x30, [sp], #16
            ret
            .size        main, (. - main)
