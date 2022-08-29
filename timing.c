#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>


void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}
void sort(int *array, int const size) {
  
  bool swapped;
  do {
    swapped = false;
    for (int i = 0; i < size - 1; ++i) {
      if (array[i] > array[i + 1]) {
        swapped = true;
        swap(array + i, array + i + 1);
      }
    }
  } while (swapped);
}
void rand_str(char *str) {
  for (int i = 0; i < 5; ++i) {
    str[i] = 'a' + (rand() % 28);
  }
}


int main() {
  srand(time(NULL));

  int size = 0;
  scanf("%d", &size);

  int *array = calloc(size, sizeof(int));
  for (int i = 0; i < size; ++i)
    array[i] = rand(); // unsigned (key)
  
  char **info = calloc(size, sizeof(int));

  clock_t start = clock();
  sort(array, size);
  clock_t end = clock();  

  printf("Sorting time: %f second\n", (float)(end - start) / CLOCKS_PER_SEC);
  
  return 0;
}
