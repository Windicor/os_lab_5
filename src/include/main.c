#include <stdio.h>
#include <stdlib.h>

#include "mylib.h"

#define GCD_INPUT_ERROR 1
#define SORT_SIZE_INPUT_ERROR 2
#define SORT_ARRAY_INPUT_ERROR 3

void gcd_cmd() {
  int a, b;
  if (scanf("%d%d", &a, &b) != 2) {
    fprintf(stderr, "Func 1 input error\n");
    exit(GCD_INPUT_ERROR);
  }
  printf("gcd: %d\n", gcd1(a, b));
}

void read_array(int* array, size_t size) {
  for (size_t i = 0; i < size; ++i) {
    if (scanf("%d", array + i) != 1) {
      fprintf(stderr, "Func 2 array input error\n");
      exit(SORT_ARRAY_INPUT_ERROR);
    }
  }
}

void print_array(int* array, size_t size) {
  printf("sorted: ");
  for (size_t i = 0; i < size; ++i) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

void sort_cmd() {
  int size;
  if (scanf("%d", &size) != 1) {
    fprintf(stderr, "Func 2 size input error\n");
    exit(SORT_SIZE_INPUT_ERROR);
  }
  int* array = malloc(size * sizeof(int));
  read_array(array, size);
  sort1(array, size);
  print_array(array, size);
}

int main() {
  int cmd;
  while (scanf("%d", &cmd) == 1) {
    switch (cmd) {
      case 1:
        gcd_cmd();
        break;
      case 2:
        sort_cmd();
        break;
      default:
        fprintf(stderr, "Undefined command\n");
        break;
    }
  }
  return 0;
}