#include <stdio.h>
#include <stdlib.h>
#ifndef __MSDOS__
#include <unistd.h>
#endif

int main()
{
  int cur_char;
  FILE *out_file;

  out_file = fopen("test.out", "wb");
  if (out_file == NULL) {
    fprintf(stderr, "Cannot open output file\n");
    exit(8);
  }

  for (cur_char = 0; cur_char < 128; cur_char++) {
    fputc(cur_char, out_file);
  }
  fclose(out_file);
  return (0);
}
