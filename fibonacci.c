#include <stdio.h>
#include <stdlib.h>

// compiled using:
// gcc (GCC) 10.2.0
// generate fibonacci sequence of length = n
// example: ./fibonacci 4
// yields:  0 1 1 2
// example: ./fibonacci 10
// yields:  0 1 1 2 3 5 8 13 21 34

void get_fibonacci_iterative(int input, int *result);
void get_fibonacci_recursive(int input, int *result);
int fibonacci_recusrive(int n);

int main (int argc, char **argv) {
  // first argmunet while running this program will be considered as input n.
  int input = atoi(argv[1]);
  int result[input - 1];

  // terminate for invalid input
  // close when int range is exceeded by input > 46
  if (!input || input > 46) {
    printf("invalid arg length. One number argument is expected.");
    printf("Usage: ./fibonacci <number>");

    exit(1);
  }

  get_fibonacci_recursive(input, result);


  for(int i = 0; i <= input - 1; i++) {
    printf("%d ", result[i]);
  }

  printf("\n");
  printf("program exited successfully.");
}

void get_fibonacci_iterative(int input, int *result) {
  result[0] = 0;
  result[1] = 1;

  for(int i = 2; i <= input; i++) {
    result[i] = result[i - 1] + result[i - 2];
  }
}


void get_fibonacci_recursive(int input, int *result) {
  result[0] = 0;
  result[1] = 1;

  for(int i = 2; i <= input; i++) {
    result[i] = fibonacci_recusrive(i);
  }
}


int fibonacci_recusrive(int n) {
   if(n == 0){
      return 0;
   } else if(n == 1) {
      return 1;
   } else {
      return (fibonacci_recusrive(n-1) + fibonacci_recusrive(n-2));
   }
}
