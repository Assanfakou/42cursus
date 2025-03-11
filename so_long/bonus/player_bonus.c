/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:28:45 by hfakou            #+#    #+#             */
/*   Updated: 2025/03/11 01:41:41 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_pos(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->hight)
	{
		x = 0;
		while (x < game->with)
		{
			if (game->map[y][x] == 'P')
			{
				game->pos_play_x = x;
				game->pos_play_y = y;
			}
			x++;
		}
		y++;
	}
}

void	rander_steps_counter(t_game *game, int steps)
{
	mlx_put_image_to_window(game->mlx, game->win, game->counter_num[(steps
			/ 1000) % 10], 124, 7);
	mlx_put_image_to_window(game->mlx, game->win, game->counter_num[(steps
			/ 100) % 10], 167, 7);
	mlx_put_image_to_window(game->mlx, game->win, game->counter_num[(steps / 10)
		% 10], 209, 7);
	mlx_put_image_to_window(game->mlx, game->win, game->counter_num[steps % 10],
		252, 8);
}

void	psaudo_clear(t_game *game)
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
			else if (game->map[y][x] == 'E')
				image_to_window(game, game->current_exit_img, x, y);
			x++;
		}
		y++;
	}
}

void	decide_player(int key_code, t_game *game)
{
	if (key_code == 'w' && game->map[game->pos_y - 1][game->pos_x] != '1')
	{
		game->current_plyer = game->player_img[2];
		game->pos_y--;
		game->key_count++;
	}
	else if (key_code == 's' && game->map[game->pos_y + 1][game->pos_x] != '1')
	{
		game->current_plyer = game->player_img[1];
		game->pos_y++;
		game->key_count++;
	}
	else if (key_code == 'd' && game->map[game->pos_y][game->pos_x + 1] != '1')
	{
		game->current_plyer = game->player_img[4];
		game->pos_x++;
		game->key_count++;
	}
	else if (key_code == 'a' && game->map[game->pos_y][game->pos_x - 1] != '1')
	{
		game->current_plyer = game->player_img[3];
		game->pos_x--;
		game->key_count++;
	}
}

void	mv_player(int key_code, t_game *game)
{
	game->pos_x = game->pos_play_x;
	game->pos_y = game->pos_play_y;
	decide_player(key_code, game);
	if (game->map[game->pos_y][game->pos_x] == 'C')
		game->counter_coin++;
	handler_of_plyer_win_lose(game, game->pos_y, game->pos_x);
	if (game->map[game->pos_y][game->pos_x] != '1'
		&& game->map[game->pos_y][game->pos_x] != 'X')
	{
		game->map[game->pos_play_y][game->pos_play_x] = '0';
		game->pos_play_x = game->pos_x;
		game->pos_play_y = game->pos_y;
		game->map[game->pos_play_y][game->pos_play_x] = 'P';
		rander_steps_counter(game, game->key_count);
		draw_map(game);
		psaudo_clear(game);
	}
}
