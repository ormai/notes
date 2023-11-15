# 2023-11-15

## Visita per livelli

```
         A
        / \
       /   \
      B     C
     / \     \
    D   E     F
   / \   \   / \
  G  H   I  L   M
```
Stampa: A B C D E F G H I L M

```
Coda: A
      └ B C
        └── D E F
            └── G H
                └── foglia
```

Per ogni nodo che si va a valutare se ne aggiungono altri due, i suoi figli.

```cpp
typedef AlberoBinario<int> AlberoBinarioInt; // utile per evitare errori di compilazioni

void visitaPerLivelli(AlberoBinarioInt a) { // si passa per valore perché si tratta di un semplice puntatore
    if (a.nullo())
        return;

    std::queue<AlberoBinarioInt> q;
    q.push(a); // se la coda è vuota non si entra mai nel ciclo

    std::queue<int> livelli; // per tenere traccia del livello di ciascun nodo
    livelli.push(1);

    int somma = 0;

    while (!q.empty()) {
        AlberoBinarioInt tmp = q.front();
        int livelloTemporaneo = livelli.front();
        q.pop();
        livelli.pop();

        // Valuta il nodo
        std::cout << tmp.nodoRadice() << ' ';
        somma += tmp.nodoRadice();

        if (!tmp.figli(sinistro).nullo()) {
            q.push(tmp.figli(sinistro));
            livelli.push(livelloTemporaneo + 1);
        }

        if (!tmp.figli(destro).nullo()) {
            q.push(tmp.figli(destro));
            livelli.push(livelloTemporaneo + 1);
        }
    }
}
```

```cpp
int somma(AlberoBinario<int> a) {
    if (a.null())
        return 0;

    return a.nodoRadice() + somma(a.figli(sinistra)) + somma(a.figli(destra));
}
```

## Lettura di un albero

```
           10
          /  \
        15    25
       /  \   / \
      6    4 7   12
```

15 figlio di 10 da sinistra
25 figlio di 10 da destra
 6 figlio di 15 da sinistra
 4 figlio di 15 da destra
 7 figlio di 25 da sinistra
12 figlio di 25 da destra

```cpp
int main() {
    // si assume che l'input sia corretto e non si fanno ulteriori controlli
    string input;
    bool firstLine = true;
    AlberoBinario<int> A;

    while (getline(std::cin, input)) {
        if (input == "-1")
            break;

        if (firstLine) {
            int valoreRadice = std::stoi(input); // stoi: string to int
            A.modificaRadice(valoreRadice);
            continue;
        }

        int indiceDuepunti = input.find(':');
        int indiceSpazio = input.find(' ');

        string parteSinistra = input.substr(0, indiceDuepunti),
               parteDestra = input.substr(indiceDuepunti + 1, indiceSpazio - indiceDuepunti);

        Direzione direzione = sinistra;

        if (input[indiceSpazio] + 1) == 'd')
            direzione = destra;

        int valoreFiglio = std::stoi(parteSinistra), valorePadre = std::stoi(parteDestra);

        AlberoBinario<int> punto = cerca(A, valorePadre);
        if (!punto.nullo()) {
            AlberoBinario<int> daInserire(valoreFiglio);
            punto.inserisciFiglio(daInserire, direzione);
        }
   }
}
```

## Ricerca e ordinamento di insieme tramite alberi binari

Ordinamento parziale:

```
          < x   x   > x
               / \
        < y   y   z  
             / \ / \
```

Albero binario di ricerca (ABR).

```cpp
void inserisci(const T &valore);

// per ogni livello dell'albero si fa un solo confronto
bool cerca(const T& valore) const; // come la ricerca binaria ma più efficace
// profondità = O(log_2 n) nel caso migliore, O(n) nel caso peggiore

void cancellare(const T& valore);

bool nullo() const;
```

L'albero è una struttura molto dinamica, per questo in alcuni casi è da preferire su un std::vector.

Dato un elenco di elementi ordinato: 1 2 3 4 5 6 7 8 9, organizzarlo in un ABR genererebbe un albero degenere. Il miglior modo di rappresentare degli elementi già in ordine è stabilire che la radice è l'elemento centrale.
