/*
 * infinity_array -- 無限配列を扱うルーチン
 *
 * 無限配列は必要に応じて大きくなる配列である。
 * 無限配列のインデックスは無限である
 * （ただし、メモリが亡くならない限りのことである）
 */
#include "ia.h"
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * ia_locate -- 無限配列の要素の場所を取得する
 *
 * パラメータ
 *     array_ptr -- 使用する配列へのポインタ
 *     index -- 配列のインデックス
 *     current_index -- このバケツ（戻り値）のインデックスへのポインタ
 * 戻り値
 *     現在のバケツへのポインタ
 */
static struct infinity_array *ia_locate (
  struct infinity_array *array_ptr, int index, int *current_index_ptr)
{
  /* 現在のバケツへのポインタ */
  struct infinity_array *current_ptr;

  current_ptr = array_ptr;
  *current_index_ptr = index;

  while (*current_index_ptr >= BLOCK_SIZE) {
    if (current_ptr->next == NULL) {
      current_ptr->next = malloc(sizeof(struct infinity_array));
      if (current_ptr->next == NULL) {
        fprintf(stderr, "Error: Out of memory\n");
        exit(8);
      }
      memset(current_ptr->next, '\0', sizeof(struct infinity_array));
    }
    current_ptr = current_ptr->next;
    *current_index_ptr -= BLOCK_SIZE;
  }

  return (current_ptr);
}

/*
 * ia_store -- 無限配列に要素を格納する
 *
 * パラメータ
 *     array_ptr -- 使用する配列へのポインタ
 *     index -- 配列のインデックス
 *     store_data -- 格納するデータ
 */
void ia_store(struct infinity_array *array_ptr, int index, int store_data)
{
  /* 現在のバケツへのポインタ */
  struct infinity_array *current_ptr;
  int current_index;

  current_ptr = ia_locate(array_ptr, index, &current_index);
  current_ptr->data[current_index] = store_data;
}

/*
 * ia_get -- 無限配列から要素を取得する
 *
 * パラメータ
 *     array_ptr -- 使用する配列へのポインタ
 *     index -- 配列のインデックス
 *
 * 戻り値
 *     要素の値
 *
 * 注意：前もって格納していない要素を取得することが可能。
 *      未初期化の要素の値はすべて0となる
 */
int ia_get(struct infinity_array *array_ptr, int index)
{
  /* 現在のバケツへのポインタ */
  struct infinity_array *current_ptr;
  int current_index;

  current_ptr = ia_locate(array_ptr, index, &current_index);
  return (current_ptr->data[current_index]);
}
