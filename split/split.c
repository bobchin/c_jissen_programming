#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * my_strchr -- 文字列中の文字を検索
 *      標準ライブラリ関数の内容を書き写したもの
 *      処理手順がわかるようにするためである
 *
 * パラメータ
 *      string_ptr -- 対象となる文字列
 *      find -- 見つけ出す文字
 *
 * 戻り値
 *      文字列中で最初に見つけ出した文字を指すポインタ
 *      エラーの場合はNULL
 */
char *my_strchr(char *string_ptr, char find)
{
  while (*string_ptr != find) {
    /* 文字列の終端をチェック */
    if (*string_ptr == '\0') {
      return NULL;
    }
    ++string_ptr;
  }
  return (string_ptr);
}

int main()
{
  char line[80];
  char *first_ptr;
  char *last_ptr;

  fgets(line, sizeof(line), stdin);

  /* 終わりに付いた改行文字を削除 */
  line[strlen(line) - 1] = '\0';

  last_ptr = line;
  first_ptr = my_strchr(line, '/');

  if (first_ptr == NULL) {
    fprintf(stderr, "Error: Unable to find slash in %s\n", line);
    exit(8);
  }

  /* スラッシュを\0にする */
  *first_ptr = '\0';
  ++first_ptr;

  printf("First:%s Last:%s\n", first_ptr, last_ptr);
  return (0);
}
