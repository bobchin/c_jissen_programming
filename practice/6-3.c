#include <stdio.h>
#include <string.h>

char line[80];
int ratio;
char result[80];

void second_value(char rank[], int value)
{
  if (value <= 60 || 101 <= value) {
    printf("%s\n", rank);
    return;
  }

  int digit;
  digit = value % 10;

  if (1 <= digit && digit <= 3) {
    printf("%s%s\n", rank, "-");
  } else if (4 <= digit && digit <= 7) {
    printf("%s\n", rank);
  } else {
    printf("%s%s\n", rank, "+");
  }
}

int main()
{
  while (1) {
    printf("Enter your answer rate(0-100)['q' is end]: ");
    fgets(line, sizeof(line), stdin);

    if (strncmp(line, "q", 1) == 0) {
      break;
    }

    sscanf(line, "%d", &ratio);

    if (0 <= ratio && ratio <= 60) {
      second_value("F", ratio);
    } else if(61 <= ratio && ratio <= 70) {
      second_value("D", ratio);
    } else if(71 <= ratio && ratio <= 80) {
      second_value("C", ratio);
    } else if(81 <= ratio && ratio <= 90) {
      second_value("B", ratio);
    } else if(91 <= ratio && ratio <= 100) {
      second_value("A", ratio);
    } else {
      printf("Enter rate (0 - 100)\n");
    }
  }
}
