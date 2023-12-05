# Addressing modes

To *load* and *store* data between [memory](memory.md) and [registers](registers.md) the instructions must be able to address the data. This can be accomplished in different ways:
- **register address** `[Xn|sp]`. The square brackets syntax is used to indicate that the address contained in `Xn|sp` is being used for addressing
- **signed immediate offset** `[Xn|sp, <±imm9>]`. The immediate value (the offset) is added to the content of `Xn|sp`, the result is used to address. The immediate value can be positive or negative and cannot occupy more than 9 bits.
- **unsigned immediate scaled offset** `[Xn|sp, <imm12>]`. The offset is added to the contents of the register. The addressing starts at the address resulting from the calculation and lasts eight bytes. The immediate offset must be `>= 0` and occupy not more than 12 bits. All this is like just doing a signed offset, the assembler will use scaled offset depending on the size of the offset. Before any of this happens, the offset is **scaled** like so:
    - for a 64-bit register the immediate value is shifted left by three bits
    - for 32 bits of load-store the `imm` is shifted left by two bits
    - for half words `imm` is shifted by one bit left
    - for byte loads and stores no shifting occurs.
- **pre-indexed immediate offset** `[Xn|sp, #±<imm9>]!`. Before the load-store operation the register is shifted by adding the immediate value, then the result is set in `Xn` and used as the address. This is useful with stepping through an array.
- **post-indexed immediate offset** `[Xn|sp], #±<imm9>`. `Xn|sp` is used as the address to load and store. After the load-store the value in the register is updated by adding to it the offset. This is useful for stepping through an array.
- **register offset** `[Xn|sp, Rm, <option>]`. `Rm` gets changed by `<option>` and then added to `Xn|sp`. The result is used as the address. `Rm` can be shifted left with options `lsl #1` (for half-words), `lsl #2` (for words), `lsl #3` (for double-words).
  This is useful for accessing arrays, where `Xn` contains the address of the beginning of the array, `Rm` is the integer index and the shift size depends on the size of the object contained in the array.
  If `Rm` is 32 bits (`Wm`) `<option>` can be `sxtw` for *sign extension*, or `uxtw` for *unsigned extension*.
- **literal** `label`. Address of the label.
- **pseudo load**: `=<immediate|symbol>`. Can only be used with `ldr`
