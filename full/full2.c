#include <string.h>
#include <stdio.h>

char first[100];
char last[100];
char full_name[200];

int main()
{
  printf("Enter first name:");
  fgets(first, sizeof(first), stdin);
  /* 最後の文字を取り除く */
  first[strlen(first) - 1] = '\0';

  printf("Enter last name:");
  fgets(last, sizeof(last), stdin);
  last[strlen(last) - 1] = '\0';

  strcpy(full_name, first);

  strcat(full_name, " ");
  strcat(full_name, last);

  printf("The full name is %s\n", full_name);

  return (0);
}
