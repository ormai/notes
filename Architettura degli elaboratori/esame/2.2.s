/*  Scrivere un programma AArch64 che, letta da input una sequenza di numeri
 *  interi positivi terminata da un numero negativo, stampi OK se la sequenza è
 *  strettamente crescente, NO altrimenti.
 *  Non aggiungere ulteriori stampe. Stampe in fase di lettura dell'input,
 *  durante la computazione o output diversi da OK e NO sono considerati errori.
 *
 *  Esempi:
 *
 *      Input: 1 2 5 7 -4; Output: OK
 *      Input: 1 2 5 7 6 -1; Output: NO
 *      Input: 1 1 2 -10; Output: NO
 *      Input: -1; Output: OK
 */

            .section    .rodata
scan_int:   .asciz      "%d"
fmt_ok:     .string     "OK\n"
fmt_no:     .string     "NO\n"
            .align      2

            .data
prec:       .word       0           // numero letto volta per volta
curr:       .word       0
cond:       .word       1           // variabile booleana globale

            .macro      read dest
            adr         x0, scan_int
            adr         x1, \dest
            bl          scanf
            .endm

            .text
            .type       main, %function
            .global     main
main:       stp         x29, x30, [sp, #-16]!
            str         x19, [sp, #-16]!

            mov         w19, #19                // variabile booleana

            // --------------------------------------------------

            read        prec
            ldr         w0, prec

            cmp         w0, #0                  // prec > 0
            blt         endl

loop:       read        curr                    // curr = int(input())
            ldr         w0, prec
            ldr         w1, curr

            cmp         w1, #0                  // curr > 0
            blt         endl

if:         cmp         w0, w1                  // controlla che (prec < succ)
            blt         endif

            mov         w19, #0                 // condizione = False

endif:      adr         x2, prec
            str         w1, [x2]                // prec = curr
            b           loop

endl:       cmp         w19, #1
            bne         else

            adr         x0, fmt_ok              // print("OK")
            bl          printf
            b           return

else:       adr         x0, fmt_no              // print("NO")
            bl          printf

            // ----------------------------------------------------

return:     ldr         x19, [sp], #16
            ldp         x29, x30, [sp], #16
            mov         w0, #0
            ret
            .size       main, (. - main)
