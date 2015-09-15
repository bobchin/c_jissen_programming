#define MAX 10

/*
 * init_array_1 -- 配列の要素をすべて0にする
 *
 * パラメータ
 *    data -- 0にする配列
 */
void init_array_1(int data[])
{
  int index;
  for (index = 0; index < MAX; index++) {
    data[index] = 0;
  }
}

/*
 * init_array_2 -- 配列の要素をすべて0にする
 *
 * パラメータ
 *    data_ptr -- 0にする配列を指すポインタ
 */
void init_array_2(int *data_ptr)
{
  int index;
  for (index = 0; index < MAX; index++) {
    *(data_ptr + index) = 0;
  }
}

int main()
{
  int array[MAX];

  void init_array_1();
  void init_array_2();

  /* 配列を初期化する1つの方法 */
  init_array_1(array);

  /* 配列を初期化する別の方法 */
  init_array_1(&array[0]);

  /* 動作するがコンパイラは警告を発する */
  init_array_1(&array);

  /* 1番目と同じだが、関数が異なる */
  init_array_2(array);

  return (0);
}
