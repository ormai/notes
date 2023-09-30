---
aliases:
  - ricorsione
---

# Recursion

<span class="dcaps">A</span> function that calls itself is said to be *recursive*.^[Pyeatt, Ughetta. “5.4.8. Recursive functions” Arm 64-Bit Assembly Language, Newnes, 2020, p. 137.]

Recursion is a programming method to solve problems. A recursive [[functions|function]] is a function that calls itself, each time simplifying the problem until a **base case** is reached. Without a base case the function doesn't terminate.

Basic recursive function scheme:

```
def function()
  if something: # Check for the base case
    return 0
  else:
    return function()
```

A function is *direct recursive* if it calls itself. A function is called *indirect recursive* if it calls another function that calls the first one.

Most recursive [[algorithm]] can be implemented by [[iterazione|iteration]].^[[Wikipedia: Recursion versus iteration](https://en.wikipedia.org/wiki/Recursion_%28computer_science%29#Recursion_versus_iteration)]  A problem that cannot be resolved by iteration is that of finding [[anagramma|permutations]].

```python
def fibonacci(n):
    if n in (1, 2): # Starting point. The initial value is 1 (Fibonacci series: 1, 1, 2, 3, 5, ...)
        return 1

    return fibonacci(n - 1) + fibonacci(n - 2)
```

A recursive [[algorithm|program]] works by solving a problem using simple data and the combining the results. 