# Computer data

The [bit](bit.md) is the basic unit of data for digital computers. A bit can be either $0$ or $1$. To represent numbers bigger than $1$ bits are combined.

Computers today group $8$ bits, forming a **byte**. Some computers group $4$ bits into a **nibble**, wich represent exactly an hexadecimal digit.

Computers also group bits into 16, 32 and 64.

The CPU has a *default word size*. Recently the default word size is becoming of 64 bits.

## Representing integers

To interpret a group of bits as an **unsigned integer** each bit is weighted by a power-of-two. The value of the group of bits is the sum of the bits multiplied by their weights.

$11111110$ as an unsigned integer is $254$, because

$$1\cdot2^7+1\cdot2^6+1\cdot2^5+1\cdot2^4+1\cdot2^3+1\cdot2^2+1\cdot2^1+0\cdot2^0=$$

$$128+64+32+16+8+4+2+0=254_{10}$$

Positive and negative integers can be represented in different ways.

### Sign magnitude

The most significant bit is used to stor#e the sign of the number while the rest of the bits store the magnitude of the number. If the MSB is $0$ the integer is positive, if it si $1$ then it is negative.

$11111110$ as a signed integer is $-126$.

This way of representing integers is easier for humans but addition and subtraction becomes harder for the CPU. Furthermore representing integers with a sign causes the existence of two zeros ($+0$ and $-0$).

### Offset binary, Excess-K

The unsigned decimal number $x$ is represented as $x-k$ where $k$ is the *bias* and usually it is $(2^{n-1}-1)$, for a $n$-bit number. $k$ is half the largest possible number (-1).

This method is used to store exponent in floating-point numbers.

### Complement

The complement of a number is a number that when added to the first makes it "whole". It is efficient to represent a negative number as the *radix complement* of their positive counterpart.^[https://en.wikipedia.org/wiki/Method_of_complements]

Subtraction of a number works by adding its complement. The subtraction $[x-y]_{10}$ can be done by adding to $y$ the nine's complement of $x$ and then doing the nine's complement of the result.

> [!example] Example of subtraction
> To do $[54-21]_{10}$ the nine's complement of $54$ is calculated and then added to $21$. $$21+45=66$$
> The nines' complement of $66$ is $\boxed{33}$.
> NOTE: the ten's complement is the nines' complement plus one.

The complement of an $n$-digit number $y$ in base $b$ is $$C(y_b)=b^n-y_b$$

The *diminished radix complement* will be $$(b^n-1)-y$$ and it is easier to calculate in an arbitrary base by using a complement table.

> [!tip] One's and Two's complement
> The one's complement of a base two number is done by *flipping* each digit. It is similar to the logical **not**.
> The two's complement is obtained by adding $1$ to the one's complement.<br>
> So the one's complement of $01100111$ will be $10011000$, while the two's complement will be $10011001$