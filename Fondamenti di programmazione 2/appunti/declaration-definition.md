```cpp
extern int i; // declaration
int j; // declaration and definition
```

`i` is declared but not defined. Memory is not allocated for `i`.

Declaration is done in order to make the name known. It's useful when sharing code between files. Initializing i would override the `extern`. Doing so in a function is an error. The declaration can happen many times across files. The definition is done exactly one time.

Definition is also a declaration, allocates storage for the object and may initialize it with a default value.

```cpp
int l; // default value (0)

int main() {
    int k; // k is declared and defined but its value is undefined
}
```
