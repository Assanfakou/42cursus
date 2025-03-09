/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_erour.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 17:29:50 by hfakou            #+#    #+#             */
/*   Updated: 2025/03/09 02:18:29 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void arounded_by_walls(t_game *game)
{
    int last_colone;
    int last_row;
    int i;

    last_colone = game->hight;
    last_row = game->with;
    printf("last colone %d\n", last_colone); 
    printf("last row %d\n", last_row); 

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
            handle_error_exit(game, "The map is not closed by walls somwhere2");
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
