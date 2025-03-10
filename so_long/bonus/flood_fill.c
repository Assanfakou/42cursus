/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 04:10:09 by hfakou            #+#    #+#             */
/*   Updated: 2025/03/10 04:10:34 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**secondary_map(t_game *game)
{
	char	**second_map;
	int		y;

	second_map = malloc(sizeof(char *) * (game->hight + 1));
	if (!second_map)
		exit(EXIT_FAILURE);
	y = 0;
	while (y < game->hight)
	{
		second_map[y] = ft_strdup(game->map[y]);
		y++;
	}
	second_map[y] = NULL;
	return (second_map);
}

void	finding_player(t_game *game, int *y, int *x)
{
	int	_y;
	int	_x;

	_y = 0;
	while (_y < game->hight)
	{
		_x = 0;
		while (_x < game->with)
		{
			if (game->map[_y][_x] == 'P')
			{
				*y = _y;
				*x = _x;
				return ;
			}
			_x++;
		}
		_y++;
	}
}

void	check_valid_path(t_game *game)
{
	char	**second_map;
	int		y;
	int		x;

	second_map = secondary_map(game);
	finding_player(game, &y, &x);
	flood_fill(second_map, y, x);
	x = 0;
	while (x < game->hight)
	{
		y = 0;
		while (y < game->with)
		{
			if (second_map[x][y] == 'C' || second_map[x][y] == 'E')
			{
				free_map(game, second_map);
				handle_error_exit(game, "The path is not valide");
			}
			y++;
		}
		x++;
	}
	free_map(game, second_map);
}

void	flood_fill(char **map, int y, int x)
{
	if (map[y][x] == '1' || map[y][x] == 'Z')
		return ;
	map[y][x] = 'Z';
	flood_fill(map, y + 1, x);
	flood_fill(map, y - 1, x);
	flood_fill(map, y, x + 1);
	flood_fill(map, y, x - 1);
}