/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:25:52 by hfakou            #+#    #+#             */
/*   Updated: 2025/03/14 00:07:55 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
				image_to_window(game, game->current_exit_img, x, y);
			else if (game->map[y][x] == 'P')
				image_to_window(game, game->current_plyer, x, y);
			else if (game->map[y][x] == 'C')
				image_to_window(game, game->current_anim, x, y);
			else if (game->map[y][x] == 'X')
				image_to_window(game, game->curent_fire, x, y);
			render_fire(game);
			render_the_animation(game);
			x++;
		}
		y++;
	}
}

int	distroy_cross(t_game *game)
{
	mlx_free(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	t_game (game);
	if (ac != 2)
		return (1);
	fill_map(&game, av[1]);
	game.total_coin = 0;
	game.counter_coin = 0;
	game.key_count = 0;
	coins_num(&game);
	game.mlx = mlx_init();
	if (game.with <= 6)
		game.win = mlx_new_window(game.mlx, game.with * SUB_PEX + 170,
				game.hight * SUB_PEX + 60, "so_long");
	else
		game.win = mlx_new_window(game.mlx, game.with * SUB_PEX, game.hight
				* SUB_PEX + 60, "so_long");
	file_to_image(&game);
	game.current_frame = 0;
	game.frame_delay = 6;
	draw_map(&game);
	mlx_put_image_to_window(game.mlx, game.win, game.counter_bar, 0 * SUB_PEX, 0
		* SUB_PEX);
	mlx_loop_hook(game.mlx, loop_rendering, &game);
	mlx_key_hook(game.win, handle_keypress, &game);
	mlx_hook(game.win, 17, 0, distroy_cross, &game);
	mlx_loop(game.mlx);
}
