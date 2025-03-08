/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:28:45 by hfakou            #+#    #+#             */
/*   Updated: 2025/03/08 17:27:24 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clear_way(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->hight)
	{
		x = 0;
		while (x < game->with)
		{
			if (game->map[y][x] == '0')
				image_to_window(game, game->floor, x, y);
			x++;
		}
		y++;
	}
}

void	mv_player(int key_code, t_game *game)
{
	int	pos_x;
	int	pos_y;

	pos_x = game->pos_play_x;
	pos_y = game->pos_play_y;
	if (key_code == 'w' && game->map[pos_y - 1][pos_x] != '1')
	{
        game->current_plyer = game->player_img[2];
		pos_y--;
        game->counter_steps++;
    }
	if (key_code == 's' && game->map[pos_y + 1][pos_x] != '1')
	{
		game->current_plyer = game->player_img[1];
		pos_y++;
		game->counter_steps++;
	}
	if (key_code == 'd' && game->map[pos_y][pos_x + 1] != '1')
	{
		game->current_plyer = game->player_img[4];
		pos_x++;
		game->counter_steps++;
	}
	if (key_code == 'a' && game->map[pos_y][pos_x - 1] != '1')
	{
		game->current_plyer = game->player_img[3];
		pos_x--;
		game->counter_steps++;
	}
	if (game->map[pos_y][pos_x] == 'C')
		game->counter_coin++;
	handler_of_player_win_lose(game, pos_y, pos_x);
	if (game->map[pos_y][pos_x] != '1' && game->map[pos_y][pos_x] != 'E')
	{
		game->map[game->pos_play_y][game->pos_play_x] = '0';
		game->pos_play_x = pos_x;
		game->pos_play_y = pos_y;
		game->map[game->pos_play_y][game->pos_play_x] = 'P';
		printf("steps : %d\n", game->counter_steps);
		draw_map(game);
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
		printf(GREEN "\n\
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
