/**
 * Consider the problem of adding two n-bit binary integers, stored
 * in two n-elements arrays A and B. The sum of the two integers should
 * be stored in binary form in an (n + 1)-element array C. State the
 * problem formally and write pseudocode for adding the two integers.
 */

/**
 * Input: Two n-sized arrays with possible values 1,0 representing an
 * n-bit integer.
 * Output: An array representing the sum in binary form of the inputs
 */
#include <stdio.h>

/**
 * Invariant: At the beginning, we have two arrays of the same size A and
 * B and a third one C of (size+1) length and initialized to all 0s.
 *
 * Maintenance: Next, we go trough all indices 'i' of A and B and inspect
 * the value at A[i] and B[i] and set C[i] in the following fashion: if
 * both A[i] and B[i] are 1, then we set an carry helper value as 1
 * we set C[i] as 0 unless there already is a carry, which in that case
 * C[i] will be 1. If either A[i] or B[i] is 1, then C[i] is 1 unless
 * carry is 1, in which case C[i] is 0. If both A[i] and B[i] are 0,
 * then C[i] is 0 unless carry is 1, in which case C[i] is 1 and we set
 * carry to 0.
 *
 * Termination: The loop terminates when all indices i of A and B are
 * inspected and the appropiate C[i] values are set as per the
 * maintenance rule. If we have a carry at the end of the loop, then
 * C[n+1] is 1, otherwise it's 0. At that point C[i] will be the binary
 * representation of A + B.
 */
void sum(int A[], int B[], int C[], size_t size)
{
  int i;
  int carry = 0;

  for(i = 0; i < size; i++) {
    if(A[i] == 1 && B[i] == 1) {
      C[i] = carry;
      carry = 1;
    } else if (A[i] == 1 || B[i] == 1) {
      C[i] = 1 - carry;
    } else {
      C[i] = carry;
      carry = 0;
    }
  }
  C[i] = carry;
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
  int test_5[3] = { 1, 0, 1 };
  int test_7[3] = { 1, 1, 1 };
  int test_2[2] = { 0, 1 };
  int test_3[2] = { 1, 1 };
  int test_9[4] = { 1, 0, 0, 1 };
  int test_13[4] = { 1, 0, 1, 1 };

  int sum_5_7[4] = { 0 };
  sum(test_5, test_7, sum_5_7, 3);
  print(sum_5_7, 4); // 0 0 1 1 -> 12

  int sum_2_3[3] = { 0 };
  sum(test_2, test_3, sum_2_3, 2);
  print(sum_2_3, 3); // 1 0 1 -> 5

  int sum_9_13[5] = { 0 };
  sum(test_9, test_13, sum_9_13, 4);
  print(sum_9_13, 5); // 0 1 1 0 1 -> 22

  return 0;
}
