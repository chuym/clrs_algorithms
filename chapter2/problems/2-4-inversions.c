/**
 * Let A[1..n] be an array of n distinct numbers. If i < j and A[i] > A[j], then the
 * pair (i, j) is called an inversion of A.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct List {
  struct List *previous;
  struct List *next;
  int pair[2];
} List;

List * as_pair(int i, int j) {
  List *pair = malloc(sizeof(List));
  pair->pair[0] = i;
  pair->pair[1] = j;
  pair->previous = NULL;
  pair->next = NULL;

  return pair;
}

List * find_inversions(int numbers[], size_t n)
{
  List *pairs = NULL;
  List *next = NULL;
  size_t i, j;
  for(i = 0; i < n - 1; i++) {
    for(j = i + 1; j < n; j++) {
      if(numbers[i] > numbers[j]) {
        next = as_pair(i + 1, j + 1);
        if(pairs == NULL) {
          pairs = next;
        } else {
          pairs->next = next;
          next->previous = pairs;
          pairs = next;
        }
      }
    }
  }

  while(pairs != NULL && pairs->previous != NULL) {
    pairs = pairs->previous;
  }

  return pairs;
}

void print_list_contents(List *pairs) {
  size_t n;
  while(pairs != NULL) {
    printf("(%d, %d)\n", pairs->pair[0], pairs->pair[1]);
    pairs = pairs->next;
  }
}


int main()
{
  int testcase[5] = { 2, 3, 8, 6, 1 };
  int testcaseb[5] = { 5, 4, 3 , 2 , 1 };
  List *pairs = find_inversions(testcaseb, 5);
  print_list_contents(pairs);
  return 0;
}

/**
 * a. The inversions for array { 2 , 3 , 8, 6, 1 } are:
 * (1, 5), (2, 5), (3, 4), (3, 5), (4, 5)
 *
 * b. What array with elements from set {1, 2, ... , n } has the most
 * inversions? how many does it have?
 * The array with the most inversions is the one in reverse order, that
 * is, {n, n - 1, ... , 1} and the number of inversions is
 * SUM_1^{n-1} = i
 *
 * c. What is the relationship between the running time of insertion
 * sort and the number of inversions in the input array? Justify your
 * answer.
 *
 * The more inversions an array have, the less time insertion sort takes.
 * this is because, A[i] has many inversions, it means that many numbers
 * between A[j..n] that are smaller than A[i], and that, in general,
 * higher numbers are at the beginning of the array. Insertion sort runs
 * fastest when the array is in inverse order, because we have to move A[i]
 * to the right until A[i+1] is lower or equal to A[i]. The number of
 * inversions on array A is exactly the number of shifts avoided when doing
 * insertion sort.
 *
 */
