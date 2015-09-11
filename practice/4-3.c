#include <stdio.h>

int main()
{
  float width_inch = 3.0;
  float height_inch = 5.0;

  printf("Rectangle area is %f\n", (width_inch * 2.54) * (height_inch * 2.54));
  printf("Rectangle circuit is %f\n", ((width_inch * 2.54) + (height_inch * 2.54)) * 2);

  return (0);
}
