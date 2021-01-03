#include <stdio.h>
#include <stdlib.h>

// compiled using:
// gcc (GCC) 10.2.0
// write a function that interchanges the first element with the last element, 
// and the second element as the second last element, and so on.

int main () {
  int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int arr_len = (sizeof arr / sizeof arr[0]) - 1;

  printf("original: ");

  for (int i = 0; i <= arr_len; i++) {
    printf("%d ", arr[i]);
  }

  printf("\n");

  for (int i = 0; i <= arr_len / 2; i++) {
    int el1 = arr[i];
    int el2 = arr[arr_len - i];

    arr[i] = el2;
    arr[arr_len - i] = el1;
  }

  printf("result: ");

  for (int i = 0; i <= arr_len; i++) {
    printf("%d ", arr[i]);
  }

  printf("\n");
}
