        .section .rodata
fmt:    .string "%d, %d, %d, %d, %d, %d, %d.\n"

        .data
arr:    .word  9, 42, 3, 4, 6, 11, 17

        .text
        .type   main, %function
        .global main
main:
        stp     x29, x30, [sp, #-16]!

        adr     x11, arr

        mov     w12, #100               // w12 = 100
        str     w12, [x11, #4*3]        // arr[3] = w12

        ldr     w13, [x11, #4*6]        // w13 = arr[6]
        str     w13, [x11]              // arr[0] = w13


        // print the array
        adr     x0, fmt
        ldr     w1, [x11], #4
        ldr     w2, [x11], #4
        ldr     w3, [x11], #4
        ldr     w4, [x11], #4
        ldr     w5, [x11], #4
        ldr     w6, [x11], #4
        ldr     w7, [x11]
        bl      printf

        ldp     x29, x30, [sp], #16
        mov     x0, #0
        ret
        .size   main, (. - main)
