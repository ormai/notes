# Registers

There are **31 general-purpose registers**^[For the aarch64 Instruction Set Architecture]. When they are referred as `x0` through `x30` they can store 64 bits, `w0` through `w31` refers to the lest significant 32 bits. Using `R0` through `R31` avoids specifying how many bits are requested, so it can be either `x` or `w`.

There are convention for the use of registers:
- `R0-R7` are used for passing arguments when calling procedures or functions
- `R9-R15` are scratch registers, so they can hold temporary results of calculations
- `R16-R29` can be used as scratch registers but their contents must be saved before they are used
- `x29` is the **frame pointer** used by compilers to track the **stack frame**. The hardware considers it a common general-purpose register.
- `x30` (procedure link register) holds the **return address** of a subroutine.
- `x31`, `sp` (stack pointer) holds the **address of the end of the stack**.
- `xzr` (64 bit), `wzr` (32 bit) is the zero register, it has always the value zero
- `pc` (program counter) contains the address of the next instruction to execute. The CPU increments it by 4 every time it fetches. It can be used to jump to any address.
- `PSTATE` (processor state) contains bits indicating the status of the current process and the result of the previous operation. It contains fields used only by the OS; a program usually uses only the first four bits, called *flags*:
    - N: `1` if the result of an operation is negative, `0` if it's positive or zero
    - Z: `1` if the result of an operation is zero, `0` if it's non-zero
    - C: `1` if an operation results in a carry out of the most significant bit, or if a subtract operation results in a borrow. For shifts it is set to the last significant bit shifted by the *shifter*
    - V: `1` if a signed overflow happens
