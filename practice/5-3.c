#include <stdio.h>
#include <string.h>

int main()
{
  char line[100];
  float width, height;

  printf("Enter width height?: ");
  fgets(line, sizeof(line), stdin);
  sscanf(line, "%f %f", &width, &height);

  printf("Rectangle circuit is %f\n", 2 * (width + height));

  return (0);
}
