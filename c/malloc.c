#include <stdio.h>
#include <stdlib.h>

int main()
{
  int* p = malloc(8);

  p = 9;
  printf("%d\n", *p);

  return 0;
}
