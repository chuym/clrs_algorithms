/**
 * Input: A sequence of n numbers A = [a1, a2, .. , an] and
 * a value v.
 * Output: An index i such that v = A[i] or the special value NIL
 * if v does not appear in A.
 */
#include <stdio.h>

/**
 * Invariant: At the beginning, we have the array where we want to find
 * if some value exists, we also have the value we want to find and
 * in the function we initialize the returned value to NULL.
 *
 * Maintenance: Next, we begin inspecting the array, starting at
 * index 0 and incrementing by 1 until we reach the size of the array.
 * If the value at index i is the same as v, then we assign the returned
 * variable to a reference to that value and break the loop. If not
 * we keep repeating the procedure.
 *
 * Termination: The loop terminates when either we finished inspecting
 * all the indices of the array or if we found the value at some index
 * i < A.length. We return whatever value stored in the returned var,
 * which holds either NULL if the procedure didn't find a matching value
 * or a reference of the found value.
 *
 */
int * search(int list[], size_t size, int v)
{
  int * found = NULL;
  int i;
  for(i = 0; i < size; i++) {
    if(list[i] == v) {
      found = &v;
      break;
    }
  }

  return found;
}

int main() {
  int testcase_a[6] = { 5, 2, 4, 6, 1, 3 };
  int testcase_b[6] = { 31, 41, 59, 26, 41, 58};

  if(search(testcase_a, 6, 9) != NULL) {
    printf("Found %d in testcase_a!\n", 9);
  } else {
    printf("Could not find %d in testcase_a!\n", 9);
  }

  if(search(testcase_b, 6, 26) != NULL) {
    printf("Found %d in testcase_b!\n", 26);
  } else {
    printf("Could not find %d in testcase_b!\n", 26);
  }
}
