#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
  int fd;

  fd = open("/home/cranechu/demo/linux/lsp.pdf", O_RDONLY);
  if (fd < 0)
  {
    perror("open lsp pdf");
  }

  fd = open("lsp_not_exist.pdf", O_RDONLY);
  if (fd < 0)
  {
    perror("open not exist lsp pdf");
  }

  fd = open("lsp.pdf", O_DIRECTORY);
  if (fd < 0)
  {
    perror("open dir");
  }

  fd = open("lsp.pdf", O_CREAT|O_EXCL);
  if (fd < 0)
  {
    perror("create existed file");
  }  

  fd = open("lsp_new.pdf", O_CREAT|O_RDONLY, S_IRUSR|S_IROTH);
  if (fd < 0)
  {
    perror("create new file by open");
  }  

  // take umask into consideration for the final permission mode
  fd = creat("new_for_write", 0664);  // open: O_WRONLY | O_CREAT | O_TRUNC
  if (fd < 0)
  {
    perror("create new file");
  }

  return 0;
}
