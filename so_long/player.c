/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:28:45 by hfakou            #+#    #+#             */
/*   Updated: 2025/02/24 13:43:37 by hfakou           ###   ########.fr       */
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

void mv_player(int key_code, t_game *game)
{
    int pos_x = game->pos_play_x;
    int pos_y = game->pos_play_y;

    if (key_code == UP || key_code == 'w' && game->ma_p[pos_y - 1][pos_x] != '1')
    {
        game->current_plyer = game->player_img[2];
        pos_y--;
    }
    if (key_code == DOWN || key_code == 's' && game->ma_p[pos_y + 1][pos_x] != '1')
    {
        game->current_plyer = game->player_img[1];    
        pos_y++;
    }
    if (key_code == RIGHT || key_code == 'd' && game->ma_p[pos_y][pos_x + 1] != '1')
    {
        game->current_plyer = game->player_img[4];
        pos_x++;
    }
    if (key_code == LEFT || key_code == 'a' && game->ma_p[pos_y + 1][pos_x - 1] != '1')
    {
        game->current_plyer = game->player_img[3];
        pos_x--;
    }
    if (game->ma_p[pos_y][pos_x] == 'C')
    {
        game->counter_coin++;
        printf("coins collected %d\n", game->counter_coin);
    }
    // if (game->counter_coin == game->total_coin)
    // {
    //     mlx_destroy_window(game->mlx, game->win);
    //     exit(1);
    // }
        // printf("x = %d, y = %d\n", game->pos_x, game->pos_play_y);
    // if (game
    if (game->ma_p[pos_y][pos_x] != '1' && game->ma_p[pos_y][pos_x] != 'E')
    {
        game->ma_p[game->pos_play_y][game->pos_play_x] = '0';
        game->pos_play_x = pos_x;
        game->pos_play_y = pos_y;
        game->ma_p[game->pos_play_y][game->pos_play_x] = 'P';
        mlx_clear_window(game->mlx, game->win);
        draw_map(game);
    }
}
