# Immediate values

Immediate values are constants specified directly by the programmer. They can be:
- decimal, for example `39`
- octal, starting with zero, for example `077`
- hexadecimal, starting with `0x`, for example `0xF8CA`
- binary, starting with `0b`, for example `0b00011010` 

There are two ways in which immediate values can be specified:
- by literal immediate value, optionally prefixed by `#` to avoid confusion
- by the syntax `=<immediate|symbol>` which can **only** be used by `ldr`
