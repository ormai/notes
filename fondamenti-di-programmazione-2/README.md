# Fondamenti di Programmazione 2

`Secondo anno / Primo semestre`

```
/
├── appunti   // presi durante le lezioni e vari
├── esercizi  // quelli con nome del tipo '3.29.md' sono presi dal Primer
└── lab       // esercitazioni di laboratorio
```

Una funzione per bash e zsh che compila-esegue-ripulisce:

```bash
run() {
  executable="${1%%.cpp}" # rimuovi l'estensione dal file name
  /usr/bin/g++ -std=c++11 -Wall $1 -o $executable # compila
  ./$executable # esegui
  rm -f $executable # rimuovi l'eseguibile
}
```
