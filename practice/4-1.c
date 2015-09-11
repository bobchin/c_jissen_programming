#include "stdio.h"

int birth_month;
int birth_day;

int main()
{
  birth_month = 12;
  birth_day = 31;

  printf("My name is %s\n", "bobchin");
  printf("My insurance number is %s\n", "012345");
  printf("My birthday is %d / %d\n", birth_month, birth_day);

  return (0);
}
