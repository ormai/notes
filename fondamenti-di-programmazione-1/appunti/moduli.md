Python è corredato da molte **librerie** che forniscono funzionalità diverse. Queste talvolta si chiamano **moduli**.

I moduli per essere utilizzati devono essere importati.

```python
# Importare tutto il modulo
>>> import math
>>> x = math.sqrt(16) # Così facendo si dorà usare il qualificatore ogni volta che si usa il modulo

# Importare solo alcune funzioni
>>> from math import sqrt, log10
>>> x = sqrt(16) # In questo modo non si usa il qualificatore
>>> z = log10(100)

# A volte si usa questa sintassi per evitare di usare il qualificatore.
>>> from math import *
```

Documentazione:

```python
# Avere una lista delle funzioni e dei metodi nel modulo
>>> import math
>>> dir(math)
['__doc__', '__file__', '__loader__', '__name__', '__package__', '__spec__', 'acos', 'acosh', 'asin', 'asinh', 'atan', 'atan2', 'atanh', 'ceil', 'comb', 'copysign', 'cos', 'cosh', 'degrees', 'dist', 'e', 'erf', 'erfc', 'exp', 'expm1', 'fabs', 'factorial', 'floor', 'fmod', 'frexp', 'fsum', 'gamma', 'gcd', 'hypot', 'inf', 'isclose', 'isfinite', 'isinf', 'isnan', 'isqrt', 'lcm', 'ldexp', 'lgamma', 'log', 'log10', 'log1p', 'log2', 'modf', 'nan', 'nextafter', 'perm', 'pi', 'pow', 'prod', 'radians', 'remainder', 'sin', 'sinh', 'sqrt', 'tan', 'tanh', 'tau', 'trunc', 'ulp']

# Consultare la documentazione di tutto il modulo
>>> help(math)
>>> help(math.sqrt)
```