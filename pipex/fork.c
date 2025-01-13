#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include "../libft/libft.h"

int main (int argc, char *argv[])
{
    int fd[2];

    if (pipe(fd) == -1)
    {
        printf("the erour ocured in pipe");
        return (1);
    }
    int pid = fork();
    if (pid != 0)
    {
        close(fd[0]);
        int i;

        i = 0;
        char *join = ft_strjoin(argv[1], argv[2]);
        printf("joind result --> %s\n", join);
        write(fd[1], &join, sizeof(join));
        close(fd[1]);
    }
    else
    {
        close(fd[1]);

        char *recieved;
        read(fd[0], recieved, 17);
        close(fd[0]);
        printf("the recieved string ; %s\n", recieved);
    }
    
}