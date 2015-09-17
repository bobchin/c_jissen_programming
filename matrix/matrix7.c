/*
 * memsetを使用するようにした
 */

#include <memory.h>
#define X_SIZE 60
#define Y_SIZE 32

int matrix[X_SIZE][Y_SIZE];

void init_matrix(void)
{
  memset(matrix, -1, sizeof(matrix));
}
