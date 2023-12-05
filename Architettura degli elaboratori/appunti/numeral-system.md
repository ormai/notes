---
aliases: 
  - "numeral system"
  - "sistema di numerazione"
---

# Numeral systems

A numeral system is a writing system for expressing numbers.

## Base 10 

The Hindu-Arabic system is a *base ten* system, because it uses the digits $0,\ 1,\ 2,\ 3,\ 4,\ 5,\ 6,\ 7,\ 8,\ 9$. It also is a **positional** system because the value of each digit in a number depends on its position. The leftmost digit is the **least significant digit**, while the rightmost is the **most significant digit**.


$$32847_{10}=3\cdot10^4+2\cdot10^3+8\cdot10^2+4\cdot10^1+7\cdot10^0$$

## Binary

Base two is the number system of digital systems. Mainly because it is easy to build circuits with **two stable states**.

In binary the least significant digit is called **least significant bit** (LBS), while the most significant one is called **most significant bit** (MSB).

## Base n

A base $n$ numeral systems will be composed of $n$ different digits. Each digit in a number of base $n$ represents a power of $n$

## Conversion

Conversion from base $4$ to base $10$:

$$1302_4=1\cdot4^3+3\cdot4^2+0\cdot4^1+2\cdot4^0=114_{10}$$

To go from base $10$ to base $n$ first number must be divided by $n$ repeatedly until it is less or equal than $0$ while keeping track of the remainder from bottom to top.

From base $10$ to base $8$
- $94883\div 8 = 11860,\ \sf reminder:\ 3$
- $11860\div 8 = 1482,\ \sf reminder:\ 4$
- $1482\div 8 = 185,\ \sf reminder:\ 1$
- $185\div 8 = 23,\ \sf reminder:\ 1$
- $23\div 8 = 2,\ \sf reminder:\ 7$
- $2\div 8 = 0,\ \sf reminder:\ 2$

$$94883_{10}=271143_8$$

### From Binary to decimal

The conversion of a binary numbers varies based on the[[data#Sign magnitude|sign]] of the number itself.

1. If the most significant bit is $1$:
    1. find the [two's complement](data.md#Complement)
    2. convert the complement to base $10$
    3. add a negative sign
2. otherwise
    1. convert to base $10$

### Negative decimal to binary

1. remove the sign
2. convert to binary
3. take the [two's complement](data.md#Complement)
