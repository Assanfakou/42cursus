/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:28:29 by hfakou            #+#    #+#             */
/*   Updated: 2025/02/22 23:05:55 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void player_pos(t_game *game)
{
    int x;
    int y;

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            if (game->ma_p[y][x] == 'P')
            {
                game->pos_play_x = x;
                game->pos_play_y = y;
            }
            x++;
        }
        y++;
    }
}

int mv_player(int key_code, t_game *game)
{
    int pos_x = game->pos_play_x;
    int pos_y = game->pos_play_y;

    if (key_code == UP || key_code == 'w')
        pos_y--;
    if (key_code == DOWN || key_code == 's')
        pos_y++;
    if (key_code == RIGHT || key_code == 'd')
        pos_x++;
    if (key_code == LEFT || key_code == 'a')
        pos_x--;
        // printf("x = %d, y = %d\n", game->pos_play_x, game->pos_play_y);
        if (game->ma_p[pos_y][pos_x] != '1')
        {
            game->ma_p[game->pos_play_y][game->pos_play_x] = '0';
            game->pos_play_x = pos_x;
            game->pos_play_y = pos_y;
            game->ma_p[game->pos_play_y][game->pos_play_x] = 'P';
            mlx_clear_window(game->mlx, game->win);
            draw_map(game);
        }
    return (0);
}