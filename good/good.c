/*
 * guess -- 簡単な推測ゲーム
 *
 * 使用法：
 *      guess
 *
 *      1から100の間の数をランダムに選択する。
 *      プレーヤーは指定された上限下限の間の数を1つ選ぶ。
 *      プレーヤーの選んだ数がプログラムが選んだ数と合っていれば、
 *      プレーヤーの勝ち。
 *      合わなかった場合は、プレーヤーの推測に合わせて
 *      範囲を調節し、ゲームが続く。
 *
 * 制限：
 *      ランダム数は文 rand() % 100 により生成する。
 *      rand() は ０ <= rand() <= maxint の数を返すため。
 *      どちらかといえば、この文は小さい数を生成することが多い。
 */

#include <stdio.h>
#include <stdlib.h>

int number_to_guess; /* 推測されるランダム数 */
int low_limit;       /* プレーヤーの推測の現在の下限 */
int high_limit;      /* プレーヤーの推測の現在の上限 */
int guess_count;     /* プレーヤーが推測した回数 */
int player_number;   /* プレーヤーが推測した数 */
char line[80];       /* １行の入力バッファ */

int main()
{
  while (1) {
    number_to_guess = rand() % 100 + 1;

    /* ループ用に変数を初期化 */
    low_limit = 0;
    high_limit = 100;
    guess_count = 0;

    while (1) {
      /* 上限下限をユーザに知らせ、推測を受け取る */
      printf("Bounds %d - %d\n", low_limit, high_limit);
      printf("Value[%d]? ", guess_count);

      ++guess_count;

      fgets(line, sizeof(line), stdin);
      sscanf(line, "%d", &player_number);

      /* 推測は正しいか */
      if (player_number == number_to_guess)
        break;

      /* 次の推測用に範囲を調節する */
      if (player_number < number_to_guess) {
        low_limit = player_number;
      } else {
        high_limit = player_number;
      }
    }
    printf("Bingo!\n");
  }

  return (0);
}







//
