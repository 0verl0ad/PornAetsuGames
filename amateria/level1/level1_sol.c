//example from http://man7.org/linux/man-pages/man2/execve.2.html
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
      
int main(int argc, char *argv[])
{
    char *newargv[] = { NULL, NULL };
    char *newenviron[] = { NULL };
    
    if (argc != 2) {
      fprintf(stderr, "Usage: %s <file-to-exec>\n", argv[0]);
      exit(EXIT_FAILURE);
    }
    
    execve(argv[1], newargv, newenviron);
    perror("execve");   /* execve() only returns on error */
    exit(EXIT_FAILURE);
}
  