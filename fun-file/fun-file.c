#include <stdio.h>
#include <stdlib.h>

int main()
{
  char name[100];
  FILE *in_file;

  printf("Name? ");
  fgets(name, sizeof(name), stdin);

  in_file = fopen(name, "r");
  if (in_file == NULL) {
    fprintf(stderr, "Error: Unable to open %s for input\n", name);
    exit(8);
  }

  printf("File found\n");
  fclose(in_file);
  return (0);
}
