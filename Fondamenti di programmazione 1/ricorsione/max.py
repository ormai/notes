# Find the max in a list

def main():
  arr = [9, -53, 44, 2, -7]
  print(maxR(arr, 1, arr[0]))

def maxR(L, inf, max):
  if inf == len(L):
    return max
  if max < L[inf]:
    max = L[inf]

  return maxR(L, inf + 1, max)

main()
