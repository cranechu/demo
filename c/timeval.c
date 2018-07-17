#include <stdio.h>
#include <sys/time.h>

int main()
{
  struct timeval tv;
  gettimeofday(&tv, NULL);
  printf("%d\n", sizeof(tv));
}
