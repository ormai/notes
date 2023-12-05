# 2023-10-18

Il *distruttore* è chiamato quando l'oggetto di quella certa classe giunge al fine della sua vita.

```cpp
class Example {
    int *ptr;
    int dim;
public:
    Example(int n) {
        ptr = new int[n];
        dim = n;
    }
    ~Example() { delete [] ptr; } // destructor
    Example(const Example &x) { // costruttore di copia
        dim = x.dim;
        ptr = new int[dim];
        for(int i = 0; i < dim; i++)
            ptr[i] = x.ptr[i];
    }
    Example &operator=(const Example &x) { // solo assegnamento
        dim = x.dim;
        ptr = new int[dim];
        for(int i = 0; i < dim; i++)
            ptr[i] = x.ptr[i];

        return *this;
    }
};

int main() {
    Example e(10); // il distruttore di e è chiamato alla fine di main
    Example *pe = new Example(30);

    Example e3 = e; // e3 è creato come copia di e (costruttore di copia)
    e = e3; // si usa l'operatore =, il cui comportamento è già definito nella classe

    delete pe; // il distruttore dell'oggetto a cui punta pe viene chiamato esplicitamente

    return 0;
}
```

## Class template

La classe è definita con un tipo generico. Solo quando il template è utilizzato il tipo da usare viene specificato.

```cpp
template <class T> // T è un segnaposto per il tipo
class mypair {
    T a, b;
public:
    // mypair(T first, T second): a(first), b(second); // chiama il costruttore di copia
    mypair(T first, T second) { // usa l'operatore di assegnamento
        a = first;
        b = second;
    }
    T getMax();
};

template <class T>
T mypair<t>::getMax() {
    T retval;
    if (a > b)
        retval = a;
    else
        retval = b;

    return retval;
}

int main() {
    mypair<int> myObject(100, 75);

    cout << myObject.getMax();

    return 0;
}
```
