#include <stdio.h>
#include <math.h>

char line[80];
double px1, py1, px2, py2;
double result;

int main()
{
  printf("Input Points(x1 y1 x2 y2): ");
  fgets(line, sizeof(line), stdin);
  sscanf(line, "%lf %lf %lf %lf", &px1, &py1, &px2, &py2);

  result = pow((px2 - px1), 2) + pow((py2 - py1), 2);
  printf("2points distance square is %lf\n", result);

  printf("2points distance is %lf\n", sqrt(result));

  return (0);
}
