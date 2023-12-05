---
aliases:
  - "program memory"
---

# Program memory


[Memory](memory.md) is divided into six *sections*:
- **Stack** and **Heap** are defined when the program is executed and loaded. The size of these may vary while the program executes.
    - the heap contains variables that are allocated dynamically
    - the stack stores parameters for function calls, return address and local variables
- `.bss`, `.rodata`, `.data`, `.text` are set by the programmer and are fixed in size. The size depends on that of the program.
    - `.text` contains the executable instructions
    - `.rodata`, `.data`, `.bss` contain constants and static variables

Variables can be allocated statically, dynamically, and automatically.

Statically allocated variables are stored in `.data`, `.rodata`, `.bss`.
Dynamically allocated variables are stored in the heap.
Automatically (local) allocated variables are stored on the stack.

![](Pasted image 20230325105320.png)
