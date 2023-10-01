# Memory

Computer memory is made of **cells** that usually contain one byte, each identified by an **address** written in hexadecimal. The address is used to move data to and from the cell.

A CPU that can access a single byte of memory has **byte addressable memory**. Bytes can be grouped into words. A CPU that can access memory only in word-sized groups has **word addressable memory**.

The grouping of words can be accomplished in two ways:
- **big-endian**: the most significant byte of a word is stored in the lowest address, and the least significant byte is stored in the highest address.
- **little-endian**: the least significant byte is stored in the largest address and the most significant byte is stored in the smallest address.

![[endianesses.excalidraw|center|100%]]

Arm processors can either use little-endian or big-endian. Linux sets them to little-endian by default.
