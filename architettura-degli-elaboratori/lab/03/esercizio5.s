.section .rodata
info: 
    .asciz "INFO on\n"
debug: 
    .asciz "DEBUG on\n"
warning: 
    .asciz "WARNING on\n"

.equ LOG_LEVEL, 31
.equ DEBUG, 10
.equ INFO, 20
.equ WARNING, 30

.macro print_debug
    .if LOG_LEVEL >= DEBUG
        adr x0, debug
        bl printf
    .endif
.endm

.macro print_info
    .if LOG_LEVEL >= INFO
        adr x0, info
        bl printf
    .endif
.endm

.macro print_warning
    .if LOG_LEVEL >= WARNING
        adr x0, warning
        bl printf
    .endif
.endm

.text
.type main, %function
.global main
main:
    stp x29, x30, [sp, #-16]!

    print_warning
    print_info
    print_debug

    // return 0
    mov w0, #0
    ldp x29, x30, [sp], #16
    ret
    .size main, (. - main)

