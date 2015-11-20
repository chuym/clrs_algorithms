#include <stdio.h>
#include <stdlib.h>

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

int pair_exists(int x, int *set, size_t size)
{
  int i, j, k, complement;
  int *subset = NULL;

  for(i = 0; i < size; i++) {
    complement = x - set[i];
    subset = malloc(sizeof(int) * (size - (i + 1)));
    k = 0;
    for(j = i + 1; j < size; j++) {
      subset[k] = set[j];
      k++;
    }
    if(search(complement, subset, size - (i + 1)) != NULL) {
      free(subset);
      return 1;
    }
    free(subset);
  }

  return 0;
}

int main()
{
  int testcase_a[9] = { 1, 3, 5, 7, 9, 11, 13, 15, 17 };
  int testcase_b[4] = { 2, 4, 6, 8 };

  printf("Should not find pair for 33: %d\n", pair_exists(33, testcase_a, 9) == 0);
  printf("Should not find pair for 400: %d\n", pair_exists(400, testcase_a, 9) == 0);
  printf("Should find pair for 14: %d\n", pair_exists(14, testcase_a, 9) == 1);
  printf("Should find pair for 32: %d\n", pair_exists(32, testcase_a, 9) == 1);

  printf("Should not find pair for 11: %d\n", pair_exists(11, testcase_b, 4) == 0);
  printf("Should not find pair for 1: %d\n", pair_exists(1, testcase_b, 4) == 0);
  printf("Should find pair for 10: %d\n", pair_exists(10, testcase_b, 4) == 1);
  printf("Should find pair for 14: %d\n", pair_exists(14, testcase_b, 4) == 1);

  return 0;
}
