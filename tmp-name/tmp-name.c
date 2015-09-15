#include <stdio.h>
#include <string.h>

char name[30];

/*
 * tmp_name -- 一時的なファイル名を返す
 *
 * この関数は呼び出されるたびに、新しい名前を返す
 *
 * 戻り値
 *    新しいファイル名を指すポインタ
 */
char *tmp_name(void)
{
  static int sequence = 0;

  ++sequence;

  strcpy(name, "tmp");
  name[3] = sequence + '0';
  name[4] = '\0';

  return name;
}

int main()
{
  char *tmp_name(void);

  printf("Name: %s\n", tmp_name());
  return (0);
}
