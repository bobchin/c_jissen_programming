/*
 * Database -- 非常に単純なデータベースプログラム
 *             プログラムに記述されたリスト中に名前を探す
 *
 * 使用法： database
 *   プログラムは名前の入力を求める。
 *   名前を入力すると、その名前がリスト中にあるかどうかを通知する。
 *
 *   何も入力しないでリターンキーを押すと終了。
 */
#define STRING_LENGTH 80
#include <stdio.h>
#include <string.h>

int main()
{
  char name[STRING_LENGTH];

  int lookup(char const *const name);

  while (1) {
    printf("Enter name: ");
    fgets(name, sizeof(name), stdin);

    /* リターンキーだけかどうかをチェック */
    if (strlen(name) <= 1)
      break;

    /* 改行を削除 */
    name[strlen(name) - 1] = '\0';

    if (lookup(name))
      printf("%s is in the list\n", name);
    else
      printf("%s is not in the list\n", name);
  }
  return (0);
}

/*
 * lookup -- リスト中で名前を探す
 *
 * パラメータ
 *     name -- 探しだす名前
 *
 * 戻り値
 *      1 -- 名前がリストにある
 *      0 -- 名前がリストにない
 */
int lookup(char const *const name)
{
  static char *list[] = {
    "John",
    "Jim",
    "Jane",
    "Clyde",
    NULL
  };

  int index;
  for (index = 0; list[index] != NULL; index++) {
    if (strcmp(list[index], name) == 0)
      return (1);
  }
  return (0);
}
