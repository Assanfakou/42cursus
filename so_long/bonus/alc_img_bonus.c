/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alc_img_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 01:38:56 by hfakou            #+#    #+#             */
/*   Updated: 2025/03/13 05:41:19 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	file_to_image(t_game *game)
{
	game->wall_img = mlx_xpm_file_to_image(game->mlx, "textures/pngs/123.xpm",
			&(int){SUB_PEX}, &(int){SUB_PEX});
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
	game->coin_img[0] = mlx_xpm_file_to_image(game->mlx,
			"textures/coin_pngs/coin1.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
	game->coin_img[1] = mlx_xpm_file_to_image(game->mlx,
			"textures/coin_pngs/coin2.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
	game->current_plyer = game->player_img[0];
	game->floor = mlx_xpm_file_to_image(game->mlx, "textures/pngs/floor.xpm",
			&(int){SUB_PEX}, &(int){SUB_PEX});
	alloc_enimy(game);
	alloc_gate(game);
	counter_bar_fto_img(game);
}

void	alloc_enimy(t_game *game)
{
	game->fire[0] = mlx_xpm_file_to_image(game->mlx, "textures/enimy/1.xpm",
			&(int){SUB_PEX}, &(int){SUB_PEX});
	game->fire[1] = mlx_xpm_file_to_image(game->mlx, "textures/enimy/2.xpm",
			&(int){SUB_PEX}, &(int){SUB_PEX});
	game->fire[2] = mlx_xpm_file_to_image(game->mlx, "textures/enimy/3.xpm",
			&(int){SUB_PEX}, &(int){SUB_PEX});
	game->fire[3] = mlx_xpm_file_to_image(game->mlx, "textures/enimy/4.xpm",
			&(int){SUB_PEX}, &(int){SUB_PEX});
	game->fire[4] = mlx_xpm_file_to_image(game->mlx, "textures/enimy/5.xpm",
			&(int){SUB_PEX}, &(int){SUB_PEX});
}

void	alloc_gate(t_game *game)
{
	game->exit_img_green[0] = mlx_xpm_file_to_image(game->mlx,
			"textures/gate/green_ex/1.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
	game->exit_img_green[1] = mlx_xpm_file_to_image(game->mlx,
			"textures/gate/green_ex/2.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
	game->exit_img_green[2] = mlx_xpm_file_to_image(game->mlx,
			"textures/gate/green_ex/3.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
	game->exit_img_green[3] = mlx_xpm_file_to_image(game->mlx,
			"textures/gate/green_ex/4.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
	game->exit_img_red[0] = mlx_xpm_file_to_image(game->mlx,
			"textures/gate/red_ex/1.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
	game->exit_img_red[1] = mlx_xpm_file_to_image(game->mlx,
			"textures/gate/red_ex/2.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
	game->exit_img_red[2] = mlx_xpm_file_to_image(game->mlx,
			"textures/gate/red_ex/3.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
	game->exit_img_red[3] = mlx_xpm_file_to_image(game->mlx,
			"textures/gate/red_ex/4.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
}

void	counter_bar_fto_img(t_game *game)
{
	game->counter_bar = mlx_xpm_file_to_image(game->mlx,
			"textures/counter/str1.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
	game->counter_num[0] = mlx_xpm_file_to_image(game->mlx,
			"textures/counter/1.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
	game->counter_num[1] = mlx_xpm_file_to_image(game->mlx,
			"textures/counter/2.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
	game->counter_num[2] = mlx_xpm_file_to_image(game->mlx,
			"textures/counter/3.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
	game->counter_num[3] = mlx_xpm_file_to_image(game->mlx,
			"textures/counter/4.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
	game->counter_num[4] = mlx_xpm_file_to_image(game->mlx,
			"textures/counter/5.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
	game->counter_num[5] = mlx_xpm_file_to_image(game->mlx,
			"textures/counter/6.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
	game->counter_num[6] = mlx_xpm_file_to_image(game->mlx,
			"textures/counter/7.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
	game->counter_num[7] = mlx_xpm_file_to_image(game->mlx,
			"textures/counter/8.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
	game->counter_num[8] = mlx_xpm_file_to_image(game->mlx,
			"textures/counter/9.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
	game->counter_num[9] = mlx_xpm_file_to_image(game->mlx,
			"textures/counter/10.xpm", &(int){SUB_PEX}, &(int){SUB_PEX});
}

void	image_to_window(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, image, x * SUB_PEX, y
		* SUB_PEX + 60);
}
