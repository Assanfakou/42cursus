/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 21:50:34 by hfakou            #+#    #+#             */
/*   Updated: 2025/03/11 01:57:35 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	coins_num(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->hight)
	{
		x = 0;
		while (x < game->with)
		{
			if (game->map[y][x] == 'E')
			{
				game->exit_pos_x = x;
				game->exit_pos_y = y;
			}
			if (game->map[y][x] == 'C')
				game->total_coin++;
			x++;
		}
		y++;
	}
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == ESC)
	{
		mlx_free(game);
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		exit(EXIT_SUCCESS);
	}
	else
		mv_player(keycode, game);
	return (0);
}

void	mlx_free(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		mlx_destroy_image(game->mlx, game->exit_img_green[i]);
		mlx_destroy_image(game->mlx, game->exit_img_red[i]);
		mlx_destroy_image(game->mlx, game->player_img[i]);
		mlx_destroy_image(game->mlx, game->fire[i]);
		i++;
	}
	mlx_destroy_image(game->mlx, game->player_img[4]);
	mlx_destroy_image(game->mlx, game->fire[4]);
	i = 0;
	while (i < 10)
		mlx_destroy_image(game->mlx, game->counter_num[i++]);
	mlx_destroy_image(game->mlx, game->wall_img);
	mlx_destroy_image(game->mlx, game->counter_bar);
	mlx_destroy_image(game->mlx, game->floor);
	mlx_destroy_image(game->mlx, game->coin_img[0]);
	mlx_destroy_image(game->mlx, game->coin_img[1]);
	free_map(game, game->map);
}

void	handler_of_plyer_win_lose(t_game *game, int y, int x)
{
	if (game->map[y][x] == 'X')
	{
		ft_victory(0);
		mlx_free(game);
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		exit(EXIT_SUCCESS);
	}
	if (game->map[y][x] == 'E' && game->total_coin == game->counter_coin)
	{
		ft_victory(1);
		mlx_free(game);
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		exit(EXIT_SUCCESS);
	}
}

void	ft_victory(int check)
{
	if (check == 1)
		ft_printf("\n\
    #################################################################\n\
    ##                                                              ##\n\
    ##  ###  ###  ######  ##    ##     ##      ## ## ##    ##   ##  ##\n\
    ##   ##  ##  ##    ## ##    ##     ##      ## ## ###   ##   ##  ##\n\
    ##    ####   #      # ##    ##     ##  ##  ## ## ## ## ##   ##  ##\n\
    ##     ##    ##    ## ##    ##     ## #### ## ## ##  ####       ##\n\
    ##     ##     ######    ####        ###  ###  ## ##   ###   ##  ##\n\
    ##                                                              ##\n\
    ##################################################################\n\n");
	else
		ft_printf("\n\
#########################################################################\n\
##                                                                     ##\n\
##   ###    ###  #######  ##     ## ##       #######   ######  ####### ##\n\
##    ###  ###  ##     ## ##     ## ##      ##     ## ##    ## ##      ##\n\
##     ######   ##     ## ##     ## ##      ##     ## ##       ##      ##\n\
##      ####    ##     ## ##     ## ##      ##     ##  ######  ######  ##\n\
##      ####    ##     ## ##     ## ##      ##     ##       ## ##      ##\n\
##      ####    ##     ## ##     ## ##      ##     ## ##    ## ##      ##\n\
##      ####     #######   #######  ######## #######   ######  ####### ##\n\
##                                                                     ##\n\
#########################################################################\n");
}
