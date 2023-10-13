# 2023-10-13

## Classi

Programmazione Orientata agli Oggetti: creare programmi basati interamente sugli **oggetti**, usando l'interazione tra oggetti.

- *Astrazione*: le classi descrivono oggetti, talvolta del mondo reale. Tali oggetti sono descritti in modo astratto.
- *Information hiding*: il modo in cui i dati sono strutturati è nascosto. Chi opera sui dati non conosce i dettagli dell'implementazione dei dati.
- *Encapsulation*: "classi dentro classi", si costruiscono classi usando altre classi.
- *Gerarchia*: alcune classi *estendono* il comportamento di altre classi.

Per definire una classe in c++ si usa la keyword `class`.

Le `struct` sono usate per definire dati, mentre le classi sono usate per definire dati e operazioni (funzioni) su di essi.

```cpp
class nomeClasse {
    specificatoreDiAccesso:
        membro1;
        membro2;

    specificatoreDiAccesso:
        membro3
};
```

Gli specificatori di accesso sono
- `private`: i membri sono visibili solo ad altri membri della stessa classe
- `protected`: equivalente a `private`, visibile a membri della stessa classe e di classi derivate (figli)
- `public`: visibile a tutti

Quando lo specificatore è omesso il default è `private`.

```cpp
class Rectangle {
    int width, height; // specifier omesso -> default è private

    public:
        Rectangle(int, int); // costruttore, ha lo stesso nome della classe
        Rectangle(); // costruttore di default (definito giù)

        // overloading di funzioni: il secondo costruttore viene chiamato quando la dichiarazione è fatta senza argomenti.

        // setters
        void set_width(int);
        void set_height(int);

        // getters
        void get_width();
        void get_height();

        int area() { return width * height; } // definizione della classe membro in-line
};

// definizione esterna della classe membro
void Rectangle::set_width(int x) {
    width = x;
}

void Rectangle::set_height(int x) {
    height = x;
}

int Rectangle::get_width() {
    return width;
}

int Rectangle::get_height() {
    return height;
}

Rectangle::Rectangle(int x, int y) { // definizione del costruttore
    // a differenza della preinizializzazione width è prima creata e poi vi si assegna x
    width = x;
    height = y;
}

Rectangle::Rectangle() { // definizione costruttore di default
    width = 5;
    height = 5;
}

/* OPPURE: preinizializzazione (inizializza mentre la classe viene creata)
Quando si dichiarano classi dentro classi va necessariamente usato questo modo.

Rectangle::Rectangle(int x, int y): width(x), height(y) {
    corpo...
}
*/

int main() {
    Rectangle rect, rectB, rectC;

    // rect.width; // non si può perché width è private

    rect.set_width(3);
    rect.set_height(4);

    cout << rect.area() << endl;

    rectB.set_width(5);
    rectB.set_height(7);

    cout << rectC.area() << endl; // è indefinito perché rectC.height e rectC.width non sono stati inizializzati.

    Rectangle rectD(4, 8);
}
```

L'inizializzazione di un ogetto-classe avviene tramite un *costruttore*. Funzioni membro di base `SET`, `GET` (setters e getters) per cambiare e ottenere i dati privati della classe.

Si può separare la definizione di una classe e la definizione delle sue classi membro in più file se sono definite esternamente.

Il costruttore si può chiamare solo quando l'oggetto viene dichiarato. Inizializza la variabile al momento della dichiarazione, succede una sola volta. Mentre i setters possono essere chiamati più volte.

[Esempio](../esercizi/cylinder.cpp).
