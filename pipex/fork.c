/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assankou <assankou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:29:17 by assankou          #+#    #+#             */
/*   Updated: 2025/01/15 18:29:43 by assankou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include "../libft/libft.h"
#include <fcntl.h>


// int main (int argc, char *argv[])
// {
//     int fd[2];

//     if (pipe(fd) == -1)
//     {
//         printf("the erour ocured in pipe");
//         return (1);
//     }
//     int pid = fork();
//     if (pid != 0)
//     {
//         close(fd[0]);
//         int i;

//         i = 0;
//         char *join = ft_strjoin(argv[1], argv[2]);
//         printf("joind result --> %s\n", join);
//         write(fd[1], &join, sizeof(join));
//         close(fd[1]);
//     }
//     else
//     {
//         close(fd[1]);

//         char *recieved;
//         read(fd[0], recieved, 17);
//         close(fd[0]);
//         printf("the recieved string ; %s\n", recieved);
//     }   
// }
int main ()
{
    // int fd = open("file.txt", 0);

    int fd[2];

    if (pipe(fd) == -1)
    {
        perror("the erour is ocured in pipe");
        return(1);
    }
    int pid = fork();

    if (pid != 0)
    {
        close(fd[0]);
        int i;
        printf("print a number : \n");
        scanf("%d", &i);
        write(fd[1], &i, sizeof(int));
        close(fd[1]);
    }
    else
    {
        close(fd[1]);
        int a;

        read(fd[0], &a, sizeof(int));
        printf("the number from the parent process : %d", a);
        close(fd[0]);
    }
}