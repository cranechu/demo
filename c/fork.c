#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void print_something()
{
  printf("print something\n");
}

int main()
{
  pid_t pid;

  pid = fork();
  if (pid == -1)
    perror("fork");

  print_something();

  if (pid == 0)
  {
    char * const args[] = {"ls", "/", NULL};
    int ret;

    ret = execv("/bin/ls", args);
    if (ret == -1)
    {
      perror("execv");
      exit(EXIT_FAILURE);
    }
  }
}
