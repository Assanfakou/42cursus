#include <unistd.h>
#include <stdio.h>
// #include "process.h"
#include <sys/wait.h>

int main ()
{
    int fd[2];
    char str[12];
    int pid = fork();
    // printf("pid == %d", pid);

    if (pipe(fd) == -1)
    {
        printf("the erour is in pipe\n");
        return (0);
    }
    if (pid == 0)
    {
        close(fd[0]);
        write(fd[1], "hello Assann", 12);
        // printf("s == %d", s);
        close(fd[1]);
    }
    else
    {
        close(fd[1]);
        char ter[12];
        read(fd[0], ter, 12);
        printf("j = %s", ter);
        close(fd[0]);
        // wait(NULL);
    }
}