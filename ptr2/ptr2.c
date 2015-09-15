#include <stdio.h>

int array[] = {4, 5, 8, 9, 8, 1, 0, 1, 9, 3};
int index_i;

int main()
{
  index_i = 0;
  while (array[index_i] != 0) {
    ++index_i;
  }

  printf("Number of elements before zero %d\n", index_i);

  return (0);
}
