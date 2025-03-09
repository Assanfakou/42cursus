/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:28:45 by hfakou            #+#    #+#             */
/*   Updated: 2025/03/09 02:12:06 by hfakou           ###   ########.fr       */
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
void decide_player(int key_code, t_game *game)
{
    if (key_code == 'w' && game->map[game->pos_y - 1][game->pos_x] != '1')
    {
        game->current_plyer = game->player_img[2];
        game->pos_y--;
    }
    if (key_code == 's' && game->map[game->pos_y + 1][game->pos_x] != '1')
    {
        game->current_plyer = game->player_img[1];    
        game->pos_y++;
    }
    if (key_code == 'd' && game->map[game->pos_y][game->pos_x + 1] != '1')
    {
        game->current_plyer = game->player_img[4];
        game->pos_x++;
    }
    if (key_code == 'a' && game->map[game->pos_y][game->pos_x - 1] != '1')
    {
        game->current_plyer = game->player_img[3];
        game->pos_x--;
    }
}
void	mv_player(int key_code, t_game *game)
{

	game->pos_x = game->pos_play_x;
	game->pos_y = game->pos_play_y;
	decide_player(key_code, game);
	if (game->map[game->pos_y][game->pos_x] == 'C')
		game->counter_coin++;
	handler_of_player_win_lose(game, game->pos_y, game->pos_x);
	if (game->map[game->pos_y][game->pos_x] != '1' && game->map[game->pos_y][game->pos_x] != 'E')
	{
		game->map[game->pos_play_y][game->pos_play_x] = '0';
		game->pos_play_x = game->pos_x;
		game->pos_play_y = game->pos_y;
		game->map[game->pos_play_y][game->pos_play_x] = 'P';
		ft_printf("steps : %d\n", game->counter_steps);
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
