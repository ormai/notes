# 2023-11-22

Un modo per accedere ai nodi del grafo è enumerarli tutti. Si deve stabilire il punto di partenza.

Matrice di adiacenza è più efficiente di liste di adiacenza.

## Depth First Search (DFS)

Si considera un certo nodo, poi si considerano nodi ad esso adiacenti, poi si considerano gli adiacenti del primo. Quando non si può scendere più oppure gli adiacenti sono stati già visitati il controllo torna alla nodo precedente.

```cpp
void dfs(unsigned sorgente, const Grafo &grafo, vector<bool> &visitati) {
    visitati[sorgente] = true; // segno il nodo visitato
    for (unsigned i = 0; i < grafo.n(); ++i) // per tutti gli adiacenti
        if (
            sorgente != i // ignora gli anelli
            && !visitati[i] // non deve essere già visitato
            && grafo(sorgente, i) // sono adiacienti se esiste l'arco
        )
            dfs(i, grafo, visitati);
}
```

```cpp
Grafo chiusuraTransitiva(const Grafo &grafo) {
    Grafo gc(g.n());
    vector<bool> visitati(grafo.n());

    for (int i = 0; i < grafo.n()); ++i) {
        visitati.assign(visitati.size(), false);
        dfs(i, grafo, visitati); // il risultato è in 'vistati'
        for (int j = 0; j < grafo.n(); ++j) {
            if (i != j && visitati[j])
                gc(i, j, true);
        }
    }

    return gc;
}
```

## Breadth First Search (BFS)

Si considera un certo nodo, poi si considerano nodi ad esso adiacenti, per ognuno degli adiacenti si considerano gli adiacenti.

```cpp
void bfs(const Grafo &grafo, unsigned sorgente) {
    vector<bool> visitati(grafo.n(), false);

    queue<unsigned> q;
    q.push(sorgente);
    visitati[sorgente] = true;

    while(!q.empty()) { // svuota la coda
        unsigned u = q.front();
        q.pop();
        // VALUTA u

        // spingi in q gli adicenti di u non ancora visitati
        for (int i = 0; i < grafo.n(); ++i)
            if (u != i && grafo(u, i) && !visitati[i]) {
                q.push(i);
                visitati[i] = true;
            }
    }
}
```

Costruire percorsi brevi richiede altro.

Implementazione alternativa in cui per ogni nodo si salva il suo precedente nel cammino.

```cpp
vector<int> bfs(const Grafo &grafo, unsigned sorgente) {
    vector<bool> visitati(grafo.n(), false);

    vector<int> predecessori(grafo.n(), -1);

    queue<unsigned> q;
    q.push(sorgente);
    predecessori[sorgente] = sorgente; // all'inizio del percorso

    visitati[sorgente] = true;

    while(!q.empty()) { // svuota la coda
        unsigned u = q.front();
        q.pop();

        // spingi in q gli adicenti di un non ancora visitati
        for (int i = 0; i < grafo.n(); ++i)
            if (u != i && grafo(u, i) && !visitati[i]) {
                q.push(i);
                predecessori[i] = u;
                visitati[i] = true;
            }
    }

    return predecessori;
}
```


```cpp
void ricostruisciCammino(int s, int t, const vector<int> &p, list<int> &cammino) {
    if (s == t)
        cammino.push_back(s);
    else if (t == -1)
        return;
    else {
        // itero al contrario fino ad arrivare ad s (caso base)
        cammino.push_back(t);
        ricostruisciCammino(s, p[t], p, cammino);
    }
}
```

Verificare se il cammino esiste e restituisci il cammino stesso. Non da il cammino più breve.

```cpp
bool trovaCammino(const Grafo &grafo, int sorgente, int destinazione, vector<bool> &visitati, list<int> &cammino) {
    if (sorgente == destinazione) {
        visitati[destinazione] = true;
        return true;
    }
    visitati[sorgente] = true;
    bool trovato = false;
    for (int i = 0; !trovato && i < grafo.n(); ++i)
        if (!visitati[i] && grafo(sorgente, i)) {
            cammino.push_back(j);
            trovato = trovaCammino(grafo, i, destinazione, visitati, cammino);
            if (!trovato)
                cammino.pop_back();
        }
    return trovato;
}
```