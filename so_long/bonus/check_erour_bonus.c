/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_erour_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 17:29:50 by hfakou            #+#    #+#             */
/*   Updated: 2025/03/13 22:28:44 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	arounded_by_walls(t_game *game)
{
	int	last_colone;
	int	last_row;
	int	i;

	last_colone = game->hight;
	last_row = game->with;
	i = 0;
	while (i < last_row)
	{
		if (game->map[0][i] != '1' || game->map[last_colone - 1][i] != '1')
			handle_error_exit(game, "The map is not closed by walls somewhere");
		i++;
	}
	i = 0;
	while (i < last_colone)
	{
		if (game->map[i][0] != '1' || game->map[i][last_row - 1] != '1')
			handle_error_exit(game, "The map is not closed by walls somewhere");
		i++;
	}
}

void	free_map(t_game *game, char **map)
{
	int	i;

	i = 0;
	while (i < game->hight)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	handle_error_exit(t_game *game, char *error)
{
	free_map(game, game->map);
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(error, 2);
	exit(EXIT_FAILURE);
}

int	check_rectangular(t_game *game)
{
	int	x;
	int	y;

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

void	check_erours(t_game *game, t_check_game *check)
{
	if (check->exit_check > 1)
		handle_error_exit(game, "It must be there one exit point");
	else if (check->player_check > 1)
		handle_error_exit(game, "It must be there one Player");
	else if (check->coin_check == 0)
		handle_error_exit(game, "There is no coin in the giving map");
	else if (check->player_check == 0)
		handle_error_exit(game, "There is no player in the giving map");
	else if (check->exit_check == 0)
		handle_error_exit(game, "There is no exit point in the giving map");
	if (game->hight > WINDOW_HIGHT / 42 || game->with > WINDOW_WIDTH / 42)
	{
		check_valid_path(game);
		handle_error_exit(game, "THE map is valid but too long");
	}
}
