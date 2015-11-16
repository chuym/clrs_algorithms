/**
 * 2.3-2 - Rewrite MERGE procedure so that it does not use
 * sentinels.
 */
#include <stdio.h>
#include <stdlib.h>

int * merge(int *left, int *right, size_t lsize, size_t rsize)
{
  int *result = malloc(sizeof(int) * (lsize + rsize));
  int l = 0, r = 0, c = 0;

  while(l < lsize || r < rsize) {
    if(l >= lsize) {
      result[c] = right[r];
      r++;
    } else if(r >= rsize) {
      result[c] = left[l];
      l++;
    } else if(left[l] > right[r]) {
      result[c] = right[r];
      r++;
    } else {
      result[c] = left[l];
      l++;
    }
    c++;
  }

  return result;
}

int * mergesort(int *list, size_t size)
{
  if(size == 1) {
    return list;
  }

  size_t left_size = size / 2;
  size_t right_size = size - left_size;
  int *left = malloc(sizeof(int) * left_size);
  int *right = malloc(sizeof(int) * right_size);
  int i;

  for(i = 0; i < left_size; i++) {
    left[i] = list[i];
  }

  for(i = left_size; i < size; i++) {
    right[i - left_size] = list[i];
  }

  int *result = merge(mergesort(left, left_size), mergesort(right, right_size), left_size, right_size);

  free(left);
  free(right);

  return result;
}

int main()
{
  int i;
  int *result;
  int testcase_a[6] = { 5, 2, 4, 6, 1, 3 };
  int testcase_b[8] = { 31, 41, 59, 26, 41, 58, 99, 11};

  result = mergesort(testcase_a, 6);

  for(i = 0; i < 6; i++) {
    printf("%d ", result[i]);
  }
  printf("\n");
  free(result);

  result = mergesort(testcase_b, 8);

  for(i = 0; i < 8; i++) {
    printf("%d ", result[i]);
  }
  printf("\n");
  free(result);

  return 0;
}
