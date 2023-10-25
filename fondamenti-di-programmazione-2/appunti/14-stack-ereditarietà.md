# 2023-10-25

## stack

**Last In First Out**.

Operazioni su stack:
- push (aggiunge un elemento sulla pila)
- top (restituisce l'elemento in cima alla pila)
- pop (rimuove l'elemento in cima alla pila)
- size (restituisce il numero di elementi nella pila)
- empty (`true` se la pila è vuota, altrimenti `false`)


```cpp
template <class T>
class Stack {
private:
    vector<T> stack;
    Stack() {}

    bool push(const T &newElement) {
        stack.push_back(newElement);
        return true;
    }

    T top() const { return stack.back(); }

    void pop() { stack.pop_back(); }

    int size() const() { return stack.size(); }

    bool empty() { return size() == 0; }
};
```

## queue (coda)

**Last In First Out**

Esempio: parentesizzazione di una formula matematica.

$(x + (y * 3) + ((x^2 - 2) + 2z))$

Ad ogni parentesi aperta deve seguire una parentesi chiusa.

---

Qualsiasi funzione ricorsiva può essere riscritta iterativamente usando eventualmente uno stack.

```cpp
int main() {
    string expr;
    auto len = string.size();
    Stack<int> s;

    getline(cin, expr);

    bool esci = false;

    for (decltype(len) i = 0; i < len && !esci; i++)
        if (expr[i] == '(')
            s.push(i);
        else if (expr[i] == ')')
            if (s.empty)
                esci = true;
            else {
                cout << "La parentesi in posizione " << s.top() << " si chiude in " << i;
                s.pop();
            }

    if (esci || !s.empty())
        cout << "L'espression non è ben parentesizzata";
    else
        cout << "Ben parentesizzata;"

    return 0;
}
```

## Ereditarietà

Una classe estende (specializza) il comportamento di un'altra classe.

```cpp
class NomeClasseDerivata: specificatore NomeClasseBase {};
```

Lo specificatore può essere `public`, `protected` o `private`.

La classe *figlia* deriva i membri della classe *genitore*, ciò in base allo specificatore di visibilità.

| Accesso                      | public | protected | private |
|----------------------------- | ------ | --------- | ------- |
| Membri della stessa classe   | si     | si        | si      |
| Membri della classe derivata | si     | si        | no      |
| Non membri                   | si     | no        | no      |

```cpp
class Polygon {
protected:
    int width, height;
public:
    set_values(int a, inb b) { width = a; height = b; }
};

class Rectangle: public Polygon {
public:
    unsigned area() { return width * height; }
};

class Triangle: public Polygon {
    unsigned area() { return width * height / 2; }
};

int main() {
    Rectangle rect;
    Triangle tr;

    // puntatori di tipo base che puntano ad oggetti di classi derivate
    // si può fare ma i puntatori possono usare solo i membri definiti nella classe base


    Polygon *ppoly1 = &rect;
    ppoly1->set_values(3, 4); // ok
    ppoly1->area(); // non si può perché non è definita in Polygon
}
```

I container possono contenere dati di un unico tipo. Un container di un tipo base può contenere tutti gli oggetti di classi derivata ma si potranno usare soltanto i membri della classe base.

Le dichiarazioni `friend` non vengono ereditate.

Costruttori:

```cpp
class Mother {
public:
    Mother() { cout << "Mother :)"; }
    Mother (int x) { cout << "Mother con parametro " << x; }
};

class Daughter: public Mother {
public:
    Daughter(int x) { cout << "Sono in Daughter con parametro."; }
};

class Son: public Mother {
public:
    Son(int x) : Mother(x) { cout << "Son con parent"; }
};

int main() {
    Daughter Kelly(0); // è chiamato prima il costruttore di Mother e poi quello di Daughter
    Son bud(0); // Prima Mother con parametri, poi Son con parametri

    return 0;
}
```
