# Tuple

A tuple is an **immutable** sequence. An empty tuple is denoted by a pair of parenthesis `()`, a singleton tuple by a comma `a,` or `(a,)`. Except for the empty tuple, parenthesis are optional: `a, b, c` is the same as `(a, b, c)`. Is the comma that makes the tuple. But parentheses are useful to avoid syntactic ambiguity: `function(a, b, c)` is different than `function((a, b, c`.
The `tuple()` constructor builds a tuple with the elements in the same order as the sequence given as argument.^[[python.org: Tuples](https://docs.python.org/3/library/stdtypes.html?highlight=tuple#common-sequence-operations)]

```python
>>> tuple()
()
>>> tuple('ciao')
('c', 'i', 'a', 'o')
>>> tuple( [1, 2, 4] )
(1, 2, 3)
```

The tuple supports all the operations for immutable sequence.^[[python.org: Common Sequence Operations](https://docs.python.org/3/library/stdtypes.html?highlight=tuple#common-sequence-operations)]

Tuple can be used two swap the value of two or more variables.

```python
a = 3
b = 16
c = 14

a, c, d = 14, 3, 16
```

They are also useful for [[functions|functions]] to take in a [[functions#Numero variabile di parametri|variable number of arguments]] and to `return` multiple values.

```python
return (a, b)
```