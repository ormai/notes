#include <iostream>

using std::cout, std::endl;

void printArray(int input[], unsigned size) {
  cout << '[';

  for (int i = 0; i < size; i++) {
    cout << input[i];
    if (i + 1 != size)
      cout << ", ";
  }

  cout << ']' << endl;
}

void swap(int &n, int &m) {
  n += m;
  m = n - m;
  n -= m;
}

void auxiliaryInsertionSort(int input[], int start, int end) {
  for (int i = start; i <= end; i++) {
    int tmp = input[i], j = i - 1;

    while (j >= 0 && input[j] > tmp) {
      input[j + 1] = input[j];
      j--;
    }

    input[j + 1] = tmp;
  }
}
