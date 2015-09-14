#include <stdio.h>
#include <string.h>

char line[80];
float ratio;
char result[80];

int main()
{
  while (1) {
    printf("Enter your answer rate(0-100)['q' is end]: ");
    fgets(line, sizeof(line), stdin);

    if (strncmp(line, "q", 1) == 0) {
      break;
    }

    sscanf(line, "%f", &ratio);

    strcpy(result, "Enter rate (0 - 100)");
    if (0 <= ratio && ratio <= 60) {
      strcpy(result, "F");
    } else if(61 <= ratio && ratio <= 70) {
      strcpy(result, "D");
    } else if(71 <= ratio && ratio <= 80) {
      strcpy(result, "C");
    } else if(81 <= ratio && ratio <= 90) {
      strcpy(result, "B");
    } else if(91 <= ratio && ratio <= 100) {
      strcpy(result, "A");
    }

    printf("%s\n", result);
  }
}
