# Debugging di un programma C++

1. Compilare con la flag [`-ggdb`](https://gcc.gnu.org/onlinedocs/gcc-13.2.0/gcc/Debugging-Options.html#index-ggdb) che aggiunge informazioni per GDB
2. `gdb --tui executable`
3. una volta dentro GDB si può usare `tui reg all` per vedere il contenuto aggiornato di tutti i registri.

Anche: `objdump -d executable`
