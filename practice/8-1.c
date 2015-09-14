#include <stdio.h>

const int COLS = 8;
const int ROWS = 8;
const int COLS_ONE = 5;
const int ROWS_ONE = 3;

void print_delim()
{
  for (int col_index = 0; col_index < COLS; col_index++) {
    printf("+");
    for (int one_index = 0; one_index < COLS_ONE; one_index++) {
      printf("-");
    }
  }
  printf("+\n");
}

void print_col()
{
  for (int col_index = 0; col_index < COLS; col_index++) {
    printf("|");
    for (int one_index = 0; one_index < COLS_ONE; one_index++) {
      printf(" ");
    }
  }
  printf("|\n");
}

int main()
{
  for (int row_index = 0; row_index < ROWS; row_index++) {
    print_delim();
    for (int one_index = 0; one_index < ROWS_ONE; one_index++) {
      print_col();
    }
  }
  print_delim();

  return (0);
}
