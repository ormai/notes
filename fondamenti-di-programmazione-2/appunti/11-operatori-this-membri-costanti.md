# 2023-10-16

Continuazione di [classi](10-classi.md);

```cpp
class Rectangle {
    int width, height;
public:
    Rectangle(int x, int y): width(x), height(y) {};

    int area() {return width * height; }
};

int main() {
    Rectangle obj(3, 4);
    Rectangle *foo, *bar, *baz;

    foo = &obj;

    bar = new Rectangle(5, 6); // crea un oggetto anonimo e passa l'indirizzo a bar

    baz = new Rectangle[2]{{2, 5}, {3, 6}};

    cout << obj.area() << endl;

    cout << foo->area() << endl; // sinonimo di (*foo).area()

    cout << baz[0].area() << ", " << baz[1].area();

    delete bar;
    delete [] baz;
}
```

Gli oggetti possono essere usati tramite funzioni membro e operatori. Gli operatori sono delle funzioni, anche se scritti in modo diverso.

```cpp
struct myClass {

};

int main() {
    myClass a, b, c;
    a = b + c; // b.operator+(c)
}
```

Nel caso un operatore abbia una definizione di default, ridefinendolo si ha un *overloading* degli operatori.

Definire il comportamento di un operator:
```
tipo operator simbolo (parametro) {
    corpo...
}
```

```cpp
class CVector {
    int x, y;
public:
    CVector () {};
    CVector(int _x, int _y): x(_x), y(_y) {};

    friend ostream &operator<<(ostream &, CVector &); // la funzione può accedere ai campi privati
    friend istream &operator>>(istream &, CVector &);

    CVector &operator=(const CVector &param);

    // CVector operator+(const CVector &);

    friend class Rectangle;
};

/* CVector CVector::operator+(const CVector &param) {
    CVector tmp;
    //      a + b
    tmp.x = x + param.x;
    tmp.y = y + param.y;

    return tmp;
} */

ostream &operator<<(ostream &os, const CVector &v) {
    os << '[' << v.x << ',' << v.y << ']';

    return os;
}

istream &operator>>(istream &is, CVector &v) {
    is >> v.x;
    is >> v.y;
}

// overloading dell'operatore + (generico), si fa invece della precedente
CVector operator+(const CVector &lhs, const CVector &rhs) {
    CVector tmp;
    tmp.x = lhs.x + rhs.x;
    tmp.y = lhs.y + rhs.y;
    return tmp;
}

CVector &CVector::operator=(const CVector &param) {
    x = param.x;
    y = param.y;

    return *this; // restituisce l'oggetto stesso.
}

int main() {
    CVector foo(3, 1), bar(1, 2);
    CVector result;

    result = foo + bar;
}
```

## this

`this` usato nel corpo di una classe rappresenta l'indirizzo della stessa classe.

```cpp
Class Dummy {
public:
    bool isItMe(Dummy &param) {
        if (param == this)
            return true;
        return false;
    }
};

int main() {
    Dummy a, *b = &a;

    if (b->isItMe(a)) {;} // darà true
}
```

## Membri statici di una classe

Un membro che persiste invariato tra tutte le istanze della classe.

```cpp
class Dummy {
public:
    static int n; // Ogni volta che un oggetto di Dummy viene creato n è incrementata.

    Dummy() { n++; }
};

int Dummy::n = 0; // L'inizializzazione di una variabile statica avviene fuori dalla classe.

int main() {
    Dummy a;
    Dummy b[5];
    cout << a.n << endl; // stampa 6

    Dummy *c = new Dummy;

    cout << a.n << endl; // stampa 7

    return 0;
}
```

## const per le funzioni membro

```cpp
class MyClass {
public:
    int x;
    MyClass(int val): x(val) {}

    int get() const { return x; }
};

int main() {
    const MyClass foo(10);
    // foo.x = 20; // errore
    cout << foo.x; // ok

    cout << foo.get(); // non funziona (se get() non è const)

    // su foo si possono usare solo le funzioni dichiarate come const
}
```

```
int get() { ... }
int get() const { ... }
const int & get() { ... } // get restituisce un riferimento costante ad un intero, la funzione non è costante
const int & get() const { ... } // la funzione è costante e restituisce un riferimento costante ad intero
```

```cpp
class MyClass {
    int x;
public:
    MyClass(int val): x(val) {}

    const int & get() const { return x; }
    int & get() { return x; }
};

int main() {
    MyClass foo(10);
    const MyClass bar(20);

    // foo.get(); // chiama la seconda get() e restituisce il riferimento ad x
    // quindi si può:
    foo.get() = 25; // nonostante x sia privata

    bar.get() = 30; // // chiama la seconda get(). Quando si prova ad assegnare ad x darà errore.

    cout << foo.get() << endl;
    cout << bar.get() << endl;
}
```
