# How does a computer work?

Instructions written in a programming language are understandable to humans but in order to be understood by computers they must be reduced to a **stream of numbers**. Assembly language is a step above the stream of numbers. Each number is a single action for the computer, which can execute billions of action every second.

In assembly each line of code is a single machine instruction, while in a higher level language a single line of code is *translated* in many machine instructions.

A computer consist of a CPU, [memory](memory.md), and input/output devices, all connected by a bus. The CPU does the computation and controls the other devices.

Memory is composed of cells in which the data is stored. Every cell is identified by an address. Memory can store data and instructions for the CPU.

The CPU itself has a small amount of memory called **registers**, which are used during computation to store the data to compute and the result, before sending it to RAM. 

The instructions are executed sequentially, one after the other. In the CPU there is a **program counter** (PC) that holds the location of the next instruction.

A CPU cycle consists of four phases:
1. fetch an instruction from memory
2. increment the program counter
3. execute the instruction
4. repeat the process with the next instruction

Instructions that alter the program counter exists, in this way loops are built.