/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 21:49:58 by hfakou            #+#    #+#             */
/*   Updated: 2025/03/10 20:30:14 by hfakou           ###   ########.fr       */
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

void	mlx_free(t_game *game)
{
	mlx_destroy_image(game->mlx, game->wall_img);
	mlx_destroy_image(game->mlx, game->player_img[0]);
	mlx_destroy_image(game->mlx, game->player_img[1]);
	mlx_destroy_image(game->mlx, game->player_img[2]);
	mlx_destroy_image(game->mlx, game->player_img[3]);
	mlx_destroy_image(game->mlx, game->player_img[4]);
	mlx_destroy_image(game->mlx, game->coin_img);
	mlx_destroy_image(game->mlx, game->exit_img_green);
	mlx_destroy_image(game->mlx, game->floor);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_map(game, game->map);
}

void	file_to_image(t_game *game)
{
	game->wall_img = mlx_xpm_file_to_image(game->mlx,
			"textures/pngs/123.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
	game->player_img[0] = mlx_xpm_file_to_image(game->mlx,
			"textures/peter/straight.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
	game->player_img[1] = mlx_xpm_file_to_image(game->mlx,
			"textures/peter/front.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
	game->player_img[2] = mlx_xpm_file_to_image(game->mlx,
			"textures/peter/back.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
	game->player_img[3] = mlx_xpm_file_to_image(game->mlx,
			"textures/peter/left.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
	game->player_img[4] = mlx_xpm_file_to_image(game->mlx,
			"textures/peter/right.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
	game->coin_img = mlx_xpm_file_to_image(game->mlx,
			"textures/coin_pngs/coin1.xpm", &(int){SUB_PEX},
			&(int){SUB_PEX});
	game->current_plyer = game->player_img[0];
	game->exit_img_green = mlx_xpm_file_to_image(game->mlx,
			"textures/gate/green_ex/1.xpm", &(int){SUB_PEX},
			&(int){SUB_PEX});
	game->floor = mlx_xpm_file_to_image(game->mlx, "textures/pngs/floor.xpm",
			&(int){SUB_PEX}, &(int){SUB_PEX});
}

void	image_to_window(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, image, x * SUB_PEX, y
		* SUB_PEX);
}
