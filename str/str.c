#include <string.h>
#include <stdio.h>

char name[30];

int main()
{
  /*
   * 配列の代入はできないのでstrcpy を使う
   * name = "Sam" # これはできない！
   */
  strcpy(name, "Sam");
  printf("The name is %s\n", name);
  return (0);
}
