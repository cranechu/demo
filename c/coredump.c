/* Print PID and loop. */

#include <stdio.h>
#include <unistd.h>

void infinite_loop(void)
{
  for (int i=0; i<10; i++)
    {
      printf("%d, PID: %d\n", i, getpid());
      printf("PID: %d\n", getpid());
      printf("PID: %d\n", getpid());
      printf("PID: %d\n", getpid());
    }
}

int main(void)
{
    printf("PID: %d\n", getpid());
    fflush(stdout);

    infinite_loop();

    return 0;
}
