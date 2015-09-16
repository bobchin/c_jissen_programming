/*
 * 無限配列(ia)パッケージに関する定義
 *
 * 無限配列は必要に応じてサイズが大きくなる配列である。
 * 配列に最初の指定以上の要素を追加すると配列は大きくなる。
 * --------------------------------------------
 * 構造体 infinite_array
 *       無限配列に関する情報を格納するために使用
 * --------------------------------------------
 * ルーチン
 *
 *     ia_init  -- 配列を初期化
 *     ia_store -- 配列に要素を格納
 *     ia_get   -- 配列の要素を取得
 */

/* 無限配列の各セルに格納する要素の数 */
#define BLOCK_SIZE 10

struct infinite_array {
  /* このブロックのデータ */
  float data[BLOCK_SIZE];

  /* 次の配列へのポインタ */
  struct infinite_array *next;
};

/*
 * ia_init -- 無限配列を初期化
 *
 * パラメータ
 *    array_ptr -- 初期化する配列
 */
#define ia_init(array_ptr) {(array_ptr)->next = NULL;}

/*
 * ia_get -- 配列の要素を取得
 *
 * パラメータ
 *     array_ptr -- 使用する配列へのポインタ
 *     index -- 配列のインデックス
 * 戻り値
 *     要素の値
 *
 * 注意：前もって格納していない要素を取得することが可能である。
 *      未初期化の要素の値はすべて0となる。
 */
extern int ia_get(struct infinite_array *array_ptr, int index);

/*
 * ia_store -- 無限配列に要素を格納
 *
 * パラメータ
 *     array_ptr -- 使用する配列へのポインタ
 *     index -- 配列のインデックス
 *     store_data -- 格納するデータ
 */
extern void ia_store(struct infinite_array *array_ptr, int index, int store_data);
