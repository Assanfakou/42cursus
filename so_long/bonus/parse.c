/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 01:27:04 by hfakou            #+#    #+#             */
/*   Updated: 2025/03/08 03:04:38 by hfakou           ###   ########.fr       */
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
void arounded_by_walls(t_game *game)
{
    int last_colone;
    int last_row;
    int i;

    last_colone = game->with;
    last_row = game->hight;
    i = 0;
    while (i < last_row)
    {
        if (game->map[0][i] != '1' || game->map[last_colone - 1][i] != '1')
            handle_error_exit(game, "The map is not closed by walls somwhere");
        i++;
    }
    i = 0;
    while (i < last_colone)
    {
        if (game->map[i][0] != '1' || game->map[i][last_row - 1] != '1')
            handle_error_exit(game, "The map is not closed by walls somwhere");
        i++;
    }
}
void free_map(t_game *game)
{
    int i;

    i = 0;
    while (i < game->hight)
    {
        free(game->map[i]);
        i++;
    }
    free(game->map);
}
void	handle_error_exit(t_game *game, char *error)
{
	free_map(game);
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(error, 2);
	exit(EXIT_FAILURE);
}

void     fill_map(t_game *game, char *filepath)
{
    int fd;
    char **map;
    t_check_game check;

    // printf("here");
    ft_bzero(&check, sizeof(t_check_game));
    // printf("[%d]", check.player_check);
    fd = open(filepath, O_RDONLY);
    game->hight = count_line(filepath);
    game->map = alloc_map(fd, game->hight);
    game->with = ft_strlen(game->map[0]);
    count_charachters(game, &check);
    arounded_by_walls(game);
    check_erours(game, &check);
    close(fd);
}
int check_rectangular(t_game *game)
{
    int x;
    int y;

    x = 0;
    while (x < game->hight)
    {
        y = 0;
        while (y < game->with)
        {
            if (game->with != ft_strlen(game->map[x]))
                return (0);
            y++;
        }
        x++;
    }
    return (1);
}
void check_erours(t_game *game, t_check_game *check)
{
    if (check->exit_check > 1)
        handle_error_exit(game, "It most be there one exit point");
    else if (check->player_check > 1)
        handle_error_exit(game, "It most be there one Player");
    else if (check->exit_check == 0)
        handle_error_exit(game, "There is no exit point in the giving map");
    else if (check->player_check == 0)
        handle_error_exit(game, "There is no player in the giving map");
    else if (check_rectangular(game) == 0)
        handle_error_exit(game, "The map most be rectangular");
}

void count_charachters(t_game *game, t_check_game *check)
{
    int y;
    int x;
    int hight;
    int with;

    x = 0;
    while (x < game->hight)
    {
        y = 0;
        while (y < game->with)
        {
            if (game->map[x][y] == 'C')
                check->coin_check++;
            if (game->map[x][y] == 'P')
                check->player_check++;
            if (game->map[x][y] == '1')
                check->wall_check++;
            if (game->map[x][y] == 'X')
                check->enimy_check++;
            if (game->map[x][y] == 'E')
                check->exit_check++;
            y++;
        }
        x++;
    }
}

// int main (int ac, char **av)
// {
//     t_game game;
//     int fd = open("file.ber", O_RDONLY);
//     fill_map(&game, av[1]);
//     // int lines = game->hight;

//     int i = 0;
//     while (i < game.hight)
//     {
//         int j = 0;
//         while (j < game.with)
//         {
//             printf("%c", game.map[i][j]);
//             j++;
//         }
//         printf("\n");
//         i++;
//     }
// }
