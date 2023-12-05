            .type       minsix, %function
            .global     minsix
minsix:
            stp         x29, x30, [sp, #-16]!

            cmp         w2, w1
            csel        w1, w2, w1, lt

            cmp         w4, w3
            csel        w3, w4, w3, lt

            cmp         w3, w1
            csel        w5, w6, w5, lt

            cmp         w6, w5
            csel        w5, w6, w5, lt

            mov         w0, w1 // return w1
            ldp         x29, x30, [sp], #16
            ret
            .size        minsix, (. - minsix)
