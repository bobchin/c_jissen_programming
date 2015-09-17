/*
 * search -- 一連の数値中から検索
 *
 * 使用法： search
 *    検索すべき数値を入力する
 *
 * ファイル：
 *     numbers.dat -- 検索対象の数値が1行に1つずつ記述されている
 *                    (数値は昇順または降順でなければならない)
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBERS 1000
const char DATA_FILE[] = "numbers.dat";

int data[MAX_NUMBERS];
int max_count;

int main()
{
  FILE *in_file;
  int middle;
  int low, high;
  int search;
  char line[80];

  in_file = fopen(DATA_FILE, "r");
  if (in_file == NULL) {
    fprintf(stderr, "Error: Unable to open %s\n", DATA_FILE);
    exit(8);
  }

  max_count = 0;
  while (1) {
    if (fgets(line, sizeof(line), in_file) == NULL)
      break;

    sscanf(line, "%d", &data[max_count]);
    ++max_count;
  }

  while (1) {
    printf("Enter number to search for or -1 to quit:");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &search);

    if (search == -1)
      break;

    low = 0;
    high = max_count;

    while (1) {
      middle = (low + high) / 2;
      printf("%d %d %d %d\n", middle, search, low, high);
      if (data[middle] == search) {
        printf("Found at index %d\n", middle);
      }

      if (low == high) {
        printf("Not found\n");
        break;
      }

      if (data[middle] < search)
        low = middle;
      else
        high = middle;
    }
  }
  return (0);
}
