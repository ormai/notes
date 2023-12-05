# Calculate the fibonacci sequence of n

def main():
  n = int(input("Give me the upper limit: "))
  print(fibonacci(n))

def fibonacci(n):
  if n == 1 or n == 2:
    return 1

  return fibonacci(n - 1) + fibonacci(n - 2)

main()
