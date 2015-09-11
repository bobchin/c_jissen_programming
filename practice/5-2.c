#include <stdio.h>

int main()
{
  float area;
  float hankei = 1.36;
  const float PI = 3.14;

  area = (4 / 3 * PI) * hankei * hankei * hankei;

  printf("circle area is %f\n", area);
  return (0);
}
