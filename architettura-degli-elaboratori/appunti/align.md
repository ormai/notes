# Aligning memory

`.align n`

```
.asciz, .byte, .short, .word
.align 3
.quad
```

```
.asciz, .byte, .short
.align 2
.word
```

```
.byte, .asciz
.align 1
.short
```