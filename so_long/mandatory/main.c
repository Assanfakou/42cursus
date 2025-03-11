/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:25:52 by hfakou            #+#    #+#             */
/*   Updated: 2025/03/11 01:50:27 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == ESC)
	{
		mlx_free(game);
		exit(EXIT_SUCCESS);
	}
	else
		mv_player(keycode, game);
	return (0);
}

void	draw_map(t_game *game)
{
	int (y), (x);
	player_pos(game);
	y = 0;
	while (y < game->hight)
	{
		x = 0;
		while (x < game->with)
		{
			if (game->map[y][x] == '1')
				image_to_window(game, game->wall_img, x, y);
			else if (game->map[y][x] == 'E')
			{
				game->exit_pos_x = x;
				game->exit_pos_y = y;
				image_to_window(game, game->exit_img_green, x, y);
			}
			else if (game->map[y][x] == 'P')
				image_to_window(game, game->current_plyer, x, y);
			else if (game->map[y][x] == 'C')
				image_to_window(game, game->coin_img, x, y);
			x++;
		}
		y++;
	}
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (1);
	fill_map(&game, av[1]);
	game.total_coin = 0;
	game.counter_coin = 0;
	game.counter_steps = 0;
	coins_num(&game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.with * SUB_PEX, game.hight
			* SUB_PEX, "so_long");
	file_to_image(&game);
	game.current_frame = 0;
	game.frame_delay = 4;
	draw_map(&game);
	mlx_key_hook(game.win, handle_keypress, &game);
	mlx_loop(game.mlx);
}
