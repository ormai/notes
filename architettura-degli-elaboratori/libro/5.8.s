            .type       bytecopy, %function
            .global     bytecopy
bytecopy:
            stp         x29, x30, [sp, #-16]!

            // .string in x0 (address) // char dest[]
            // .string in x1 (address) // char src[]
            // .word in w2 // int count

            sub         w2, w2, #1 // count = count - 1;
            // pre-test loop
while:
            cmp         w2, #0
            blt         return // if (count < 0) { return; }

            ldrb        x2, [x1, w2, uxtw] // x2 = src[count]
            strb        x2, [x0, w2, uxtw] // dest[count] = x2

            sub         w2, w2, #1 // count = count - 1;
return:
            mov         w0, #0 // ruturns void
            ldp         x29, x30, [sp], #16
            ret
            .size        bytecopy, (. - bytecopy)
