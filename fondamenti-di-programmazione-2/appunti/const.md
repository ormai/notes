# Const qualifier (C++ Primer, §2.4)

```cpp
const int n = 42; // the value of n cannot be changed
```

Const objects must always be initialized.

Const objects are local to a file. To share a const between file without redefining the same one in every file use:

```cpp
extern const int someVar = getTheVar();
```

One time, and then, in every other file

```cpp
extern const int someVar;
```

## Reference to const

```cpp
const int i = 1024;
const int &ri = i;
```

`ri` can't be used to change the value of `i`. Declaring `ri` without `const` is an error.

---

It is possible to make a *reference to const* to something which is not const. The `const` used for the reference restricts only what can be done with the reference.

```cpp
int i = 42;
const in &ri = i;
```
`i` cannot be changed through `ri` but it can be still changed directly.

## Pointer to const

```cpp
const double pi = 3.141592654;
const double *pPi = &pi;
```

The address of a const object may only be stored in a const pointer. `pPi` cannot be used to change `pi`. But `pPi` can be changed to point to a different const object of type `double`.

---

A *pointer to const* can point to a non const object:

```cpp
double n = 5.86;
const double *pn = &n;
```

`pn` can't be used to change `n` even through `n` can be changed directly. The address that contained in `pn` **can still change**.

### Const pointers

A pointer being an object can itself be const.

A const pointer must be initialized and the address that it holds (value) cannot change.

```cpp
int i = 0;
int *const pi = &i; // <- const pointer
```

`i` can change through `pi` but the object to which it points can't change.

```cpp
const int i = 42;
const int *const pi = &i;
```

Here `pi` is a `cons pointer to const*
