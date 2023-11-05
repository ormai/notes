# Fondamenti di Programmazione 2

Secondo anno / Primo semestre

```
.
├── appunti
├── esercizi
└── lab
```

Keymap per compilare con `make` ed eseguire in [Neovim](https://github.com/neovim/neovim) con [akinsho/toggleterm.nvim](https://github.com/akinsho/toggleterm.nvim):

```lua
vim.keymap.set('n', '<leader>r', ":TermExec cmd='make %:r && ./%:r'<CR>")
```

[config](https://github.com/ormai/dotfiles/blob/main/.config/nvim/after/ftplugin/cpp.lua)

# GNU GDB per debuggare

1. Compilare con la flag [`-ggdb`](https://gcc.gnu.org/onlinedocs/gcc-13.2.0/gcc/Debugging-Options.html#index-ggdb) che aggiunge informazioni di debug per GDB
2. `gdb --tui executable`
3. una volta dentro si può usare `tui reg all` per vedere il contenuto aggiornato di tutti i registri.

Anche: `objdump -d executable`

# GNU make

Template di un Makefile

```Makefile
# Eseguibile del compilatore
CC=g++
# Specifica standard, abilita informazioni di debug e tutti i warning
CFLAGS=-std=c++11 -ggdb -Wall

all: il-mio-progetto # `make all` costruirà il-mio-progetto

# il-mio-progetto è il nome dell'eseguibile unico
il-mio-progetto: dipendenza.o altra-dipendenza.o
  $(CC) $(CFLAGS) $@ $^ main.cpp
# $@ scorciatoia per il target: 'il-mio-progetto'
# $^ tutte le dipendenze già compilate, quindi in formato .o
# main.cpp è il sorgente principale

dipendenza.o: dipendenza.cpp dipendenza.hpp
  $(CC) $(CFLAGS) -c dipendenza.cpp

altra-dipendenza.o: altra-dipendenza.cpp altra-dipendenza.hpp
  $(CC) $(CFLAGS) -c altra-dipendenza.cpp

# `make test` esegue l'unico eseguibile
test:
  ./il-mio-progetto

# `make clean` rimuove l'eseguibile e i .o dalla directory del progetto
clean:
  $(RM) il-mio-progetto *.o

# NB: le indentazioni devono essere tabulazioni pure, non spazi
```
