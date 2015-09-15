#include <stdio.h>
#include <string.h>

const int LIST_NUM = 3;

struct yubinlist {
  char postcode[7];
  char address[50];
} addresses[LIST_NUM];

void print_yubin()
{
  for (int i = 0; i < LIST_NUM; i++) {
    printf("%d:[%s]=%s\n", i + 1, addresses[i].postcode, addresses[i].address);
  }
}

int main()
{
  strcpy(addresses[0].postcode, "0123456");
  strcpy(addresses[0].address,  "Hokkaido Sapporo");

  strcpy(addresses[1].postcode, "7654321");
  strcpy(addresses[1].address,  "Hokkaido Hakodate");

  strcpy(addresses[2].postcode, "1111111");
  strcpy(addresses[2].address,  "Hokkaido Asahikawa");

  print_yubin();

  return (0);
}
