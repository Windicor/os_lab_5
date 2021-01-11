#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>

#define GCD_INPUT_ERROR 1
#define SORT_SIZE_INPUT_ERROR 2
#define SORT_ARRAY_INPUT_ERROR 3
#define CANNOT_OPEN_LIBRARY_ERROR 4
#define CANNOT_FIND_FUNC_ERROR 5

void* lib;
int (*gcd)(int, int);
void (*sort)(int*, unsigned long);

void gcd_cmd() {
  int a, b;
  if (scanf("%d%d", &a, &b) != 2) {
    fprintf(stderr, "Func 1 input error\n");
    exit(GCD_INPUT_ERROR);
  }
  printf("gcd: %d\n", gcd(a, b));
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
  sort(array, size);
  print_array(array, size);
}

int is_first_implementation = 1;
void swap_functions() {
  if (is_first_implementation) {
    gcd = dlsym(lib, "gcd1");
    sort = dlsym(lib, "sort1");
  } else {
    gcd = dlsym(lib, "gcd2");
    sort = dlsym(lib, "sort2");
  }
  is_first_implementation = !is_first_implementation;
  if (gcd == NULL || sort == NULL) {
    fprintf(stderr, "Cannot find functions\n");
    exit(CANNOT_FIND_FUNC_ERROR);
  }
}

void load_lib() {
  lib = dlopen("libmy.so", RTLD_LAZY);
  if (!lib) {
    fprintf(stderr, "Cannot open library libmy.so\n");
    exit(CANNOT_OPEN_LIBRARY_ERROR);
  }
  swap_functions();
}

void close_lib() {
  dlclose(lib);
}

int main() {
  load_lib();
  int cmd;
  while (scanf("%d", &cmd) == 1) {
    switch (cmd) {
      case 0:
        swap_functions();
        break;
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
  close_lib();
  return 0;
}
