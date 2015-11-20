/**
 * 2.3-5 - Binary search
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * Argument that binary search complexity is O(lgn) on worse case.
 *
 * Worst case scenario happens when the thing we are looking for is not in
 * our list, and also with every iteration we half the size of our array, then:
 *
 * T(n) = 1 , if n = 1,
 * T(n) = T(n/2) + 1 , if n = 2^k and k > 1
 *
 * We assume that -> F(k) = T(2^k) = lg2^k
 * Then;
 * F(k+1) = T(2^k+1) = T((2^k+1)/2) + 1
 * F(k+1) = T(2^k+1) = T(2^k) + 1
 * F(k+1) = T(2^k+1) = lg2^k + 1
 * F(k+1) = T(2^k+1) = lg2^k + lg 2
 * F(k+1) = T(2^k+1) = lg2^k+1
 *
 * We showed that T(n) = O(lgn) on worst case scenario.
 */
int * search(int needle, int *list, size_t size)
{
  int *result = NULL;
  int *remainder;
  size_t middle, i, j;

  if(size == 0) {
    return result;
  }

  if(size == 1) {
    if(needle == list[0]) {
      result = &list[0];
    }
    return result;
  }

  middle = size / 2;

  if(needle == list[middle]) {
    result = &list[middle];
  } else if(needle > list[middle]) {
    remainder = malloc(sizeof(int) * (size - middle - 1));
    i = 0;
    for(j = middle + 1; j < size; j++) {
      remainder[i] = list[j];
      i++;
    }
    result = search(needle, remainder, size - middle - 1);
    free(remainder);
  } else {
    remainder = malloc(sizeof(int) * middle);
    for(j = 0; j < middle; j++) {
      remainder[j] = list[j];
    }

    result = search(needle, remainder, middle);
    free(remainder);
  }

  return result;
}

int main()
{
  int *result;
  int testcase_a[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  int testcase_b[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

  result = search(5, NULL, 0);
  printf("Should not find for empty list: %d\n", result == NULL);

  result = search(2, testcase_a, 9);
  printf("Should find 2 in testcase_a: %d\n", result != NULL);

  result = search(9, testcase_a, 9);
  printf("Should find 9 in testcase_a: %d\n", result != NULL);

  result = search(11, testcase_a, 9);
  printf("Should not find 11 in testcase_a: %d\n", result == NULL);

  result = search(1, testcase_b, 10);
  printf("Should find 1 in testcase_b: %d\n", result != NULL);

  result = search(7, testcase_b, 10);
  printf("Should find 7 in testcase_b: %d\n", result != NULL);

  result = search(11, testcase_b, 10);
  printf("Should not find 11 in testcase_b: %d\n", result == NULL);

  return 0;
}
