/**
 * Exercise 2.2-2 - Selection sort
 *
 * Input: A list of numbers A of size n
 * Ouput: The list A' of size n with its elements sorted.
 */
#include <stdio.h>

/**
 * Invariant: At the beginning, we have the array A with unsorted values
 * and j = 2 where we start sorting. When A.length = 1, the array is
 * already sorted and return it as it is.
 *
 * Maitenance: With every iteration, elements from A[1..j-1] will be
 * sorted. We then find a value in A[j+1..n] A[i] such that A[i] <= A[j]
 * if such value exists, then A[j] <=> A[i], if not then A[j] remains
 * as it is because A[j] is <= than any A[j+1..n], at wich point
 * A[1..j] will be sorted.
 *
 * Termination: The loop terminates when we finished inspecting all
 * values in A[1..n-1], since at the end of every iteration A[1..j] is
 * sorted and we exit the loop at n - 1, then A[1..n-1] is sorted, and
 * since at the end of the loop A[j] <= A[j+1..n], then A[n-1] must be
 * lower than A[n], then A[1..n] is sorted.
 */
void sort(int A[], size_t size)
{
  int j, k;
  int lowest, holder;
  for(j = 0; j < size - 1; j++) {
    lowest = j;
    for(k = j + 1; k < size; k++) {
      if(A[lowest] > A[k]) {
        lowest = k;
      }
    }
    holder = A[j];
    A[j] = A[lowest];
    A[lowest] = holder;
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

  print(testcase_a, 6); // 1, 2, 3, 4, 5, 6
  print(testcase_b, 6); // 26, 31, 41, 41, 58, 59

  return 0;
}

/**
 * Questions:
 * Q. Why does it need to run only for the first n - 1 elements?
 * A. Because at the end of every iteration A[1..j] is sorted and it is
 * guaranteed that A[j] is lower than any values in A[j+1..n]. At the
 * end of the loop we have that j = n - 1, then A[1..n-1] is sorted,
 * and we also have that A[n-1] is <= A[n], then A[1..n] is sorted.
 *
 * Q. Give the best-case and worst-case running times of selection sort
 * in O-notation.
 * Best case and worst case are both O(n^2).
