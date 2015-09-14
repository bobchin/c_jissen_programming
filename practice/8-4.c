#include <stdio.h>

const int COLS = 9;
const int ROWS = 9;

void print_header()
{
  printf("  |");
  for (int i = 0; i < COLS; i++) {
    printf(" %2d", (i + 1));
  }
  printf("\n");
  printf("--+");
  for (int i = 0; i < COLS; i++) {
    printf("---");
  }
  printf("\n");
}

void print_line(int value)
{
  printf("%2d|", value);
  for (int i = 0; i < COLS; i++) {
    printf(" %2d", (i + 1) * value);
  }
  printf("\n");
}

int main()
{
  printf("掛け算表\n");

  print_header();
  for (int i = 0; i < ROWS; i++) {
    print_line(i + 1);
  }
  return (0);
}
