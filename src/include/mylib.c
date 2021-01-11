#include <stdlib.h>

void swap(unsigned int* a, unsigned int* b) {
  unsigned int t = *a;
  *a = *b;
  *b = t;
}

int gcd1(int a_inp, int b_inp) {
  unsigned int a = a_inp, b = b_inp;
  while (b) {
    a %= b;
    swap(&a, &b);
  }
  return a;
}

unsigned int min(unsigned int a, unsigned int b) {
  if (a < b) {
    return a;
  }
  return b;
}

int gcd2(int a_inp, int b_inp) {
  unsigned int a = a_inp, b = b_inp;
  for (int i = min(a, b); i > 1; --i) {
    if (a % i == 0 && b % i == 0) {
      return i;
    }
  }
  return 1;
}

void sort1(int* array, unsigned long size) {
  for (unsigned long i = 0; i < size; ++i) {
    for (unsigned long j = 0; j < size - 1; ++j) {
      if (array[j] > array[j + 1]) {
        swap(array + j, array + j + 1);
      }
    }
  }
}

int compare(const void* a, const void* b) {
  return (*(int*)a - *(int*)b);
}

void sort2(int* array, unsigned long size) {
  qsort(array, size, sizeof(int), compare);
}