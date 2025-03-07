/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 01:27:04 by hfakou            #+#    #+#             */
/*   Updated: 2025/03/07 03:32:24 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int count_line(char *file_path)
{
    int line_num;
    int fd;
    char *line;

    fd = open(file_path, O_RDONLY);
    line = get_next_line(fd);
    line_num = 0;
    while (line != NULL)
    {
        free(line);
        line = get_next_line(fd);
        line_num++;
    }
    close(fd);
    return (line_num);
}

char **alloc_map(int fd, int lines)
{
    char **map;
    char *line;
    int i;

    map = malloc(sizeof(char *) * (lines + 1));
    if (!map)
        return (NULL);
    line = get_next_line(fd);
    i = 0;
    while (line)
    {
        map[i] = line;
        line = get_next_line(fd);
        i++;
    }
    map[i] = NULL;
    return (map);
}

void fill_map(t_game *game, char *filepath)
{
    int fd;

    fd = open(filepath, O_RDONLY);
    game->with = count_line(filepath);
    game->map = alloc_map(fd, game->with);
    close(fd);
}
// int main (int ac, char **av)
// {
//     char **map;
//     int fd = open("file.ber", O_RDONLY);
//     map = alloc_map(fd, count_line("file.ber"));

//     int i = 0;
//     while (i < count_line("file.ber"))
//     {
//         int j = 0;
//         while (j < 10)
//         {
//             printf("%c", map[i][j]);
//             j++;
//         }
//         printf("\n");
//         i++;
//     }
// }