#include <stdio.h>

int main()
{
  int thing_var;  /* モノを表す変数を定義 */
  int *thing_ptr; /* モノを指すポインタを定義 */

  thing_var = 2;
  printf("Thing %d\n", thing_var);

  thing_ptr = &thing_var;
  *thing_ptr = 3;
  printf("Thing %d\n", thing_var);

  printf("Thing %d\n", *thing_ptr);
  return (0);
}
