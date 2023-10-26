# 2023-10-26

## Membri virtuali

```cpp
virtual tipo nome_funzione()
```

La parola chiave `virtual` fa in modo che la funzione chiamata sia quella della classe derivata appropriata. Se non esiste la funzione definite nel parent è chiamata invece.

Una funzione virtuale *pura* non fa nulla e la sua presenza rende l'intera classe astratta (*abstract class*). Non sarà più possibile creare oggetti di quella classe, ma solo puntatore ad oggetti creati da classi derivate da quella classe.

```cpp
#include <iostream>
#include <vector>
using namespace std;

// Poligoni definibili con base e altezza
class Polygon { // Polygon è una classe astratta
protected:
    int base, altezza;

public:
    set_values(int a, int b) { base = a; altezza = b; }
    virtual int area() { return 0; }
    virtual int area() = 0; // funzione virtuale pura
    /*
            +----------------+      }
    Polygon | virtual area() | --+  |
            +----------------+   |  | Rectangle 
            | int area()     | <-+  |
            +----------------+      }
    */ 
    void printarea() { cout << this->area() << '\n'; }
};

class Rectangle : public Polygon {
public:
    int area() { return base * altezza ;}
    // int area() { return Polygon::base * Polygon::altezza; }
};

class Triangle : public Polygon {
public:
    int area() { return base * altezza / 2; }
};

int main() {
    Rectangle rect;
    Triangle tr;

    // Polygon * ppoly1 = &rect;
    // Polygon * ppoly2 = &tr;
    // ppoly1 -> set_values(4, 5);
    // ppoly2 -> set_values(4, 5);
    // cout << ppoly1.area() << endl;
    // cout << ppoly2.area() << endl;

    Polygon *ppoly1 = new Rectangle(4, 5);
    ppoly1->area();
    delete ppoly1;

    vector<Polygon *> vppol; // vector<Polygon> NO 
    return 0;
}
```
