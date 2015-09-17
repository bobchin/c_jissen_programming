/*
 * Database -- 非常に単純なデータベースプログラム
 *             プログラムに記述されたリスト中に名前を探す
 *
 * 使用法： database [-S<file>] [-P<file>]
 *
 *   -S<file> デバッグ用に保存ファイルを指定
 *   -P<file> デバッグまたはデモ用に再生ファイルを指定
 *
 *   プログラムは名前の入力を求める。
 *   名前を入力すると、その名前がリスト中にあるかどうかを通知する。
 *
 *   何も入力しないでリターンキーを押すと終了。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *save_file = NULL;
FILE *playback_file = NULL;

char *extended_fgets(char *, int, FILE *);

int main(int argc, char *argv[])
{
  char name[80];
  char *save_file_name;
  char *playback_file_name;

  int lookup(char const *const name);

  while ((argc > 1) && (argv[1][0] == '-')) {
    switch (argv[1][1]) {
      case 'S':
        save_file_name = &argv[1][2];
        save_file = fopen(save_file_name, "w");
        if (save_file == NULL)
          fprintf(stderr, "Warning: Unable to open save file %s\n", save_file_name);
        break;

      case 'P':
        playback_file_name = &argv[1][2];
        playback_file = fopen(playback_file_name, "r");
        if (playback_file == NULL) {
          fprintf(stderr, "Error: Unable to open playback file %s\n", playback_file_name);
          exit(8);
        }
        break;

      default:
        fprintf(stderr, "Bad option: %s\n", argv[1]);
        exit(8);
    }
    --argc;
    ++argv;
  }

  while (1) {
    printf("Enter name: ");

    extended_fgets(name, sizeof(name), stdin);

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

/*
 * extended_fgets -- 入力ファイルから1行を取得し、
 *                   必要ならそれを保存ファイルに記録する
 *
 * パラメータ
 *     line -- 読まれるべき1行
 *     size -- sizeof(line) -- 読まれる文字の最大数
 *     file -- このファイルからデータを読む(通常はstdin)
 *
 * 戻り値
 *     NULL -- エラーまたはEOFが読まれた場合
 *             それ以外ははlineを返す(fgetsとまったく同じ)
 */
char *extended_fgets(char *line, int size, FILE *file)
{
  extern FILE *save_file;
  extern FILE *playback_file;

  char *result;

  if (playback_file != NULL) {
    result = fgets(line, size, playback_file);
    /* ユーザが自分の入力を見られるように入力を標準出力にエコーさせる */
    fputs(line, stdout);
  } else {
    result = fgets(line, size, file);
  }

  if (save_file != NULL)
    fputs(line, save_file);

  return (result);
}
