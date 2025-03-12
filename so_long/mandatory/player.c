/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:28:45 by hfakou            #+#    #+#             */
/*   Updated: 2025/03/11 01:23:29 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clear_way(t_game *game)
{
	int	y;
	int	x;

	if (game->map[game->exit_pos_y][game->exit_pos_x] != 'P')
		game->map[game->exit_pos_y][game->exit_pos_x] = 'E';
	y = 0;
	while (y < game->hight)
	{
		x = 0;
		while (x < game->with)
		{
			if (game->map[y][x] == '0')
				image_to_window(game, game->floor, x, y);
			else if (game->map[y][x] == 'P')
				image_to_window(game, game->current_plyer, x, y);
			else if (game->map[y][x] == 'E')
				image_to_window(game, game->exit_img_green, x, y);
			x++;
		}
		y++;
	}
}

int	decide_player(int key_code, t_game *game)
{
	if (key_code == 'w' && game->map[game->pos_y - 1][game->pos_x] != '1')
	{
		game->current_plyer = game->player_img[2];
		game->pos_y--;
		return (1);
	}
	else if (key_code == 's' && game->map[game->pos_y + 1][game->pos_x] != '1')
	{
		game->current_plyer = game->player_img[1];
		game->pos_y++;
		return (1);
	}
	else if (key_code == 'd' && game->map[game->pos_y][game->pos_x + 1] != '1')
	{
		game->current_plyer = game->player_img[4];
		game->pos_x++;
		return (1);
	}
	else if (key_code == 'a' && game->map[game->pos_y][game->pos_x - 1] != '1')
	{
		game->current_plyer = game->player_img[3];
		game->pos_x--;
		return (1);
	}
	return (0);
}

void	mv_player(int key_code, t_game *game)
{
	game->pos_x = game->pos_play_x;
	game->pos_y = game->pos_play_y;
	if (decide_player(key_code, game) == 1)
	{
		game->counter_steps++;
		ft_printf("steps %d\n", game->counter_steps);
	}
	if (game->map[game->pos_y][game->pos_x] == 'C')
		game->counter_coin++;
	handler_of_player_win_lose(game, game->pos_y, game->pos_x);
	if (game->map[game->pos_y][game->pos_x] != '1')
	{
		game->map[game->pos_play_y][game->pos_play_x] = '0';
		game->pos_play_x = game->pos_x;
		game->pos_play_y = game->pos_y;
		game->map[game->pos_play_y][game->pos_play_x] = 'P';
		clear_way(game);
	}
}

void	handler_of_player_win_lose(t_game *game, int y, int x)
{
	if (game->map[y][x] == 'E' && game->total_coin == game->counter_coin)
	{
		ft_victory(1);
		mlx_free(game);
		exit(EXIT_SUCCESS);
	}
}

void	ft_victory(int check)
{
	if (check == 1)
		printf("\n\
    #################################################################\n\
    ##                                                              ##\n\
    ##  ###  ###  ######  ##    ##     ##      ## ## ##    ##   ##  ##\n\
    ##   ##  ##  ##    ## ##    ##     ##      ## ## ###   ##   ##  ##\n\
    ##    ####   #      # ##    ##     ##  ##  ## ## ## ## ##   ##  ##\n\
    ##     ##    ##    ## ##    ##     ## #### ## ## ##  ####       ##\n\
    ##     ##     ######    ####        ###  ###  ## ##   ###   ##  ##\n\
    ##                                                              ##\n\
    ##################################################################\n\n");
}
