/**
 * Rewrite the INSERTION-SORT procedure to sort into nonincreasing
 * instead of nondecreasing order.
 */
#include <stdio.h>

void sort(int list[], size_t size)
{
  int key, j, i;
  for(j = 1; j < size; j++) {
    key = list[j];
    for(i = j - 1; i >= 0 && list[i] < key; i--) {
      list[i + 1] = list[i];
    }
    list[i + 1] = key;
  }
}

void print(int list[], size_t size) {
  int j;
  for(j = 0; j < size; j++) {
    printf("%d ", list[j]);
  }
  printf("\n");
}

int main()
{
  int testcase_a[6] = { 5, 2, 4, 6, 1, 3 };
  int testcase_b[6] = { 31, 41, 59, 26, 41, 58};

  sort(testcase_a, 6);
  sort(testcase_b, 6);

  print(testcase_a, 6); // 6, 5, 4, 3, 2, 1
  print(testcase_b, 6); // 59, 58, 41, 41, 31, 26

  return 0;
}
