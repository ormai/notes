# Calculate the factorial of n

def main():
  userInput = int(input("Give me a number: "))
  print("The factorial of %d is %d." % (userInput, factorial(userInput)))

def factorial(n):
  if n == 0 or n == 1: 
    return 1

  return n * factorial(n - 1)

main()
