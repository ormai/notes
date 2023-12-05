/* Dynamic programming */

/* CRLS, Introduction to Algorithms, §14.1 Rod cutting */

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

int cutRodBottomUp(const std::vector<int> &price, int n) {
  std::vector<int> revenue(n + 1);
  revenue[0] = 0;
  for (int j = 1; j <= n; ++j) {
    int q = -1;
    for (int i = 1; i <= j; ++i)
      q = std::max(q, price[i - 1] + revenue[j - i]);
    revenue[j] = q;
  }
  return revenue[n];
}

int cutRodMemoizedAux(const std::vector<int> &price, int n,
                      std::vector<int> &revenue) {
  if (revenue[n] >= 0)
    return revenue[n];

  int q;
  if (n == 0)
    q = 0;
  else {
    q = -1;
    for (int i = 1; i <= n; ++i)
      q = std::max(q, price[i - 1] + cutRodMemoizedAux(price, n - i, revenue));
  }
  revenue[n] = q;
  return q;
}

int cutRodMemoized(const std::vector<int> &price, int n) {
  assert(n <= price.size());
  std::vector<int> revenue(n + 1, -1);
  return cutRodMemoizedAux(price, n, revenue);
}

/* n: the length of the rod being cut */
int cutRodNaive(const std::vector<int> &price, int n) {
  assert(n <= price.size());
  if (n == 0) // length = 0 => price = 0 => revenue = 0
    return 0;
  int optimalSolution = -1;
  for (int i = 1; i <= n; ++i) // i is the length at which to cut the rod
    optimalSolution =
        std::max(optimalSolution, price[i - 1] + cutRodNaive(price, n - i));
  return optimalSolution;
}

int main() {
  const std::vector<int> prices = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
  std::cout << cutRodBottomUp(prices, 10) << std::endl;

  return 0;
}
