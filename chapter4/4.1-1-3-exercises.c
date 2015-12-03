#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 *
 * 1. What does the FIND-MAXIMUM-SUBARRAY function return when all elements of A are
 * negative?
 * r. It return the biggest element in the array.
 *
 * 2. What problem size n_0 gives the crossover point at which the recursive algorithm
 * beats the brute-force algorithm? Change the base case to use the brute force when n
 * is sufficiently small
 *
 * r. In computer, the n_0 is 17. It changes the crossover point.
 */

#define CROSSOVER 17

int * find_max_crossing_subarray(int * A, int low, int mid, int high)
{
  int left_sum = A[mid], right_sum = A[mid+1];
  int sum = 0;
  int max_left = mid, max_right = mid + 1, i;
  static int result[3];

  i = -500;
  for(i = mid; i >= low; i--) {
    sum += A[i];
    if(sum > left_sum) {
      left_sum = sum;
      max_left = i;
    }
  }

  sum = 0;
  for(i = mid + 1; i <= high; i++) {
    sum += A[i];

    if(sum > right_sum) {
      right_sum = sum;
      max_right = i;
    }
  }

  result[0] = max_left;
  result[1] = max_right;
  result[2] = left_sum + right_sum;
  return result;
}

int * find_maximum_subarray_bf(int *A, int low, int high)
{
  int max_sum = A[0];
  int current_sum, max_left = 0, max_right = 0;
  size_t i, j;
  for(i = low; i <= high - 1; i++) {

    current_sum = A[i];
    if(max_sum < current_sum) {
      max_sum = current_sum;
      max_left = max_right = i;
    }
    
    for(j = i+1; j <= high; j++) {
      current_sum += A[j];
      if(max_sum < current_sum) {
        max_sum = current_sum;
        max_left = i;
        max_right = j;
      }
    }
  }

  static int result[3];
  result[0] = max_left;
  result[1] = max_right;
  result[2] = max_sum;

  return result;
}


int * find_maximum_subarray_mixed(int * A, int low, int high)
{
  static int *result;
  if(low == high) {
    static int base[3];
    base[0] = low;
    base[1] = high;
    base[2] = A[low];

    return base;
  } else if (high - low <= CROSSOVER) {
    return find_maximum_subarray_bf(A, low, high);
  } else {
    int mid = (high + low) / 2;
    static int *left;
    static int *right;

    left = find_maximum_subarray_mixed(A, low, mid);
    right = find_maximum_subarray_mixed(A, mid + 1, high);
    result = find_max_crossing_subarray(A, low, mid, high);

    if(left[2] >= right[2] && left[2] >= result[2]) {
      return left;
    } else if(right[2] >= left[2] && right[2] >= result[2]) {
      return right;
    } else {
      return result;
    }
  }
}

int * find_maximum_subarray(int * A, int low, int high)
{
  static int *result;
  if(low == high) {
    static int base[3];
    base[0] = low;
    base[1] = high;
    base[2] = A[low];

    return base;
  } else {
    int mid = (high + low) / 2;
    static int *left;
    static int *right;

    left = find_maximum_subarray(A, low, mid);
    right = find_maximum_subarray(A, mid + 1, high);
    result = find_max_crossing_subarray(A, low, mid, high);

    if(left[2] >= right[2] && left[2] >= result[2]) {
      return left;
    } else if(right[2] >= left[2] && right[2] >= result[2]) {
      return right;
    } else {
      return result;
    }
  }
}

int * find_maximum_subarray_linear(int * A, size_t n)
{
  int sum = A[0];
  int max = A[0];
  int i;
  int left_index = 0, right_index = n;

  for(i = 1; i <= n; i++) {
    if(sum < 1 && A[i] > 0) {
      sum = max = A[i];
      left_index = right_index = i;
    } else if(sum + A[i] > max) {
      sum += A[i];
      max = sum;
      right_index = i;
    } else {
      sum += A[i];
    }
  }

  static int result[3];
  result[0] = left_index;
  result[1] = right_index;
  result[2] = max;

  return result;
}

int main()
{
  int testcase[75] = { 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4 };

  int i;
  
  clock_t begin, end;
  printf("Size 75\n");
  begin = clock();
  for(i = 0; i < 10000; i++) {
    find_maximum_subarray(testcase, 0, 74);
  }
  end = clock();
  printf("Divide and Conquer approach (10000 times): %3.9f\n", (double)(end - begin) / CLOCKS_PER_SEC);

  begin = clock();
  for(i = 0; i < 10000; i++) {
    find_maximum_subarray_bf(testcase, 0, 74);
  }
  end = clock();
  printf("Brute Force approach (10000 times): %3.9f\n", (double)(end - begin) / CLOCKS_PER_SEC);

  begin = clock();
  for(i = 0; i < 10000; i++) {
    find_maximum_subarray_mixed(testcase, 0, 74);
  }
  end = clock();
  printf("Mixed approach (10000 times): %3.9f\n", (double)(end - begin) / CLOCKS_PER_SEC);

  begin = clock();
  for(i = 0; i < 10000; i++) {
    find_maximum_subarray_linear(testcase, 74);
  }
  end = clock();
  printf("Linear approach (10000 times): %3.9f\n", (double)(end - begin) / CLOCKS_PER_SEC);

  return 0;
}
