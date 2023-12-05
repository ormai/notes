                          // x20 | x21
mov x20, #2               //  2  |  ?
lsr x21, x20, #1          //  2  |  1
sub x20, x20, x21         //  1  |  1
add x20, x20, x21, lsl #2 //  5  |  1
