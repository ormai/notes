# 2023-09-28

Overloading di funzioni: due funzioni con stesso nome e stesso tipo di ritorno ma diversi parametri.

```cpp
void f(int n);
void f(int m1, int m2);

void f(int n); // ri-dichiarare questa sarebbe un errore

void f(float n); // questa va bene
```

Il compilatore chiamerà una delle due in base agli argomenti usati nella chiamata.

```cpp
void f(auto n); // fattibile ma rischioso
```

## Variabili statiche

(*GNU C reference manual, §2.8, §2.9*)

```cpp
int count_calls() {
    static int count = 0; // la variabile persiste anche dopo il termine della funzione
    return ++count;
}

int main() {
    for (int i = 0; i != 10; i++) {
        cout << count_calls() << endl; // stampa 1,2,...,10
    }
    return 0;
}
```

Le variabili `static` sono diverse dalle globali in quanto sono visibili solo nella funzione.
