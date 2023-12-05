/*  Scrivere un programma AArch64 che stampi 50 linee f(0), f(1), ..., dove
 *  f(n) è definito come segue:
 *
 *  f(0) = 0
 *  f(1) = 1
 *  f(n) = (2*f(n-1) - f(n-2)/2), se n >= 2
 *
 *  Usare interi a 64 bit per tutte le operazioni. Le prime 7 linee saranno
 *  quindi
 */

            .section    .rodata
fmt_int:    .string     "%lld\n"

            .data
cacheLen:   .word       0                       // variabile globale

            .bss
cache:      .skip       400                     // array dei risultai
            /* 50 numeri da 8 byte ciascuno */

            .text
            .type       main, %function
            .global     main
main:       stp         x29, x30, [sp, #-16]!
            str         x19, [sp, #-16]!

            mov         w19, wzr                 // i = 0

loop:       // così f() può sapere quanti elementi ci sono in `cache`
            adr         x1, cacheLen
            str         w19, [x1]

            // chiama f(w19), con w19 che va da 0 a 49, così da avere 50 linee
            mov         w0, w19
            bl          f

            // SALVA IL RISULATO DI f(w19) in chache[w19]
            mov         w2, #8
            ldr         x3, =cache
            madd        x4, x19, x2, x3
            str         x0, [x4]

            // STAMPA IL RISULTATO DI f(w19)
            mov         x1, x0
            adr         x0, fmt_int
            bl          printf

            // RIPETI IL LOOP
            add         w19, w19, #1             // i += 1
            cmp         w19, #50                 // termina quando i = 50
            blt         loop

            // TERMINA
            mov         w0, #0
            ldr         x19, [sp], #16
            ldp         x29, x30, [sp], #16
            ret
            .size        main, (. - main)

/*****************************************************************************/

            .type       f, %function
f:          stp         x29, x30, [sp, #-16]!
            stp         x19, x20, [sp, #-16]!

            // ---------------------------------------------------------------

            // f(0) = 0
casoBase1:  cmp         x0, #0
            bne         casoBase2
            mov         x0, #0
            b           return

            // f(1) = 1
casoBase2:  cmp         x0, #1
            bne         casoRicorivo
            mov         x0, #1
            b           return

            // f(n) = 2 * f(n - 1) - f(n - 2) / 2
casoRicorivo:
            // controlla che il risultato non sia già stato calcolato
            ldr         w1, cacheLen            // w1 = cache[w19]
            cmp         x0, x1
            bge         calcola

            // recupera risultato già calcolato
            ldr         x3, =cache
            mov         w4, #8
            madd        x5, x0, x4, x3
            ldr         x0, [x5]    // x0 = cache[n]
            b           return      // return x0

calcola:    mov         x19, x0     // metti al sicuro n originale

            // 2 * f(n - 1)
            sub         x0, x0, #1
            bl          f
            mov         x5, #2
            mul         x0, x0, x5
            mov         x20, x0     // n dopo 2 * f(n - 1)

            // f(n - 2) / 2
            sub         x0, x19, #2
            bl          f
            mov         x5, #2
            udiv        x0, x0, x5

            sub         x0, x20, x0

            // ----------------------------------------------------------------

return:     ldp         x19, x20, [sp], #16
            ldp         x29, x30, [sp], #16
            ret
            .size        f, (. - f)
