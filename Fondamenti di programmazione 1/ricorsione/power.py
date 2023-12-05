# Calculate the power of b to the n

def main():
  b = int(input("Give me the base: "))
  e = int(input("Give me the exponent: "))
  print(power(b, e))

def power(base, exponent):
  if exponent == 0:
    return 1

  return base * power(base, exponent - 1)

main()
